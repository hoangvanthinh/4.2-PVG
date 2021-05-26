/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    telnet.c

  Summary:
    Module for Microchip TCP/IP Stack
     -TelnetサービスのTCPポートは23番で提供する
     -Reference: RFC 854

  Description:
    TELNET サーバー

 *******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) <2014> released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*
* ============================================================================ *
* VERSION DATE       BY                   CHANGE/COMMENT                       *
* ---------------------------------------------------------------------------- *
*   1.00  2017-05-08 きむ茶工房(きむしげ) デモボード用だったので書換えた。     *
*   1.10  2017-05-30 きむ茶工房(きむしげ) 18F2xK22/24EP256MC202での動作確認。  *
*
 *******************************************************************************/
//DOM-IGNORE-END

#define __TELNET_C_

#include "../../tcpip/tcpip.h"

#if defined(STACK_USE_TELNET_SERVER)

// "tcpip_config.h"でオーバーライドされない場合は、構成パラメータのデフォルトを設定します。
#if !defined(TELNET_PORT)
// Unsecured Telnet port
#define TELNET_PORT  23
#endif
#if !defined(TELNETS_PORT)
// SSLセキュアTelnetポート（STACK_USE_SSL_SERVERが未定義の場合は無視されます）
#define TELNETS_PORT  992
#endif

#if !defined(MAX_TELNET_CONNECTIONS)
// Telnet接続の最大数
#define MAX_TELNET_CONNECTIONS  (3u)
#endif
#if !defined(TELNET_USERNAME)

// Default Telnet user name
#define TELNET_USERNAME  "admin"
#endif
#if !defined(TELNET_PASSWORD)
// Default Telnet password
#define TELNET_PASSWORD  "microchip"
#endif

// Demo title string
static ROM uint8_t strTitle[] = "\x1b[2J\x1b[31m\x1b[1m"    // 2J=画面消去, 31m=赤文字, 1m=太文字
        "\x1b[1;1fMicrochip Telnet Server 1.1\x1b[0m\r\n"   // 0m=文字属性をリセット
        "(for this demo, type 'admin' for the login and 'microchip' for the password.)\r\n"
        "Login: ";
// Demo password
// DO Suppress Local Echo (stop telnet client from printing typed characters)
// "\xff\xfd\x2d"はローカルエコーを停止させる為のロケールコードの様だが上手く動作していなさそう
static ROM uint8_t strPassword[] = "Password: \xff\xfd\x2d";
// Access denied message
static ROM uint8_t strAccessDenied[] = "Access denied\r\n";
// Successful authentication message
static ROM uint8_t strAuthenticated[] = "Logged in successfully !!\r\n";
// input a command message
static ROM uint8_t strCommand[] = "\r\nPress 'q' to quit "
        "Or input a command(STATE/LED ON/LED OFF)\r\n" ;
// Button status message
static ROM uint8_t strButton[2][16] = {"Button: ON   \r\n",
                                       "Button: OFF  \r\n" } ;
// Command accepted message
static ROM uint8_t strAccepte[] = "I accepted !\r\n" ;
// Invalid command message
static ROM uint8_t strNoCommand[] = "Invalid command !!\r\n" ;
// Demo disconnection message
static ROM uint8_t strGoodBye[] = "\r\nGoodbye!\r\n";

extern APP_CONFIG AppConfig;

/*******************************************************************************
*  ans = adconv() アナログ値の入力処理を行う                                   *
*    ans : 読み込んだアナログ値を返す(０～１０２３の範囲)                      *
*******************************************************************************/
unsigned int adconv()
{
     unsigned int temp;

#if defined (__XC8)
     GO_nDONE = 1 ;                     // PICにアナログ値読取り開始を指示
     while(GO_nDONE) ;                  // PICが読取り完了するまで待つ
     temp = ADRESH ;                    // PICは読取った値をADRESHとADRESLのレジスターにセットする
     temp = ( temp << 8 ) | ADRESL ;    // 10ビットの分解能力です
#elif defined(__dsPIC33E__)|| defined(__PIC24E__)
     AD1CON1bits.SAMP = 1;              // サンプリングの開始
     Delay10us(1) ;                     // サンプリングの終了まで待つ
     AD1CON1bits.SAMP = 0 ;             // 変換の開始
     while (!AD1CON1bits.DONE) ;        // 変換の終了まで待つ
     temp = ADC1BUF0 ;                  // アナログ値(AN0)を読み出す
#else
     #error telenet.c : The MCU does not support AD conversion.
#endif
     return temp ;
}
/*********************************************************************
 * Function:        void TelnetTask(void)
 *
 * PreCondition:    Stack is initialized()
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Telnetサーバー関連のタスクを実行します。
 *                  Telnetステートマシンと状態トラッキング変数が含まれます。
 *
 * Note:            None
 ********************************************************************/
