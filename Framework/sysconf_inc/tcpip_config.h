/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    tcpip_config.h

  Summary:
    

  Description:
    Microchip TCP/IP Stack Demo Application Configuration Header
   (マイクロチップTCP / IPスタックデモアプリケーション構成ヘッダー)

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
*   DATE       BY                   CHANGE/COMMENT                             *
* ---------------------------------------------------------------------------- *
*   2017-04-13 きむ茶工房(きむしげ) 日本語コメントに書き換え                   *
*
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef __TCPIP_CONFIG_H_
#define __TCPIP_CONFIG_H_

#include <stdint.h>



// =======================================================================
//   アプリケーションオプション
// =======================================================================

/* アプリケーションレベルモジュールの選択
 *   次の行のコメントを解除またはコメントを付けて、
 *   次の高レベルアプリケーションモジュールを有効または無効にします。
 *
 * 特定のコンパイルが有効になっている場合（例：STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE)
 * ファイル（例：generic_tcp_client.c）がフォルダ（例：\ tcpip \ wifi_demo_app \ firmware \ src）に有るかどうかを確認します。
 * その様なファイルを他のプロジェクトフォルダからコピーする必要が有るかもしれません。
 *
 */

//#define STACK_USE_UART                       // IPアドレス表示とスタック設定にUARTを使用したアプリケーションのデモ
//#define STACK_USE_UART2TCP_BRIDGE            // UARTからTCPへのブリッジ アプリケーションのデモ
//#define STACK_USE_IP_GLEANING                // arp -s でのIPアドレス変更に対応する実装
//#define STACK_USE_ICMP_SERVER                // ICMP(PING)はサーバ(Ping query応答)機能を実装する
#define STACK_USE_ICMP_CLIENT                // ICMP(PING)はクライアント(送信)機能を実装する
//#define STACK_USE_HTTP2_SERVER               // POST、Cookie、認証などを含む新しいHTTPサーバーの実装
//#define STACK_USE_AUTO_IP                    // リンクレイヤIPアドレス自動設定プロトコルの実装
//#define STACK_USE_DHCP_CLIENT                // IPアドレス及びその他のパラメータを取得する為のDHCPライアントの実装
//#define STACK_USE_DHCP_SERVER                // シングルホストDHCPサーバの実装
//#define STACK_USE_FTP_SERVER                 // FTP サーバ (old)の実装
//#define STACK_USE_SMTP_CLIENT                // SMTP クライアントの実装
//#define STACK_USE_TFTP_CLIENT                // TFTP クライアントの実装
//#define STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE // HTTP クライアントのサンプル(generic_tcp_client.c)
//#define STACK_USE_GENERIC_TCP_SERVER_EXAMPLE // HTTP サーバのサンプル(generic_tcp_server.c)
//#define STACK_USE_TELNET_SERVER              // Telnet サーバの実装
#define STACK_USE_ANNOUNCE                   // マイクロチップ内蔵EthernetデバイスDiscovererサーバ/クライアント
#define STACK_USE_DNS_CLIENT                 // ホスト名文字列をIPアドレスに解決する為のDNSクライアントの実装
//#define STACK_USE_DNS_SERVER                 // ローカルデバイスへのリダイレクト用のDNSサーバの実装
#define STACK_USE_NBNS                       // NBNSホスト名ブロードキャストクエリに応答するNetBIOSネームサービスサーバーの実装
//#define STACK_USE_REBOOT_SERVER              // このPICをリモートでリセットする為のモジュール主、にブートローダーに役立ちます。
//#define STACK_USE_SNTP_CLIENT                // インターネットから現在の日付/時刻を取得する為のSNTPプロトコルの実装
//#define STACK_USE_UDP_PERFORMANCE_TEST       // UDP TXパフォーマンス特性をテストする為のモジュール　注1)
//#define STACK_USE_TCP_PERFORMANCE_TEST       // TCP TXパフォーマンス特性をテストする為のモジュール
//#define STACK_USE_DYNAMICDNS_CLIENT          // 動的DNSクライアントアップデータモジュール
//#define STACK_USE_BERKELEY_API               // バークレーソケットAPIを利用できます。
//#define STACK_USE_ZEROCONF_LINK_LOCAL        // Zeroconf IPv4 リンクローカルアドレッシング
//#define STACK_USE_ZEROCONF_MDNS_SD           // Zeroconf mDNS and mDNS service discovery
//#define STACK_USE_SSL_SERVER                 // SSL サーバーの実装
//#define STACK_USE_SSL_CLIENT                 // SSL クライアントの実装
#define STACK_USE_MODBUS_CLIENT
//#define STACK_USE_MODBUS_SERVER
// 注1) これを有効にすると、膨大な量のUDPブロードキャストパケットが破棄ポート上のネットワークにあふれます。
//      運用ネットワークで、特にVPNで（ブロードバンドトラフィックを限られた帯域幅の接続でトンネリングできる）、
//      これを有効にするときは注意してください。

