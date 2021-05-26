/*******************************************************************************
  Company:
    Microchip Technology Inc.

  File Name:
    system_config.h

  Summary:
    PIC24EP256MC202 - ENC28J60 用の定義ファイル

  Description:
    システム固有の定義

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
*   2017-05-29 きむ茶工房(きむしげ) PIC24EP256MC202-ENC28J60用に書き換え         *
*
 *******************************************************************************/
//DOM-IGNORE-END

#ifndef __SYSTEM_CONFIG_H_
#define __SYSTEM_CONFIG_H_

#include <stdio.h>
#include <string.h>
#include <p33EP512MU810.h>
#include "system_inc.h"

#include "tcpip_config.h"

// Define a macro describing this hardware set up (used in other files)
//#define PIC18_EXPLORER

// ハードウェアI / Oピンのマッピング
//------------------------------------------------------------------------------

// LEDs
//#define LED0_TRIS           (TRISDbits.TRISD0)  // Ref D1
#define LED0_IO             (LATEbits.LATE7)
//#define LED1_TRIS           (TRISDbits.TRISD1)  // Ref D2
#define LED1_IO             (LATEbits.LATE7)
//#define LED2_TRIS           (TRISDbits.TRISD2)  // Ref D3
//#define LED2_IO             (LATDbits.LATD2)
//#define LED3_TRIS           (TRISDbits.TRISD3)  // Ref D4
//#define LED3_IO             (LATDbits.LATD3)
//#define LED4_TRIS           (TRISDbits.TRISD4)  // Ref D5
//#define LED4_IO             (LATDbits.LATD4)
//#define LED5_TRIS           (TRISDbits.TRISD5)  // Ref D6
//#define LED5_IO             (LATDbits.LATD5)
//#define LED6_TRIS           (TRISDbits.TRISD6)  // Ref D7
//#define LED6_IO             (LATDbits.LATD6)
//#define LED7_TRIS           (TRISDbits.TRISD7)  // Ref D8
//#define LED7_IO             (LATDbits.LATD7)
//#define LED_GET()           (LATD)
//#define LED_PUT(a)          (LATD = (a))

// Momentary push buttons
//#define BUTTON0_TRIS        (TRISAbits.TRISA5)
//#define BUTTON0_IO          (PORTAbits.RA1)
//#define BUTTON1_TRIS        (TRISBbits.TRISB0)
//#define BUTTON1_IO          (PORTBbits.RB0)
//#define BUTTON2_TRIS        (TRISBbits.TRISB0)  // No Button2 on this board
//#define BUTTON2_IO          (1u)
//#define BUTTON3_TRIS        (TRISBbits.TRISB0)  // No Button3 on this board
//#define BUTTON3_IO          (1u)

// ENC28J60 I/O pins FOR 810
//#define ENC_RST_TRIS		(TRISDbits.TRISD6)
//#define ENC_RST_IO			(LATDbits.LATD6)
//
//#define ENC_CS_TRIS			(TRISDbits.TRISD4)
//#define ENC_CS_IO			(LATDbits.LATD4)
//
//#define ENC_SCK_TRIS		(TRISDbits.TRISD5)
//
//#define ENC_SDI_TRIS		(TRISCbits.TRISC14)
//
//#define ENC_SDO_TRIS		(TRISDbits.TRISD7)
//==================================================================

#define ENC_RST_TRIS		(TRISEbits.TRISE9)
#define ENC_RST_IO			(LATEbits.LATE9)

#define ENC_CS_TRIS			(TRISFbits.TRISF12)
#define ENC_CS_IO			(LATFbits.LATF12)

#define ENC_SCK_TRIS		(TRISDbits.TRISD2)

#define ENC_SDI_TRIS		(TRISEbits.TRISE8)

#define ENC_SDO_TRIS		(TRISDbits.TRISD3)

#define ENC_SPI_IF			(_SPI1IF)
#define ENC_SSPBUF			(SPI1BUF)
#define ENC_SPISTAT			(SPI1STAT)
#define ENC_SPISTATbits		(SPI1STATbits)
#define ENC_SPICON1			(SPI1CON1)
#define ENC_SPICON1bits		(SPI1CON1bits)
#define ENC_SPICON2			(SPI1CON2)

// MRF24W I/O pins0
//#define WF_CS_TRIS          (TRISCbits.TRISC2)
//#define WF_SDI_TRIS         (TRISCbits.TRISC4)
//#define WF_SCK_TRIS         (TRISCbits.TRISC3)
//#define WF_SDO_TRIS         (TRISCbits.TRISC5)
//#define WF_RESET_TRIS       (TRISBbits.TRISB1)
//#define WF_RESET_IO         (LATBbits.LATB1)
//#define WF_INT_TRIS         (TRISBbits.TRISB0)
//#define WF_INT_IO           (PORTBbits.RB0)
//#define WF_CS_IO            (LATCbits.LATC2)
//#define WF_HIBERNATE_TRIS   (TRISBbits.TRISB2)
//#define WF_HIBERNATE_IO     (PORTBbits.RB2)
//#define WF_INT_EDGE         (INTCON2bits.INTEDG0)
//#define WF_INT_IE           (INTCONbits.INT0IE)
//#define WF_INT_IF           (INTCONbits.INT0IF)
//#define WF_SPI_IF           (PIR1bits.SSPIF)
//#define WF_SSPBUF           (SSP1BUF)
//#define WF_SPISTAT          (SSP1STAT)
//#define WF_SPISTATbits      (SSP1STATbits)
//#define WF_SPICON1          (SSP1CON1)
//#define WF_SPICON1bits      (SSP1CON1bits)
//#define WF_SPICON2          (SSP1CON2)
//#define WF_SPI_IE           (PIE1bits.SSPIE)
//#define WF_SPI_IP           (IPR1bits.SSPIP)