void TelnetTask(void)
{
    uint8_t i;
    uint8_t vTelnetSession;
    uint16_t w, w2;
    TCP_SOCKET MySocket;
    static TICK t ;
    char   buff[20] ;

    enum {
        SM_HOME = 0,
        SM_PRINT_LOGIN,
        SM_GET_LOGIN,
        SM_GET_PASSWORD,
        SM_GET_PASSWORD_BAD_LOGIN,
        SM_PRINT_COMMAND,
        SM_GET_COMMAND,
        SM_DISCONNECT
    } TelnetState ;

    static TCP_SOCKET hTelnetSockets[MAX_TELNET_CONNECTIONS];
    static uint8_t vTelnetStates[MAX_TELNET_CONNECTIONS];
    static bool bInitialized = false;

    // 電源投入時に1回の初期化を実行する
#if defined(WF_CS_TRIS)
    if ((!bInitialized) || (AppConfig.hibernateFlag)) {
#else
    if (!bInitialized) {
#endif
        for (vTelnetSession = 0; vTelnetSession < MAX_TELNET_CONNECTIONS; vTelnetSession++) {
            hTelnetSockets[vTelnetSession] = INVALID_SOCKET;
            vTelnetStates[vTelnetSession] = SM_HOME;
        }
        bInitialized = true;
    }

    // 各telnetセッションと処理ステートの変更とTX/RXデータをループする
    for (vTelnetSession = 0; vTelnetSession < MAX_TELNET_CONNECTIONS; vTelnetSession++) {
        // このセッションの処理ステート情報をロードする
        MySocket    = hTelnetSockets[vTelnetSession];
        TelnetState = vTelnetStates[vTelnetSession];

        // リモートクライアントが切断した場合は、状態をリセットして下さい。
        if (MySocket != INVALID_SOCKET) {
            if (TCPWasReset(MySocket))
                TelnetState = SM_PRINT_LOGIN;
        }

        // セッション状態を処理する
        switch (TelnetState) {
           /*** ソケットをリモートTCPサーバーに接続する処理 ***/
           case SM_HOME :
               MySocket = TCPOpen(0, TCP_OPEN_SERVER, TELNET_PORT, TCP_PURPOSE_TELNET);

               // TCPソケットがない場合、操作を中止します。
               // type TCP_PURPOSE_TELNET is available If this ever happens, you need to go add one to tcpip_config.h
               if (MySocket == INVALID_SOCKET)  break ;

               // SSLサーバーのサポートが有効な場合は、SSLリスナーを開きます。
#if defined(STACK_USE_SSL_SERVER)
               TCPAddSSLListener(MySocket, TELNETS_PORT);
#endif
               // 処理ステートを次(SM_PRINT_LOGIN)に進める
               TelnetState++;
               break;

           /*** タイトルの文字列データを送信する処理 ***/
           case SM_PRINT_LOGIN:
#if defined(STACK_USE_SSL_SERVER)
               // TELNET_REJECT_UNSECUREDが定義されている場合、安全でない接続を拒否する
   #if defined(TELNET_REJECT_UNSECURED)
               if (!TCPIsSSL(MySocket)) {
                   if (TCPIsConnected(MySocket)) {
                       TCPDisconnect(MySocket);
                       TCPDisconnect(MySocket);
                       break;
                   }
               }
   #endif
               // まだハンドシェイクしている場合、何も送信しないで下さい。
               if (TCPSSLIsHandshaking(MySocket)) break ;
#endif

               // タイトルの文字列をソケットに書き込む事が出来るかどうかを確認する
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strTitle)) break ;
               // タイトル文字列データを送信バッファに入れます。
               TCPPutROMString(MySocket, strTitle);
               // パケットを送信する
               TCPFlush(MySocket);
               // 処理ステートを次(SM_GET_LOGIN)に進める
               TelnetState++;

           /*** 入力されたログイン名を調べる処理 ***/
           case SM_GET_LOGIN:
               // パスワード要求の文字列をソケットに書き込む事が出来るかどうかを確認する
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strPassword)) break ;
               // ユーザーがリターン('LF')を押したかどうかを確認する
               w = TCPFind(MySocket, '\n', 0, false);  // 'CR+LF'の'LF'で判断している
               if (w == 0xFFFFu) {
                   // 検索できなかった
                   if (TCPGetRxFIFOFree(MySocket) == 0u) {
                       // 受信バッファが満杯状態なら、タイトル表示の所まで戻る
                       TelnetState = SM_PRINT_LOGIN;
                       TCPGetArray(MySocket, NULL, w + 1);
                   }
                   break;
               }

               // ログイン名を検索する - 大文字と小文字を区別しない
               w2 = TCPFindROMArray(MySocket, (ROM uint8_t *) TELNET_USERNAME, sizeof (TELNET_USERNAME) - 1, 0, true);
               if (!((sizeof (TELNET_USERNAME) - 1 == w - w2) || (sizeof (TELNET_USERNAME) == w - w2))) {
                   // ユーザー名が見つかりませんでした。
                   // しかし、ユーザー名の正当性が漏れないようにしてみましょう
                   TelnetState = SM_GET_PASSWORD_BAD_LOGIN;
               } else {
                   TelnetState = SM_GET_PASSWORD;
               }
               // ログイン名が確認されたので、FIFOバッファを空にします
               TCPGetArray(MySocket, NULL, w + 1);

               // パスワード要求の文字列を送信する
               TCPPutROMString(MySocket, strPassword);
               TCPFlush(MySocket);
               break;

           /*** 入力されたパスワードを調べる処理 ***/
           case SM_GET_PASSWORD:
           case SM_GET_PASSWORD_BAD_LOGIN:
               // アクセス認証の文字列をソケットに書き込む事が出来るかどうかを確認する
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strAuthenticated)) break ;
               // ユーザーがリターンを押したかどうかを確認する
               w = TCPFind(MySocket, '\n', 0, false);
               if (w == 0xFFFFu) {
                   if (TCPGetRxFIFOFree(MySocket) == 0u) {
                        // 受信バッファが満杯状態なら、タイトル表示の所まで戻る
                        TelnetState = SM_PRINT_LOGIN;
                        TCPGetArray(MySocket, NULL, w + 1);
                   }
                   break;
               }

               // パスワードを検索する - 大文字と小文字を区別する
               w2 = TCPFindROMArray(MySocket, (ROM uint8_t *) TELNET_PASSWORD, sizeof (TELNET_PASSWORD) - 1, 0, false);
               if ((w2 == 0xFFFF) || (TelnetState == SM_GET_PASSWORD_BAD_LOGIN)) {
                   // パスワードが見つかりませんでした、又はログイン名が異なる
                   // タイトル表示の所まで戻る
                   TCPGetArray(MySocket, NULL, w + 1);
                   TelnetState = SM_PRINT_LOGIN;
                   break;
               }
               // パスワードが確認されたので、FIFOバッファを空にします
               TCPGetArray(MySocket, NULL, w + 1);

               // アクセス認証の文字列を送信する
               TCPPutROMString(MySocket, strAuthenticated);
               TCPFlush(MySocket);
               TelnetState = SM_PRINT_COMMAND;
               // No break

           /*** コマンド要求の文字列を表示する処理 ***/
           case SM_PRINT_COMMAND:
               // コマンド要求の文字列をソケットに書き込む事が出来るかどうかを確認する
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strCommand)) break ;
               //  コマンド要求文字列のデータを送信する
               TCPPutROMString(MySocket, strCommand);
               TCPFlush(MySocket);
               // 処理ステートを次(SM_GET_COMMAND)に進める
               TelnetState++;

           /*** 入力されたコマンドに応じた処理 ***/
           case SM_GET_COMMAND:
               // 情報表示の文字列をソケットに書き込む事が出来るかどうかを確認する
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strButton)) break ;
               // ユーザーがリターン('LF')を押したかどうかを確認する
               w = TCPFind(MySocket, '\n', 0, false);  // 'CR+LF'の'LF'で判断している
               if (w == 0xFFFFu) {
                   // 検索できなかった
                   if (TCPGetRxFIFOFree(MySocket) == 0u) {
                       // 受信バッファが満杯状態なら、タイトル表示の所まで戻る
                       TelnetState = SM_PRINT_COMMAND;
                       TCPGetArray(MySocket, NULL, w + 1);
                   }
                   break;
               }

               // 受信バッファから読み取れるデータ数を得る
               if (TCPIsGetReady(MySocket)) {
                   // "STATE"文字の検索
                   w2 = TCPFindROMArray(MySocket,(ROM uint8_t *)"STATE", 5, 0, false);
                   if (w2 != 0xFFFFu) {
                       // AN1(可変抵抗)の値を読み取る
                       sprintf(buff,"\r\nAnalog: %04d\r\n",adconv()) ;
                       TCPPutROMString(MySocket, (ROM uint8_t *)buff);
                       // スイッチの状態を得る
                       if (BUTTON0_IO == 0) TCPPutROMString(MySocket, (ROM uint8_t *)&strButton[0]);
                       else                 TCPPutROMString(MySocket, (ROM uint8_t *)&strButton[1]);
                       // リモートTCPサーバーに送る
                       TCPFlush(MySocket);
                       TelnetState = SM_PRINT_COMMAND;
                       TCPGetArray(MySocket, NULL, w + 1);
                       break ;
                   }
                   // "LED"文字の検索
                   w2 = TCPFindROMArray(MySocket,(ROM uint8_t *)"LED", 3, 0, false);
                   if (w2 != 0xFFFFu) {
                       w2 = TCPFindROMArray(MySocket,(ROM uint8_t *)"ON", 2, 0, false);
                       if (w2 != 0xFFFFu) {
                            // 要求を受け付けましたのメッセージを送信する
                            TCPPutROMString(MySocket, (ROM uint8_t *)strAccepte);
                            TCPFlush(MySocket);
                            TelnetState = SM_PRINT_COMMAND;
                            TCPGetArray(MySocket, NULL, w + 1);
                            LED0_IO = 1 ;    // LEDを点灯
                            break ;
                       }
                       w2 = TCPFindROMArray(MySocket,(ROM uint8_t *)"OFF", 3, 0, false);
                       if (w2 != 0xFFFFu) {
                            // 要求を受け付けましたのメッセージを送信する
                            TCPPutROMString(MySocket, (ROM uint8_t *)strAccepte);
                            TCPFlush(MySocket);
                            TelnetState = SM_PRINT_COMMAND;
                            TCPGetArray(MySocket, NULL, w + 1);
                            LED0_IO = 0 ;    // LEDを消灯
                            break ;
                       }
                   }

                   // １バイト読み込む
                   TCPGet(MySocket, &i);
                   switch (i) {
                   case 'q':
                   case 'Q':
                       if (TCPIsPutReady(MySocket) >= strlenpgm((ROM char *)strGoodBye)+4) {
                            // 終了メッセージを送り、1秒後の切断待ち
                            TCPGetArray(MySocket, NULL, w + 1);
                            TCPPutROMString(MySocket, (ROM uint8_t *) "\x1b[1m");
                            TCPPutROMString(MySocket, strGoodBye);
                            TCPFlush(MySocket);
                            t = TickGet() ;
                            TelnetState = SM_DISCONNECT;
                            break;
                       }
                   default:
                       TCPGetArray(MySocket, NULL, w + 1);
                       // 入力されたコマンドは無いよメッセージを送る
                       TCPPutROMString(MySocket, strNoCommand) ;
                       TCPFlush(MySocket);
                       break ;
                   }
               }
               break;

           /*** 1秒後に切断する ***/
           case SM_DISCONNECT:
               if(TickGet() - t >= TICK_SECOND) {
                   // 接続を切りタイトル表示に戻る
                   TCPDisconnect(MySocket);
                   TelnetState = SM_PRINT_LOGIN;
               }
               break ;
        }

        // 現在のセッション状態のステートを記録する
        hTelnetSockets[vTelnetSession] = MySocket;
        vTelnetStates[vTelnetSession]  = TelnetState;
    }
}

#endif // defined(STACK_USE_TELNET_SERVER)