// =======================================================================
//   データストレージオプション(クライアントは不必要と思われる)
// =======================================================================

/* MPFS 構成
 *   MPFS(Microchip File System)：Webページ用のHTML関連データを保存する為の簡易なファイルシステムです。
 *   MPFSは、他のアプリケーションに必要な時に自動的に組み込まれます。
 *   カスタムアプリケーションで必要な場合は、適切に選択項目のコメントを外します。
 */
//#define STACK_USE_MPFS2

/* MPFSストレージの場所
 *   htmlページが内部プログラムメモリに保存されている場合は、
 *   MPFS_USE_EEPROMとMPFS_USE_SPI_FLASHの両方にコメントを付けてから、
 *   MPFSイメージ（.cまたは.sファイル）をプロジェクトに含めます。
 *   htmlページが外部メモリに格納されている場合は、適切な定義のコメントを外します。
 *
 *   サポートされるシリアルフラッシュ部品には、SST25VFxxxBシリーズが含まれます。
 */
//#define MPFS_USE_EEPROM
//#define MPFS_USE_SPI_FLASH

/* EEPROM アドレッシングの選択
 *   1Mbit EEPROMを使用している場合は、この行のコメントを外して下さい。
 */
//#define USE_EEPROM_25LC1024

/* EEPROM 予約領域
 *   MPFSストレージを開始する前に予約するEEPROMバイト数。
 *   これらのバイトはIPアドレス、MACアドレス、およびその他の必要な変数などの
 *   アプリケーション構成をホストします。
 *
 *   MPFS Classicの場合、この設定は、MPFS2ユーティリティの[詳細設定]ページの
 *   [予約]設定と一致する必要があります。
 */
#define MPFS_RESERVE_BLOCK              (205ul)

/* MPFSファイルハンドル
 *   同時に開くMPFS2ファイルの最大数。
 *
 *   MPFS Classicの場合、これは効果がありません。
 */
#define MAX_MPFS_HANDLES                (7ul)

// =======================================================================
//   ネットワークアドレス指定オプション
// =======================================================================

/* デフォルトのネットワーク構成
 *   これらの設定は、EEPROMにデータが見つからない場合にのみ使用されます。
 *
 *   EEPROMをクリアするには、BUTTON0を押したままボードをリセットし、
 *   LEDが点滅するまで保持し続けます。解除し、再度リセットして下さい。
 *   (デモボードの操作の様だぞっとぉ)
 */
#define MY_DEFAULT_HOST_NAME            "GATEWAY42"  // 15文字までの半角英数字

#define MY_DEFAULT_MAC_BYTE1            (0x00)  // 00-04-A3-00-00-00のデフォルトを使用して下さい。
#define MY_DEFAULT_MAC_BYTE2            (0x04)  // ENCX24J600、MRF24WB0Mを使用する場合、又は
#define MY_DEFAULT_MAC_BYTE3            (0xA3)  // PIC32MX6XX / 7XXの内部イーサネットの場合は、
#define MY_DEFAULT_MAC_BYTE4            (0x00)  // その代わりに工場内でプログラムされた
#define MY_DEFAULT_MAC_BYTE5            (0x00)  // MACアドレスを使用したいと考えています。
#define MY_DEFAULT_MAC_BYTE6            (0x05)  // 

//#define MY_DEFAULT_MAC_BYTE1            (0xFF)  // 00-04-A3-00-00-00のデフォルトを使用して下さい。
//#define MY_DEFAULT_MAC_BYTE2            (0xFF)  // ENCX24J600、MRF24WB0Mを使用する場合、又は
//#define MY_DEFAULT_MAC_BYTE3            (0xFF)  // PIC32MX6XX / 7XXの内部イーサネットの場合は、
//#define MY_DEFAULT_MAC_BYTE4            (0xFF)  // その代わりに工場内でプログラムされた
//#define MY_DEFAULT_MAC_BYTE5            (0xFF)  // MACアドレスを使用したいと考えています。
//#define MY_DEFAULT_MAC_BYTE6            (0xFF)  // 

