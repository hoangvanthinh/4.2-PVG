/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    telnet.c

  Summary:
    Module for Microchip TCP/IP Stack
     -Telnet�T�[�r�X��TCP�|�[�g��23�ԂŒ񋟂���
     -Reference: RFC 854

  Description:
    TELNET �T�[�o�[

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
*   1.00  2017-05-08 ���ޒ��H�[(���ނ���) �f���{�[�h�p�������̂ŏ��������B     *
*   1.10  2017-05-30 ���ޒ��H�[(���ނ���) 18F2xK22/24EP256MC202�ł̓���m�F�B  *
*
 *******************************************************************************/
//DOM-IGNORE-END

#define __TELNET_C_

#include "../../tcpip/tcpip.h"

#if defined(STACK_USE_TELNET_SERVER)

// "tcpip_config.h"�ŃI�[�o�[���C�h����Ȃ��ꍇ�́A�\���p�����[�^�̃f�t�H���g��ݒ肵�܂��B
#if !defined(TELNET_PORT)
// Unsecured Telnet port
#define TELNET_PORT  23
#endif
#if !defined(TELNETS_PORT)
// SSL�Z�L���ATelnet�|�[�g�iSTACK_USE_SSL_SERVER������`�̏ꍇ�͖�������܂��j
#define TELNETS_PORT  992
#endif

#if !defined(MAX_TELNET_CONNECTIONS)
// Telnet�ڑ��̍ő吔
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
static ROM uint8_t strTitle[] = "\x1b[2J\x1b[31m\x1b[1m"    // 2J=��ʏ���, 31m=�ԕ���, 1m=������
        "\x1b[1;1fMicrochip Telnet Server 1.1\x1b[0m\r\n"   // 0m=�������������Z�b�g
        "(for this demo, type 'admin' for the login and 'microchip' for the password.)\r\n"
        "Login: ";
// Demo password
// DO Suppress Local Echo (stop telnet client from printing typed characters)
// "\xff\xfd\x2d"�̓��[�J���G�R�[���~������ׂ̃��P�[���R�[�h�̗l������肭���삵�Ă��Ȃ�����
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
*  ans = adconv() �A�i���O�l�̓��͏������s��                                   *
*    ans : �ǂݍ��񂾃A�i���O�l��Ԃ�(�O�`�P�O�Q�R�͈̔�)                      *
*******************************************************************************/
unsigned int adconv()
{
     unsigned int temp;

#if defined (__XC8)
     GO_nDONE = 1 ;                     // PIC�ɃA�i���O�l�ǎ��J�n���w��
     while(GO_nDONE) ;                  // PIC���ǎ�芮������܂ő҂�
     temp = ADRESH ;                    // PIC�͓ǎ�����l��ADRESH��ADRESL�̃��W�X�^�[�ɃZ�b�g����
     temp = ( temp << 8 ) | ADRESL ;    // 10�r�b�g�̕���\�͂ł�
#elif defined(__dsPIC33E__)|| defined(__PIC24E__)
     AD1CON1bits.SAMP = 1;              // �T���v�����O�̊J�n
     Delay10us(1) ;                     // �T���v�����O�̏I���܂ő҂�
     AD1CON1bits.SAMP = 0 ;             // �ϊ��̊J�n
     while (!AD1CON1bits.DONE) ;        // �ϊ��̏I���܂ő҂�
     temp = ADC1BUF0 ;                  // �A�i���O�l(AN0)��ǂݏo��
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
 * Overview:        Telnet�T�[�o�[�֘A�̃^�X�N�����s���܂��B
 *                  Telnet�X�e�[�g�}�V���Ə�ԃg���b�L���O�ϐ����܂܂�܂��B
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

    // �d����������1��̏����������s����
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

    // �etelnet�Z�b�V�����Ə����X�e�[�g�̕ύX��TX/RX�f�[�^�����[�v����
    for (vTelnetSession = 0; vTelnetSession < MAX_TELNET_CONNECTIONS; vTelnetSession++) {
        // ���̃Z�b�V�����̏����X�e�[�g�������[�h����
        MySocket    = hTelnetSockets[vTelnetSession];
        TelnetState = vTelnetStates[vTelnetSession];

        // �����[�g�N���C�A���g���ؒf�����ꍇ�́A��Ԃ����Z�b�g���ĉ������B
        if (MySocket != INVALID_SOCKET) {
            if (TCPWasReset(MySocket))
                TelnetState = SM_PRINT_LOGIN;
        }

        // �Z�b�V������Ԃ���������
        switch (TelnetState) {
           /*** �\�P�b�g�������[�gTCP�T�[�o�[�ɐڑ����鏈�� ***/
           case SM_HOME :
               MySocket = TCPOpen(0, TCP_OPEN_SERVER, TELNET_PORT, TCP_PURPOSE_TELNET);

               // TCP�\�P�b�g���Ȃ��ꍇ�A����𒆎~���܂��B
               // type TCP_PURPOSE_TELNET is available If this ever happens, you need to go add one to tcpip_config.h
               if (MySocket == INVALID_SOCKET)  break ;

               // SSL�T�[�o�[�̃T�|�[�g���L���ȏꍇ�́ASSL���X�i�[���J���܂��B
#if defined(STACK_USE_SSL_SERVER)
               TCPAddSSLListener(MySocket, TELNETS_PORT);
#endif
               // �����X�e�[�g����(SM_PRINT_LOGIN)�ɐi�߂�
               TelnetState++;
               break;

           /*** �^�C�g���̕�����f�[�^�𑗐M���鏈�� ***/
           case SM_PRINT_LOGIN:
#if defined(STACK_USE_SSL_SERVER)
               // TELNET_REJECT_UNSECURED����`����Ă���ꍇ�A���S�łȂ��ڑ������ۂ���
   #if defined(TELNET_REJECT_UNSECURED)
               if (!TCPIsSSL(MySocket)) {
                   if (TCPIsConnected(MySocket)) {
                       TCPDisconnect(MySocket);
                       TCPDisconnect(MySocket);
                       break;
                   }
               }
   #endif
               // �܂��n���h�V�F�C�N���Ă���ꍇ�A�������M���Ȃ��ŉ������B
               if (TCPSSLIsHandshaking(MySocket)) break ;
#endif

               // �^�C�g���̕�������\�P�b�g�ɏ������ގ����o���邩�ǂ������m�F����
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strTitle)) break ;
               // �^�C�g��������f�[�^�𑗐M�o�b�t�@�ɓ���܂��B
               TCPPutROMString(MySocket, strTitle);
               // �p�P�b�g�𑗐M����
               TCPFlush(MySocket);
               // �����X�e�[�g����(SM_GET_LOGIN)�ɐi�߂�
               TelnetState++;

           /*** ���͂��ꂽ���O�C�����𒲂ׂ鏈�� ***/
           case SM_GET_LOGIN:
               // �p�X���[�h�v���̕�������\�P�b�g�ɏ������ގ����o���邩�ǂ������m�F����
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strPassword)) break ;
               // ���[�U�[�����^�[��('LF')�����������ǂ������m�F����
               w = TCPFind(MySocket, '\n', 0, false);  // 'CR+LF'��'LF'�Ŕ��f���Ă���
               if (w == 0xFFFFu) {
                   // �����ł��Ȃ�����
                   if (TCPGetRxFIFOFree(MySocket) == 0u) {
                       // ��M�o�b�t�@�����t��ԂȂ�A�^�C�g���\���̏��܂Ŗ߂�
                       TelnetState = SM_PRINT_LOGIN;
                       TCPGetArray(MySocket, NULL, w + 1);
                   }
                   break;
               }

               // ���O�C�������������� - �啶���Ə���������ʂ��Ȃ�
               w2 = TCPFindROMArray(MySocket, (ROM uint8_t *) TELNET_USERNAME, sizeof (TELNET_USERNAME) - 1, 0, true);
               if (!((sizeof (TELNET_USERNAME) - 1 == w - w2) || (sizeof (TELNET_USERNAME) == w - w2))) {
                   // ���[�U�[����������܂���ł����B
                   // �������A���[�U�[���̐��������R��Ȃ��悤�ɂ��Ă݂܂��傤
                   TelnetState = SM_GET_PASSWORD_BAD_LOGIN;
               } else {
                   TelnetState = SM_GET_PASSWORD;
               }
               // ���O�C�������m�F���ꂽ�̂ŁAFIFO�o�b�t�@����ɂ��܂�
               TCPGetArray(MySocket, NULL, w + 1);

               // �p�X���[�h�v���̕�����𑗐M����
               TCPPutROMString(MySocket, strPassword);
               TCPFlush(MySocket);
               break;

           /*** ���͂��ꂽ�p�X���[�h�𒲂ׂ鏈�� ***/
           case SM_GET_PASSWORD:
           case SM_GET_PASSWORD_BAD_LOGIN:
               // �A�N�Z�X�F�؂̕�������\�P�b�g�ɏ������ގ����o���邩�ǂ������m�F����
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strAuthenticated)) break ;
               // ���[�U�[�����^�[�������������ǂ������m�F����
               w = TCPFind(MySocket, '\n', 0, false);
               if (w == 0xFFFFu) {
                   if (TCPGetRxFIFOFree(MySocket) == 0u) {
                        // ��M�o�b�t�@�����t��ԂȂ�A�^�C�g���\���̏��܂Ŗ߂�
                        TelnetState = SM_PRINT_LOGIN;
                        TCPGetArray(MySocket, NULL, w + 1);
                   }
                   break;
               }

               // �p�X���[�h���������� - �啶���Ə���������ʂ���
               w2 = TCPFindROMArray(MySocket, (ROM uint8_t *) TELNET_PASSWORD, sizeof (TELNET_PASSWORD) - 1, 0, false);
               if ((w2 == 0xFFFF) || (TelnetState == SM_GET_PASSWORD_BAD_LOGIN)) {
                   // �p�X���[�h��������܂���ł����A���̓��O�C�������قȂ�
                   // �^�C�g���\���̏��܂Ŗ߂�
                   TCPGetArray(MySocket, NULL, w + 1);
                   TelnetState = SM_PRINT_LOGIN;
                   break;
               }
               // �p�X���[�h���m�F���ꂽ�̂ŁAFIFO�o�b�t�@����ɂ��܂�
               TCPGetArray(MySocket, NULL, w + 1);

               // �A�N�Z�X�F�؂̕�����𑗐M����
               TCPPutROMString(MySocket, strAuthenticated);
               TCPFlush(MySocket);
               TelnetState = SM_PRINT_COMMAND;
               // No break

           /*** �R�}���h�v���̕������\�����鏈�� ***/
           case SM_PRINT_COMMAND:
               // �R�}���h�v���̕�������\�P�b�g�ɏ������ގ����o���邩�ǂ������m�F����
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strCommand)) break ;
               //  �R�}���h�v��������̃f�[�^�𑗐M����
               TCPPutROMString(MySocket, strCommand);
               TCPFlush(MySocket);
               // �����X�e�[�g����(SM_GET_COMMAND)�ɐi�߂�
               TelnetState++;

           /*** ���͂��ꂽ�R�}���h�ɉ��������� ***/
           case SM_GET_COMMAND:
               // ���\���̕�������\�P�b�g�ɏ������ގ����o���邩�ǂ������m�F����
               if (TCPIsPutReady(MySocket) < strlenpgm((ROM char *) strButton)) break ;
               // ���[�U�[�����^�[��('LF')�����������ǂ������m�F����
               w = TCPFind(MySocket, '\n', 0, false);  // 'CR+LF'��'LF'�Ŕ��f���Ă���
               if (w == 0xFFFFu) {
                   // �����ł��Ȃ�����
                   if (TCPGetRxFIFOFree(MySocket) == 0u) {
                       // ��M�o�b�t�@�����t��ԂȂ�A�^�C�g���\���̏��܂Ŗ߂�
                       TelnetState = SM_PRINT_COMMAND;
                       TCPGetArray(MySocket, NULL, w + 1);
                   }
                   break;
               }

               // ��M�o�b�t�@����ǂݎ���f�[�^���𓾂�
               if (TCPIsGetReady(MySocket)) {
                   // "STATE"�����̌���
                   w2 = TCPFindROMArray(MySocket,(ROM uint8_t *)"STATE", 5, 0, false);
                   if (w2 != 0xFFFFu) {
                       // AN1(�ϒ�R)�̒l��ǂݎ��
                       sprintf(buff,"\r\nAnalog: %04d\r\n",adconv()) ;
                       TCPPutROMString(MySocket, (ROM uint8_t *)buff);
                       // �X�C�b�`�̏�Ԃ𓾂�
                       if (BUTTON0_IO == 0) TCPPutROMString(MySocket, (ROM uint8_t *)&strButton[0]);
                       else                 TCPPutROMString(MySocket, (ROM uint8_t *)&strButton[1]);
                       // �����[�gTCP�T�[�o�[�ɑ���
                       TCPFlush(MySocket);
                       TelnetState = SM_PRINT_COMMAND;
                       TCPGetArray(MySocket, NULL, w + 1);
                       break ;
                   }
                   // "LED"�����̌���
                   w2 = TCPFindROMArray(MySocket,(ROM uint8_t *)"LED", 3, 0, false);
                   if (w2 != 0xFFFFu) {
                       w2 = TCPFindROMArray(MySocket,(ROM uint8_t *)"ON", 2, 0, false);
                       if (w2 != 0xFFFFu) {
                            // �v�����󂯕t���܂����̃��b�Z�[�W�𑗐M����
                            TCPPutROMString(MySocket, (ROM uint8_t *)strAccepte);
                            TCPFlush(MySocket);
                            TelnetState = SM_PRINT_COMMAND;
                            TCPGetArray(MySocket, NULL, w + 1);
                            LED0_IO = 1 ;    // LED��_��
                            break ;
                       }
                       w2 = TCPFindROMArray(MySocket,(ROM uint8_t *)"OFF", 3, 0, false);
                       if (w2 != 0xFFFFu) {
                            // �v�����󂯕t���܂����̃��b�Z�[�W�𑗐M����
                            TCPPutROMString(MySocket, (ROM uint8_t *)strAccepte);
                            TCPFlush(MySocket);
                            TelnetState = SM_PRINT_COMMAND;
                            TCPGetArray(MySocket, NULL, w + 1);
                            LED0_IO = 0 ;    // LED������
                            break ;
                       }
                   }

                   // �P�o�C�g�ǂݍ���
                   TCPGet(MySocket, &i);
                   switch (i) {
                   case 'q':
                   case 'Q':
                       if (TCPIsPutReady(MySocket) >= strlenpgm((ROM char *)strGoodBye)+4) {
                            // �I�����b�Z�[�W�𑗂�A1�b��̐ؒf�҂�
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
                       // ���͂��ꂽ�R�}���h�͖����惁�b�Z�[�W�𑗂�
                       TCPPutROMString(MySocket, strNoCommand) ;
                       TCPFlush(MySocket);
                       break ;
                   }
               }
               break;

           /*** 1�b��ɐؒf���� ***/
           case SM_DISCONNECT:
               if(TickGet() - t >= TICK_SECOND) {
                   // �ڑ���؂�^�C�g���\���ɖ߂�
                   TCPDisconnect(MySocket);
                   TelnetState = SM_PRINT_LOGIN;
               }
               break ;
        }

        // ���݂̃Z�b�V������Ԃ̃X�e�[�g���L�^����
        hTelnetSockets[vTelnetSession] = MySocket;
        vTelnetStates[vTelnetSession]  = TelnetState;
    }
}

#endif // defined(STACK_USE_TELNET_SERVER)
