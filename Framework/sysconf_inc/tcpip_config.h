/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    tcpip_config.h

  Summary:
    

  Description:
    Microchip TCP/IP Stack Demo Application Configuration Header
   (�}�C�N���`�b�vTCP / IP�X�^�b�N�f���A�v���P�[�V�����\���w�b�_�[)

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
*   2017-04-13 ���ޒ��H�[(���ނ���) ���{��R�����g�ɏ�������                   *
*
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef __TCPIP_CONFIG_H_
#define __TCPIP_CONFIG_H_

#include <stdint.h>



// =======================================================================
//   �A�v���P�[�V�����I�v�V����
// =======================================================================

/* �A�v���P�[�V�������x�����W���[���̑I��
 *   ���̍s�̃R�����g�������܂��̓R�����g��t���āA
 *   ���̍����x���A�v���P�[�V�������W���[����L���܂��͖����ɂ��܂��B
 *
 * ����̃R���p�C�����L���ɂȂ��Ă���ꍇ�i��FSTACK_USE_GENERIC_TCP_CLIENT_EXAMPLE)
 * �t�@�C���i��Fgeneric_tcp_client.c�j���t�H���_�i��F\ tcpip \ wifi_demo_app \ firmware \ src�j�ɗL�邩�ǂ������m�F���܂��B
 * ���̗l�ȃt�@�C���𑼂̃v���W�F�N�g�t�H���_����R�s�[����K�v���L�邩������܂���B
 *
 */

//#define STACK_USE_UART                       // IP�A�h���X�\���ƃX�^�b�N�ݒ��UART���g�p�����A�v���P�[�V�����̃f��
//#define STACK_USE_UART2TCP_BRIDGE            // UART����TCP�ւ̃u���b�W �A�v���P�[�V�����̃f��
//#define STACK_USE_IP_GLEANING                // arp -s �ł�IP�A�h���X�ύX�ɑΉ��������
//#define STACK_USE_ICMP_SERVER                // ICMP(PING)�̓T�[�o(Ping query����)�@�\����������
#define STACK_USE_ICMP_CLIENT                // ICMP(PING)�̓N���C�A���g(���M)�@�\����������
//#define STACK_USE_HTTP2_SERVER               // POST�ACookie�A�F�؂Ȃǂ��܂ސV����HTTP�T�[�o�[�̎���
//#define STACK_USE_AUTO_IP                    // �����N���C��IP�A�h���X�����ݒ�v���g�R���̎���
//#define STACK_USE_DHCP_CLIENT                // IP�A�h���X�y�т��̑��̃p�����[�^���擾����ׂ�DHCP���C�A���g�̎���
//#define STACK_USE_DHCP_SERVER                // �V���O���z�X�gDHCP�T�[�o�̎���
//#define STACK_USE_FTP_SERVER                 // FTP �T�[�o (old)�̎���
//#define STACK_USE_SMTP_CLIENT                // SMTP �N���C�A���g�̎���
//#define STACK_USE_TFTP_CLIENT                // TFTP �N���C�A���g�̎���
//#define STACK_USE_GENERIC_TCP_CLIENT_EXAMPLE // HTTP �N���C�A���g�̃T���v��(generic_tcp_client.c)
//#define STACK_USE_GENERIC_TCP_SERVER_EXAMPLE // HTTP �T�[�o�̃T���v��(generic_tcp_server.c)
//#define STACK_USE_TELNET_SERVER              // Telnet �T�[�o�̎���
#define STACK_USE_ANNOUNCE                   // �}�C�N���`�b�v����Ethernet�f�o�C�XDiscoverer�T�[�o/�N���C�A���g
#define STACK_USE_DNS_CLIENT                 // �z�X�g���������IP�A�h���X�ɉ�������ׂ�DNS�N���C�A���g�̎���
//#define STACK_USE_DNS_SERVER                 // ���[�J���f�o�C�X�ւ̃��_�C���N�g�p��DNS�T�[�o�̎���
#define STACK_USE_NBNS                       // NBNS�z�X�g���u���[�h�L���X�g�N�G���ɉ�������NetBIOS�l�[���T�[�r�X�T�[�o�[�̎���
//#define STACK_USE_REBOOT_SERVER              // ����PIC�������[�g�Ń��Z�b�g����ׂ̃��W���[����A�Ƀu�[�g���[�_�[�ɖ𗧂��܂��B
//#define STACK_USE_SNTP_CLIENT                // �C���^�[�l�b�g���猻�݂̓��t/�������擾����ׂ�SNTP�v���g�R���̎���
//#define STACK_USE_UDP_PERFORMANCE_TEST       // UDP TX�p�t�H�[�}���X�������e�X�g����ׂ̃��W���[���@��1)
//#define STACK_USE_TCP_PERFORMANCE_TEST       // TCP TX�p�t�H�[�}���X�������e�X�g����ׂ̃��W���[��
//#define STACK_USE_DYNAMICDNS_CLIENT          // ���IDNS�N���C�A���g�A�b�v�f�[�^���W���[��
//#define STACK_USE_BERKELEY_API               // �o�[�N���[�\�P�b�gAPI�𗘗p�ł��܂��B
//#define STACK_USE_ZEROCONF_LINK_LOCAL        // Zeroconf IPv4 �����N���[�J���A�h���b�V���O
//#define STACK_USE_ZEROCONF_MDNS_SD           // Zeroconf mDNS and mDNS service discovery
//#define STACK_USE_SSL_SERVER                 // SSL �T�[�o�[�̎���
//#define STACK_USE_SSL_CLIENT                 // SSL �N���C�A���g�̎���
#define STACK_USE_MODBUS_CLIENT
//#define STACK_USE_MODBUS_SERVER
// ��1) �����L���ɂ���ƁA�c��ȗʂ�UDP�u���[�h�L���X�g�p�P�b�g���j���|�[�g��̃l�b�g���[�N�ɂ��ӂ�܂��B
//      �^�p�l�b�g���[�N�ŁA����VPN�Łi�u���[�h�o���h�g���t�B�b�N������ꂽ�ш敝�̐ڑ��Ńg���l�����O�ł���j�A
//      �����L���ɂ���Ƃ��͒��ӂ��Ă��������B

// =======================================================================
//   �f�[�^�X�g���[�W�I�v�V����(�N���C�A���g�͕s�K�v�Ǝv����)
// =======================================================================

/* MPFS �\��
 *   MPFS(Microchip File System)�FWeb�y�[�W�p��HTML�֘A�f�[�^��ۑ�����ׂ̊ȈՂȃt�@�C���V�X�e���ł��B
 *   MPFS�́A���̃A�v���P�[�V�����ɕK�v�Ȏ��Ɏ����I�ɑg�ݍ��܂�܂��B
 *   �J�X�^���A�v���P�[�V�����ŕK�v�ȏꍇ�́A�K�؂ɑI�����ڂ̃R�����g���O���܂��B
 */
//#define STACK_USE_MPFS2

/* MPFS�X�g���[�W�̏ꏊ
 *   html�y�[�W�������v���O�����������ɕۑ�����Ă���ꍇ�́A
 *   MPFS_USE_EEPROM��MPFS_USE_SPI_FLASH�̗����ɃR�����g��t���Ă���A
 *   MPFS�C���[�W�i.c�܂���.s�t�@�C���j���v���W�F�N�g�Ɋ܂߂܂��B
 *   html�y�[�W���O���������Ɋi�[����Ă���ꍇ�́A�K�؂Ȓ�`�̃R�����g���O���܂��B
 *
 *   �T�|�[�g�����V���A���t���b�V�����i�ɂ́ASST25VFxxxB�V���[�Y���܂܂�܂��B
 */
//#define MPFS_USE_EEPROM
//#define MPFS_USE_SPI_FLASH

/* EEPROM �A�h���b�V���O�̑I��
 *   1Mbit EEPROM���g�p���Ă���ꍇ�́A���̍s�̃R�����g���O���ĉ������B
 */
//#define USE_EEPROM_25LC1024

/* EEPROM �\��̈�
 *   MPFS�X�g���[�W���J�n����O�ɗ\�񂷂�EEPROM�o�C�g���B
 *   �����̃o�C�g��IP�A�h���X�AMAC�A�h���X�A����т��̑��̕K�v�ȕϐ��Ȃǂ�
 *   �A�v���P�[�V�����\�����z�X�g���܂��B
 *
 *   MPFS Classic�̏ꍇ�A���̐ݒ�́AMPFS2���[�e�B���e�B��[�ڍאݒ�]�y�[�W��
 *   [�\��]�ݒ�ƈ�v����K�v������܂��B
 */
#define MPFS_RESERVE_BLOCK              (205ul)

/* MPFS�t�@�C���n���h��
 *   �����ɊJ��MPFS2�t�@�C���̍ő吔�B
 *
 *   MPFS Classic�̏ꍇ�A����͌��ʂ�����܂���B
 */
#define MAX_MPFS_HANDLES                (7ul)

// =======================================================================
//   �l�b�g���[�N�A�h���X�w��I�v�V����
// =======================================================================

/* �f�t�H���g�̃l�b�g���[�N�\��
 *   �����̐ݒ�́AEEPROM�Ƀf�[�^��������Ȃ��ꍇ�ɂ̂ݎg�p����܂��B
 *
 *   EEPROM���N���A����ɂ́ABUTTON0���������܂܃{�[�h�����Z�b�g���A
 *   LED���_�ł���܂ŕێ��������܂��B�������A�ēx���Z�b�g���ĉ������B
 *   (�f���{�[�h�̑���̗l�������Ƃ�)
 */
#define MY_DEFAULT_HOST_NAME            "GATEWAY42"  // 15�����܂ł̔��p�p����

#define MY_DEFAULT_MAC_BYTE1            (0x00)  // 00-04-A3-00-00-00�̃f�t�H���g���g�p���ĉ������B
#define MY_DEFAULT_MAC_BYTE2            (0x04)  // ENCX24J600�AMRF24WB0M���g�p����ꍇ�A����
#define MY_DEFAULT_MAC_BYTE3            (0xA3)  // PIC32MX6XX / 7XX�̓����C�[�T�l�b�g�̏ꍇ�́A
#define MY_DEFAULT_MAC_BYTE4            (0x00)  // ���̑���ɍH����Ńv���O�������ꂽ
#define MY_DEFAULT_MAC_BYTE5            (0x00)  // MAC�A�h���X���g�p�������ƍl���Ă��܂��B
#define MY_DEFAULT_MAC_BYTE6            (0x05)  // 

//#define MY_DEFAULT_MAC_BYTE1            (0xFF)  // 00-04-A3-00-00-00�̃f�t�H���g���g�p���ĉ������B
//#define MY_DEFAULT_MAC_BYTE2            (0xFF)  // ENCX24J600�AMRF24WB0M���g�p����ꍇ�A����
//#define MY_DEFAULT_MAC_BYTE3            (0xFF)  // PIC32MX6XX / 7XX�̓����C�[�T�l�b�g�̏ꍇ�́A
//#define MY_DEFAULT_MAC_BYTE4            (0xFF)  // ���̑���ɍH����Ńv���O�������ꂽ
//#define MY_DEFAULT_MAC_BYTE5            (0xFF)  // MAC�A�h���X���g�p�������ƍl���Ă��܂��B
//#define MY_DEFAULT_MAC_BYTE6            (0xFF)  // 

#define MY_DEFAULT_IP_ADDR_BYTE1        (192ul) // IP�A�h���X(192.168.3.105)
#define MY_DEFAULT_IP_ADDR_BYTE2        (168ul)
#define MY_DEFAULT_IP_ADDR_BYTE3        (0ul)
#define MY_DEFAULT_IP_ADDR_BYTE4        (5ul)

#define MY_DEFAULT_MASK_BYTE1           (255ul) // �T�u�l�b�g �}�X�N(255.255.255.0)
#define MY_DEFAULT_MASK_BYTE2           (255ul)
#define MY_DEFAULT_MASK_BYTE3           (255ul)
#define MY_DEFAULT_MASK_BYTE4           (0ul)

#define MY_DEFAULT_GATE_BYTE1           (192ul) // �f�t�H���g �Q�[�g�E�F�C(192.168.3.1)
#define MY_DEFAULT_GATE_BYTE2           (168ul)
#define MY_DEFAULT_GATE_BYTE3           (0ul)
#define MY_DEFAULT_GATE_BYTE4           (1ul)

//#define MY_DEFAULT_PRIMARY_DNS_BYTE1    (192ul) // �v���C�}�� DNS(192.168.3.1)
//#define MY_DEFAULT_PRIMARY_DNS_BYTE2    (168ul)
//#define MY_DEFAULT_PRIMARY_DNS_BYTE3    (0ul)
//#define MY_DEFAULT_PRIMARY_DNS_BYTE4    (1ul)

#define MY_DEFAULT_PRIMARY_DNS_BYTE1    (0ul) // �v���C�}�� DNS(192.168.3.1)
#define MY_DEFAULT_PRIMARY_DNS_BYTE2    (0ul)
#define MY_DEFAULT_PRIMARY_DNS_BYTE3    (0ul)
#define MY_DEFAULT_PRIMARY_DNS_BYTE4    (0ul)

#define MY_DEFAULT_SECONDARY_DNS_BYTE1  (0ul)
#define MY_DEFAULT_SECONDARY_DNS_BYTE2  (0ul)
#define MY_DEFAULT_SECONDARY_DNS_BYTE3  (0ul)
#define MY_DEFAULT_SECONDARY_DNS_BYTE4  (0ul)

// =======================================================================
//   PIC32MX7XX/6XX MAC Layer Options
//   PIC32MX7XX/6XX�f�o�C�X���g�p���Ȃ��ꍇ�A���̃Z�N�V�����͖������Ă��������B
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
//   �g�����X�|�[�g�w�̃I�v�V����
// =======================================================================

/* �g�����X�|�[�g�w�̍\��
 *   ��L�̃��W���[���I���Ɋ�Â��āA�ȉ��̒჌�x�����W���[���������I�ɗL���ɂȂ�܂��B
 *   �J�X�^�����W���[���ŕK�v�ȏꍇ�́A�����ŗL���ɂ��܂��B
 */
//#define STACK_USE_TCP
//#define STACK_USE_UDP

/* �N���C�A���g���[�h�̐ݒ�
 *   ���̃X�^�b�N��CLIENT���[�h�Ŏg�p����ꍇ�́A���̍s�̃R�����g���O���܂��B
 *   CLIENT���[�h�ł́A�N���C�A���g����ɌŗL�̂������̋@�\���L���ɂȂ�܂��B
 */
//#define STACK_CLIENT_MODE

/* TCP�\�P�b�g���������蓖��
 *   TCP�͒��M�f�[�^�Ɣ��M�f�[�^���o�b�t�@�����O����ׂɃ�������K�v�Ƃ��܂��B
 *   �X�g���[�W�̗ʂƃ��f�B�A�́A�ȉ��̗���Q�l�ɂ��ă\�P�b�g�P�ʂŊ��蓖�Ă鎖���o���܂��B
 */
// ���蓖�Ă�RAM�̑��ʁi�o�C�g�P�ʁj�����蓖�Ă܂�
// TCP TCB�ARX FIFO�A�����TX FIFO�Ŏg�p����ׂɎg�p���܂��B
#define TCP_ETH_RAM_SIZE                    (2863ul) // �Â�MLA UDP�p�t�H�[�}���X�e�X�g�F8192ul; TCP�p�t�H�[�}���X�e�X�g�F8951ul
#define TCP_PIC_RAM_SIZE                    (0ul)
#define TCP_SPI_RAM_SIZE                    (0ul)
#define TCP_SPI_RAM_BASE_ADDRESS            (0x00)

// �\�P�b�g�^�̖��O���`����
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
// �K�v�ȃ\�P�b�g�̃^�C�v�A���ꂼ��̐��ATCB�ATX FIFO�ARX FIFO�̊i�[�ꏊ�A
// �����RX FIFO��TX FIFO�̑傫�����`���܂��B
// ���̃C�j�V�����C�U��傫�����͏���������ƁA�g�p�\��TCP�\�P�b�g�̐������܂�܂��B
//
// �e�\�P�b�g�ɂ́A�ő�56�o�C�g��PIC RAM��
// 48 +�iTX FIFO�T�C�Y�j+�iRX FIFO�T�C�Y�j�o�C�g��TCP_*_RAM���K�v�ł��B
//
// ���FTCP���K�v�Ƃ���SYN�����FIN���b�Z�[�W����M����ɂ́A
//     RX FIFO�����Ȃ��Ƃ�1�o�C�g�ł���K�v������܂��B
//     TX FIFO�͕K�v�ɉ����ă[���ɂ��鎖���o���܂��B
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

#if defined(STACK_USE_IPERF) // �����̃\�P�b�g��Iperf�ł��g�p����Ă��܂�
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
    //{TCP_PURPOSE_TCP_PERFORMANCE_RX, TCP_ETH_RAM, 40, 1500}, // TCP�X���[�v�b�g�𑪒肷��ׂɁAIperf�ɒu�������܂����̂ŁA�����K�v�L��܂���
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

/* UDP�\�P�b�g�ݒ�
 *   �g�p�\��UDP�\�P�b�g�̍ő吔�ƁA
 *   ���M�����p�P�b�g�Ƀ`�F�b�N�T�����܂߂邩�ǂ������`���܂��B
 */
#define MAX_UDP_SOCKETS     (8u)
//   �`�F�b�N�T�����܂߂�ƁA������DMA������A
//   ������X�s�[�h���Ȃ�ENCX24J600�܂���PIC32MX6XX/7XX���g�p���Ă���ꍇ�������A
//   UDP TX�p�t�H�[�}���X�͂ق�50���ቺ���܂��B
//#define UDP_USE_TX_CHECKSUM

/* �o�[�N���[API�\�P�b�g�̐ݒ�
 *   �eBerkeley�\�P�b�g�́AMAX_UDP_SOCKETS��TCPSocketInitializer[]�z��Œ�`���ꂽ1��
 *   TCP�\�P�b�g�܂���UDP�\�P�b�g������I�Ɏg�p���Ă��܂��B
 *   ���������āA���̐��́AMAX_UDP_SOCKETS + TCPSocketInitializer[]�z��Œ�`���ꂽTCP�\�P�b�g�̐�
 *  �i�܂�Asizeof(TCPSocketInitializer�j/ sizeof(TCPSocketInitializer[0]�j�j�ȉ��łȂ���΂Ȃ�܂���B
 *   STACK_USE_BERKELEY_API����`����Ă��炸�ABerkeley Sockets�������ȏꍇ�A���̒�`�͖����ł��B
 *   ���̒l�́A�A�v���P�[�V������RAM���Ԃ牺���Ȃ��l�ɂ���ׂɒႭ�ݒ肵�ĉ������B
 */
#define BSD_SOCKET_COUNT (5u)

// =======================================================================
//   �A�v���P�[�V�����ŗL�̃I�v�V����
// =======================================================================

// -- HTTP2 Server options -----------------------------------------------

// ����HTTP�ڑ��̍ő吔
// �e�ڑ���2�o�C�g��RAM��TCP�\�P�b�g������܂��B
#define MAX_HTTP_CONNECTIONS    (2u)

// HTTP�ڑ��R���e�L�X�g�ϐ��iHTTP�ڑ����Ƃ�HTTP_CONN�\���́j���i�[����ׂ�
// �C�[�T�l�b�g/ Wi-Fi RAM�̑����PIC RAM���g�p����ׂ̃I�v�V�����̐ݒ�B
// ���̃}�N���̒�`����������ƁA�C�[�T�l�b�g/Wi-Fi RAM���g�p����܂�(�ŏ�PIC RAM�g�p���A�p�t�H�[�}���X�ቺ)�B
// ���̃}�N�����`����ƁAPIC RAM���g�p����܂�(�p�t�H�[�}���X�͌��サ�܂�)�B
// PIC18�f�o�C�X�ł��̃I�v�V������L���ɂ���ׂ��ł͂���܂���B
// ���̃I�v�V��������`����Ă���ƃp�t�H�[�}���X�����シ��̂́A
// HTTP�T�[�o�[�������̐ڑ��𓯎��ɏ������Ă���ꍇ�݂̂ł�
//#define HTTP_SAVE_CONTEXT_IN_PIC_RAM

// ����̃t�@�C�����v������Ă��Ȃ����ɂǂ̃t�@�C����\�����邩���w�肷��
#define HTTP_DEFAULT_FILE       "index.htm"
#define HTTPS_DEFAULT_FILE      "index.htm"
// �o�b�t�@�I�[�o�[�����ی�ׁ̈A��L��2�̕�����̍Œ��ɐݒ肵�܂��B
#define HTTP_DEFAULT_LEN        (10u)

// MPFS over HTTP�̍X�V��ݒ�
// HTTP�o�R�ł̍X�V�𖳌��ɂ���ɂ́A���̍s���R�����g�ɂ���
// MPFS�A�b�v���[�h�̃p�X���[�h��v���������̃t�@�C�A�E�H�[���ƃ��[�^�̑g���킹�ɂ��A
// �A�b�v���[�h����MPFS2���[�e�B���e�B�����s���邱�Ƃ�����܂��B
// ���̂悤�ȏꍇ�́A���̒�`���R�����g�A�E�g���Ă��������B
#define HTTP_MPFS_UPLOAD        "mpfsupload"

// �g�p����HTTP�̃��W���[�����`
// ����̃��W���[�����g�p���Ă��Ȃ��ꍇ�́A�R�����g��t���ă��\�[�X��ߖ񂵂Ă��������B
#define HTTP_USE_POST                   // POST�T�|�[�g��L���ɂ���
#define HTTP_USE_COOKIES                // Cookie�̃T�|�[�g��L���ɂ���
#define HTTP_USE_AUTHENTICATION         // ��{�F�؃T�|�[�g��L���ɂ���

//#define HTTP_NO_AUTH_WITHOUT_SSL      // Uncomment to require SSL before requesting a password

// HTTP�T�[�o�[�̃��X�j���O�E�|�[�g���`
#define HTTP_PORT               (80u)

// HTTPS�T�[�o�̃��X�j���O�|�[�g���`�iSTACK_USE_SSL_SERVER���L���ȏꍇ�j
#define HTTPS_PORT              (443u)

// Cookie�����GET/POST����(�o�C�g�j��ǂݎ��ׂ̍ő�f�[�^�����`
#define HTTP_MAX_DATA_LEN       (100u)

// �R�[���o�b�N�����s����O��TX FIFO�ɋ󂫂̍ŏ��o�C�g�����`
#define HTTP_MIN_CALLBACK_FREE  (16u)

#define STACK_USE_HTTP_APP_RECONFIG     // Use the AppConfig web page in the Demo App (~2.5kb ROM, ~0b RAM)
#define STACK_USE_HTTP_MD5_DEMO         // MD5�f����Web�y�[�W���g�p����(~5kb ROM, ~160b RAM)
//#define STACK_USE_HTTP_EMAIL_DEMO     // �d�q���[���f����Web�y�[�W���g�p����

// -- SSL Options --------------------------------------------------------

#define MAX_SSL_CONNECTIONS     (2ul)   // SSL�ɂ��ő�ڑ���
#define MAX_SSL_SESSIONS        (2ul)   // �L���b�V�����ꂽSSL�Z�b�V�����̍ő吔
#define MAX_SSL_BUFFERS         (4ul)   // SSL�o�b�t�@�̍ő吔�i�\�P�b�g������2�j
#define MAX_SSL_HASHES          (5ul)   // SSL�n�b�V���̍ő吔�i�f�b�h���b�N���������ׂɁA2 per, plus 1�j

// SSL RSA�L�[�̃r�b�g�B
// ���̃p�����[�^�[�́ASSL�T�[�o�[�ڑ��ɂ̂ݎg�p����܂��B
#define SSL_RSA_KEY_SIZE        (512ul)

// -- Telnet Options -----------------------------------------------------

// �����ɋ������Telnet�Z�b�V�����̐�
// ��L��TCPSocketInitializer[]�z��Ő錾����Ă���TCP_PURPOSE_TELNET�^��TCP�\�P�b�g��
// �������̕����̐ڑ����@�\����悤�ɂ���K�v������܂��B
// ���̒�`�����g�p�\�ȃ\�P�b�g�����Ȃ��ꍇ�A�������̂����������������ۂ̐����ɂȂ�܂��B
#define MAX_TELNET_CONNECTIONS  (1u)

// Telnet�T�[�o�[�̃f�t�H���g�̃��[�J�����X�j���O�|�[�g�B
// �|�[�g23���v���g�R���̃f�t�H���g�ł��B
#define TELNET_PORT             23

// SSL�ŕی삳��Ă���ꍇ��Telnet�T�[�o�[�̃f�t�H���g�̃��[�J�����X�j���O�|�[�g�B
// �|�[�g992���Atelnet�v���g�R���̃f�t�H���g�ł��B
#define TELNETS_PORT            992

// �ڑ����邷�ׂẴN���C�A���g��SSL�ŕی삵�ATELNETS_PORT�o�R�Őڑ����܂��B
// TELNET_PORT�̃|�[�g�ڑ��͖�������܂��B
// STACK_USE_SSL_SERVER������`�̏ꍇ�A���̑S�̂̐ݒ�͖�������܂��B
// (server will accept unsecured connections on TELNET_PORT and won't even listen on TELNETS_PORT).
//#define TELNET_REJECT_UNSECURED

// Telnet�T�[�o�[�ւ̃��O�C���ɕK�v�ȃf�t�H���g�̃��[�U�[���ƃp�X���[�h�B
#define TELNET_USERNAME         "admin"
#define TELNET_PASSWORD         "microchip"

#endif /* __TCPIP_CONFIG_H_ */