#define MY_DEFAULT_IP_ADDR_BYTE1        (192ul) // IPアドレス(192.168.3.105)
#define MY_DEFAULT_IP_ADDR_BYTE2        (168ul)
#define MY_DEFAULT_IP_ADDR_BYTE3        (0ul)
#define MY_DEFAULT_IP_ADDR_BYTE4        (5ul)

#define MY_DEFAULT_MASK_BYTE1           (255ul) // サブネット マスク(255.255.255.0)
#define MY_DEFAULT_MASK_BYTE2           (255ul)
#define MY_DEFAULT_MASK_BYTE3           (255ul)
#define MY_DEFAULT_MASK_BYTE4           (0ul)

#define MY_DEFAULT_GATE_BYTE1           (192ul) // デフォルト ゲートウェイ(192.168.3.1)
#define MY_DEFAULT_GATE_BYTE2           (168ul)
#define MY_DEFAULT_GATE_BYTE3           (0ul)
#define MY_DEFAULT_GATE_BYTE4           (1ul)

//#define MY_DEFAULT_PRIMARY_DNS_BYTE1    (192ul) // プライマリ DNS(192.168.3.1)
//#define MY_DEFAULT_PRIMARY_DNS_BYTE2    (168ul)
//#define MY_DEFAULT_PRIMARY_DNS_BYTE3    (0ul)
//#define MY_DEFAULT_PRIMARY_DNS_BYTE4    (1ul)

#define MY_DEFAULT_PRIMARY_DNS_BYTE1    (0ul) // プライマリ DNS(192.168.3.1)
#define MY_DEFAULT_PRIMARY_DNS_BYTE2    (0ul)
#define MY_DEFAULT_PRIMARY_DNS_BYTE3    (0ul)
#define MY_DEFAULT_PRIMARY_DNS_BYTE4    (0ul)

#define MY_DEFAULT_SECONDARY_DNS_BYTE1  (0ul)
#define MY_DEFAULT_SECONDARY_DNS_BYTE2  (0ul)
#define MY_DEFAULT_SECONDARY_DNS_BYTE3  (0ul)
#define MY_DEFAULT_SECONDARY_DNS_BYTE4  (0ul)

// =======================================================================
//   PIC32MX7XX/6XX MAC Layer Options
//   PIC32MX7XX/6XXデバイスを使用しない場合、このセクションは無視してください。
// =======================================================================
#define ETH_CFG_LINK            0       // set to 1 if you need to config the link to specific following parameters
// otherwise the default connection will be attempted
// depending on the selected PHY
#define ETH_CFG_AUTO        1       // use auto negotiation
#define ETH_CFG_10          1       // use/advertise 10 Mbps capability
#define ETH_CFG_100         1       // use/advertise 100 Mbps capability
#define ETH_CFG_HDUPLEX     1       // use/advertise half duplex capability
#define ETH_CFG_FDUPLEX     1       // use/advertise full duplex capability
#define ETH_CFG_AUTO_MDIX   1       // use/advertise auto MDIX capability
#define ETH_CFG_SWAP_MDIX   1       // use swapped MDIX. else normal MDIX

#define EMAC_TX_DESCRIPTORS     2       // number of the TX descriptors to be created
#define EMAC_RX_DESCRIPTORS     8       // number of the RX descriptors and RX buffers to be created

#define EMAC_RX_BUFF_SIZE       1536    // size of a RX buffer. should be multiple of 16
// this is the size of all receive buffers processed by the ETHC
// The size should be enough to accomodate any network received packet
// If the packets are larger, they will have to take multiple RX buffers
// The current implementation does not handle this situation right now and the packet is discarded.

// =======================================================================
//   トランスポート層のオプション
// =======================================================================

/* トランスポート層の構成
 *   上記のモジュール選択に基づいて、以下の低レベルモジュールが自動的に有効になります。
 *   カスタムモジュールで必要な場合は、ここで有効にします。
 */
//#define STACK_USE_TCP
//#define STACK_USE_UDP