// 25LC256 I/O pins
//#define EEPROM_CS_TRIS      (TRISAbits.TRISA3)
//#define EEPROM_CS_IO        (LATAbits.LATA3)
//#define EEPROM_SCK_TRIS     (TRISCbits.TRISC3)
//#define EEPROM_SDI_TRIS     (TRISCbits.TRISC4)
//#define EEPROM_SDO_TRIS     (TRISCbits.TRISC5)
//#define EEPROM_SPI_IF       (PIR1bits.SSP1IF)
//#define EEPROM_SSPBUF       (SSP1BUF)
//#define EEPROM_SPICON1      (SSP1CON1)
//#define EEPROM_SPICON1bits  (SSP1CON1bits)
//#define EEPROM_SPICON2      (SSP1CON2)
//#define EEPROM_SPISTAT      (SSP1STAT)
//#define EEPROM_SPISTATbits  (SSP1STATbits)

// 使用するプロセッサ用にレジスタ名を修正する
//#define SPBRGH    SPBRGH1     // USART1
//#define ADCON2    ADCON1

// LCD DEFINITIONS
// Following definitions are used for LCD display on the demo board
// "LCD_DATA0_IO"が有効になればLCD表示関連ルーチンが利用可能な様である。
//#define LCD_DATA0_TRIS		(TRISEbits.TRISE0)		// Multiplexed with LED6
//#define LCD_DATA0_IO		(LATEbits.LATE0)
//#define LCD_DATA1_TRIS		(TRISEbits.TRISE1)
//#define LCD_DATA1_IO		(LATEbits.LATE1)
//#define LCD_DATA2_TRIS		(TRISEbits.TRISE2)
//#define LCD_DATA2_IO		(LATEbits.LATE2)
//#define LCD_DATA3_TRIS		(TRISEbits.TRISE3)		// Multiplexed with LED3
//#define LCD_DATA3_IO		(LATEbits.LATE3)
//#define LCD_DATA4_TRIS		(TRISEbits.TRISE4)		// Multiplexed with LED2
//#define LCD_DATA4_IO		(LATEbits.LATE4)
//#define LCD_DATA5_TRIS		(TRISEbits.TRISE5)
//#define LCD_DATA5_IO		(LATEbits.LATE5)
//#define LCD_DATA6_TRIS		(TRISEbits.TRISE6)
//#define LCD_DATA6_IO		(LATEbits.LATE6)
//#define LCD_DATA7_TRIS		(TRISEbits.TRISE7)
//#define LCD_DATA7_IO		(LATEbits.LATE7)
//#define LCD_RD_WR_TRIS		(TRISDbits.TRISD5)
//#define LCD_RD_WR_IO		(LATDbits.LATD5)
//#define LCD_RS_TRIS             (TRISBbits.TRISB15)
//#define LCD_RS_IO		(LATBbits.LATB15)
//#define LCD_E_TRIS		(TRISDbits.TRISD4)
//#define LCD_E_IO		(LATDbits.LATD4)

// 8ビットおよび16ビットまたは32ビットコンパイラ間で一貫性のあるAPI名用のUARTマッピング関数。
// 簡単にするため、すべてがUSART / EUSART /などの代わりに "UART"を使用します。
//#define BusyUART()          BusyUSART()
//#define CloseUART()         CloseUSART()
//#define ConfigIntUART(a)    ConfigIntUSART(a)
//#define DataRdyUART()       DataRdyUSART()
//#define OpenUART(a,b,c)     OpenUSART(a,b,c)
//#define ReadUART()          ReadUSART()
//#define WriteUART(a)        WriteUSART(a)
//#define getsUART(a,b,c)     getsUSART(b,a)
//#define putsUART(a)         putsUSART(a)
//#define getcUART()          ReadUSART()
//#define putcUART(a)         WriteUSART(a)
//#define putrsUART(a)        putrsUSART((far rom char *)a)

//------------------------------------------------------------------------------
// End of /* ハードウェアI / Oピンのマッピング */


// コンパイラ情報
//------------------------------------------------------------------------------

// Include proper device header file
#include <xc.h>

// 指定されたアーキテクチャのベースRAMとROMのポインタ型
#define PTR_BASE        unsigned short
#define ROM_PTR_BASE    unsigned short

// C18用の定義をXC用に適用される
#define memcmppgm2ram(a,b,c)    memcmp(a,b,c)
#define strcmppgm2ram(a,b)      strcmp(a,b)
#define memcpypgm2ram(a,b,c)    memcpy(a,b,c)
#define strcpypgm2ram(a,b)      strcpy(a,b)
#define strncpypgm2ram(a,b,c)   strncpy(a,b,c)
#define strstrrampgm(a,b)       strstr(a,b)
#define strlenpgm(a)            strlen(a)
#define strchrpgm(a,b)          strchr(a,b)
#define strcatpgm2ram(a,b)      strcat(a,b)

// コンパイラ固有の定義
//#define __attribute__(a)
#define FAR    __attribute__((far))
#define ROM    const
//#define rom
#define Reset()    asm("reset")

//------------------------------------------------------------------------------
// End of /* コンパイラ情報 */

#endif /* __SYSTEM_CONFIG_H_ */