/* クライアントモードの設定
 *   このスタックをCLIENTモードで使用する場合は、次の行のコメントを外します。
 *   CLIENTモードでは、クライアント操作に固有のいくつかの機能が有効になります。
 */
//#define STACK_CLIENT_MODE

/* TCPソケットメモリ割り当て
 *   TCPは着信データと発信データをバッファリングする為にメモリを必要とします。
 *   ストレージの量とメディアは、以下の例を参考にしてソケット単位で割り当てる事が出来ます。
 */
// 割り当てるRAMの総量（バイト単位）を割り当てます
// TCP TCB、RX FIFO、およびTX FIFOで使用する為に使用します。
#define TCP_ETH_RAM_SIZE                    (2863ul) // 古いMLA UDPパフォーマンステスト：8192ul; TCPパフォーマンステスト：8951ul
#define TCP_PIC_RAM_SIZE                    (0ul)
#define TCP_SPI_RAM_SIZE                    (0ul)
#define TCP_SPI_RAM_BASE_ADDRESS            (0x00)

// ソケット型の名前を定義する
#define TCP_SOCKET_TYPES
#define TCP_PURPOSE_GENERIC_TCP_CLIENT 0
#define TCP_PURPOSE_GENERIC_TCP_SERVER 1
#define TCP_PURPOSE_TELNET 2
#define TCP_PURPOSE_FTP_COMMAND 3
#define TCP_PURPOSE_FTP_DATA 4
#define TCP_PURPOSE_TCP_PERFORMANCE_TX 5
#define TCP_PURPOSE_TCP_PERFORMANCE_RX 6
#define TCP_PURPOSE_UART_2_TCP_BRIDGE 7
#define TCP_PURPOSE_HTTP_SERVER 8
#define TCP_PURPOSE_DEFAULT 9
#define TCP_PURPOSE_BERKELEY_SERVER 10
#define TCP_PURPOSE_BERKELEY_CLIENT 11
#define TCP_PURPOSE_MODBUS_CLIENT 12
#define TCP_PURPOSE_MODBUS_TCP_SERVER 13
#define END_OF_TCP_SOCKET_TYPES

#if defined(__TCP_C_)
// 必要なソケットのタイプ、それぞれの数、TCB、TX FIFO、RX FIFOの格納場所、
// およびRX FIFOとTX FIFOの大きさを定義します。
// このイニシャライザを大きく又は小さくすると、使用可能なTCPソケットの数が決まります。
//
// 各ソケットには、最大56バイトのPIC RAMと
// 48 +（TX FIFOサイズ）+（RX FIFOサイズ）バイトのTCP_*_RAMが必要です。
//
// 注：TCPが必要とするSYNおよびFINメッセージを受信するには、
//     RX FIFOが少なくとも1バイトである必要があります。
//     TX FIFOは必要に応じてゼロにする事が出来ます。
#define TCP_CONFIGURATION

const struct {
    uint8_t vSocketPurpose;
    uint8_t vMemoryMedium;
    uint16_t wTXBufferSize;
    uint16_t wRXBufferSize;
} TCPSocketInitializer[] = {
 
#if defined(STACK_USE_MODBUS_CLIENT)
    {TCP_PURPOSE_MODBUS_CLIENT,TCP_ETH_RAM, 500, 500},
#endif
    
    
#if defined(STACK_USE_MODBUS_SERVER)
   {TCP_PURPOSE_MODBUS_TCP_SERVER,TCP_ETH_RAM, 260, 260},
#endif  
    
#if defined(STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE)
    {TCP_PURPOSE_GENERIC_TCP_CLIENT, TCP_ETH_RAM, 100, 100},
#endif

#if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)
    {TCP_PURPOSE_GENERIC_TCP_SERVER, TCP_ETH_RAM, 100, 100},
#endif

#if defined(STACK_USE_IPERF) // これらのソケットはIperfでも使用されています
    {TCP_PURPOSE_GENERIC_TCP_CLIENT, TCP_ETH_RAM, 125, 100},
    {TCP_PURPOSE_GENERIC_TCP_SERVER, TCP_ETH_RAM, 20, 20},
#endif

#ifdef STACK_USE_TELNET_SERVER
    {TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
    //{TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
    //{TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
#endif

#ifdef STACK_USE_FTP_SERVER
    {TCP_PURPOSE_FTP_COMMAND, TCP_ETH_RAM, 100, 40},
    {TCP_PURPOSE_FTP_DATA, TCP_ETH_RAM, 0, 128},
#endif

#ifdef STACK_USE_TCP_PERFORMANCE_TEST
    {TCP_PURPOSE_TCP_PERFORMANCE_TX, TCP_ETH_RAM, 200, 1},
    //{TCP_PURPOSE_TCP_PERFORMANCE_RX, TCP_ETH_RAM, 40, 1500}, // TCPスループットを測定する為に、Iperfに置換えられましたので、もう必要有りません
#endif

#ifdef STACK_USE_UART2TCP_BRIDGE
    {TCP_PURPOSE_UART_2_TCP_BRIDGE, TCP_ETH_RAM, 256, 256},
#endif

#ifdef STACK_USE_HTTP2_SERVER
#if defined(STACK_USE_SSL_SERVER) || defined(STACK_USE_SSL_CLIENT)
    {TCP_PURPOSE_HTTP_SERVER, TCP_ETH_RAM, 800, 800},
    {TCP_PURPOSE_HTTP_SERVER, TCP_ETH_RAM, 800, 800},
#else
    {TCP_PURPOSE_HTTP_SERVER, TCP_ETH_RAM, 1000, 1000},
    {TCP_PURPOSE_HTTP_SERVER, TCP_ETH_RAM, 1000, 1000},
#endif
#endif

#ifdef STACK_USE_SMTP_CLIENT
    {TCP_PURPOSE_DEFAULT, TCP_ETH_RAM, 1000, 1000},
#endif

#ifdef STACK_USE_BERKELEY_API
    {TCP_PURPOSE_BERKELEY_SERVER, TCP_ETH_RAM, 25, 20},
    {TCP_PURPOSE_BERKELEY_SERVER, TCP_ETH_RAM, 25, 20},
    {TCP_PURPOSE_BERKELEY_SERVER, TCP_ETH_RAM, 25, 20},
    {TCP_PURPOSE_BERKELEY_CLIENT, TCP_ETH_RAM, 125, 100},
#endif
};
#define END_OF_TCP_CONFIGURATION
#endif

/* UDPソケット設定
 *   使用可能なUDPソケットの最大数と、
 *   送信されるパケットにチェックサムを含めるかどうかを定義します。
 */
#define MAX_UDP_SOCKETS     (8u)
//   チェックサムを含めると、超高速DMAを備え、
//   事実上スピードがないENCX24J600またはPIC32MX6XX/7XXを使用している場合を除き、
//   UDP TXパフォーマンスはほぼ50％低下します。
//#define UDP_USE_TX_CHECKSUM

/* バークレーAPIソケットの設定
 *   各Berkeleyソケットは、MAX_UDP_SOCKETSとTCPSocketInitializer[]配列で定義された1つの
 *   TCPソケットまたはUDPソケットを内部的に使用しています。
 *   したがって、この数は、MAX_UDP_SOCKETS + TCPSocketInitializer[]配列で定義されたTCPソケットの数
 *  （つまり、sizeof(TCPSocketInitializer）/ sizeof(TCPSocketInitializer[0]））以下でなければなりません。
 *   STACK_USE_BERKELEY_APIが定義されておらず、Berkeley Socketsが無効な場合、この定義は無効です。
 *   この値は、アプリケーションがRAMをぶら下げない様にする為に低く設定して下さい。
 */
#define BSD_SOCKET_COUNT (5u)

// =======================================================================
//   アプリケーション固有のオプション
// =======================================================================

// -- HTTP2 Server options -----------------------------------------------

// 同時HTTP接続の最大数
// 各接続は2バイトのRAMとTCPソケットを消費します。
#define MAX_HTTP_CONNECTIONS    (2u)

// HTTP接続コンテキスト変数（HTTP接続ごとにHTTP_CONN構造体）を格納する為に
// イーサネット/ Wi-Fi RAMの代わりにPIC RAMを使用する為のオプションの設定。
// このマクロの定義を解除すると、イーサネット/Wi-Fi RAMが使用されます(最小PIC RAM使用率、パフォーマンス低下)。
// このマクロを定義すると、PIC RAMが使用されます(パフォーマンスは向上します)。
// PIC18デバイスでこのオプションを有効にするべきではありません。
// このオプションが定義されているとパフォーマンスが向上するのは、
// HTTPサーバーが複数の接続を同時に処理している場合のみです
//#define HTTP_SAVE_CONTEXT_IN_PIC_RAM

// 特定のファイルが要求されていない時にどのファイルを表示するかを指定する
#define HTTP_DEFAULT_FILE       "index.htm"
#define HTTPS_DEFAULT_FILE      "index.htm"
// バッファオーバーラン保護の為、上記の2つの文字列の最長に設定します。
#define HTTP_DEFAULT_LEN        (10u)

// MPFS over HTTPの更新を設定
// HTTP経由での更新を無効にするには、この行をコメントにする
// MPFSアップロードのパスワードを要求する特定のファイアウォールとルータの組合わせにより、
// アップロード時にMPFS2ユーティリティが失敗することがあります。
// このような場合は、この定義をコメントアウトしてください。
#define HTTP_MPFS_UPLOAD        "mpfsupload"

// 使用するHTTPのモジュールを定義
// 特定のモジュールを使用していない場合は、コメントを付けてリソースを節約してください。
#define HTTP_USE_POST                   // POSTサポートを有効にする
#define HTTP_USE_COOKIES                // Cookieのサポートを有効にする
#define HTTP_USE_AUTHENTICATION         // 基本認証サポートを有効にする

//#define HTTP_NO_AUTH_WITHOUT_SSL      // Uncomment to require SSL before requesting a password

// HTTPサーバーのリスニング・ポートを定義
#define HTTP_PORT               (80u)

// HTTPSサーバのリスニングポートを定義（STACK_USE_SSL_SERVERが有効な場合）
#define HTTPS_PORT              (443u)

// CookieおよびGET/POST引数(バイト）を読み取る為の最大データ長を定義
#define HTTP_MAX_DATA_LEN       (100u)

// コールバックを実行する前にTX FIFOに空きの最小バイト数を定義
#define HTTP_MIN_CALLBACK_FREE  (16u)

#define STACK_USE_HTTP_APP_RECONFIG     // Use the AppConfig web page in the Demo App (~2.5kb ROM, ~0b RAM)
#define STACK_USE_HTTP_MD5_DEMO         // MD5デモはWebページを使用する(~5kb ROM, ~160b RAM)
//#define STACK_USE_HTTP_EMAIL_DEMO     // 電子メールデモはWebページを使用する

// -- SSL Options --------------------------------------------------------

#define MAX_SSL_CONNECTIONS     (2ul)   // SSLによる最大接続数
#define MAX_SSL_SESSIONS        (2ul)   // キャッシュされたSSLセッションの最大数
#define MAX_SSL_BUFFERS         (4ul)   // SSLバッファの最大数（ソケットあたり2個）
#define MAX_SSL_HASHES          (5ul)   // SSLハッシュの最大数（デッドロックを回避する為に、2 per, plus 1）

// SSL RSAキーのビット。
// このパラメーターは、SSLサーバー接続にのみ使用されます。
#define SSL_RSA_KEY_SIZE        (512ul)

// -- Telnet Options -----------------------------------------------------

// 同時に許可されるTelnetセッションの数
// 上記のTCPSocketInitializer[]配列で宣言されているTCP_PURPOSE_TELNET型のTCPソケットと
// 同じ数の複数の接続が機能するようにする必要があります。
// この定義よりも使用可能なソケットが少ない場合、何方かのうち小さい方が実際の制限になります。
#define MAX_TELNET_CONNECTIONS  (1u)

// Telnetサーバーのデフォルトのローカルリスニングポート。
// ポート23がプロトコルのデフォルトです。
#define TELNET_PORT             23

// SSLで保護されている場合のTelnetサーバーのデフォルトのローカルリスニングポート。
// ポート992が、telnetプロトコルのデフォルトです。
#define TELNETS_PORT            992

// 接続するすべてのクライアントをSSLで保護し、TELNETS_PORT経由で接続します。
// TELNET_PORTのポート接続は無視されます。
// STACK_USE_SSL_SERVERが未定義の場合、この全体の設定は無視されます。
// (server will accept unsecured connections on TELNET_PORT and won't even listen on TELNETS_PORT).
//#define TELNET_REJECT_UNSECURED

// Telnetサーバーへのログインに必要なデフォルトのユーザー名とパスワード。
#define TELNET_USERNAME         "admin"
#define TELNET_PASSWORD         "microchip"

#endif /* __TCPIP_CONFIG_H_ */
