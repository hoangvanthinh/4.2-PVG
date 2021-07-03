/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_MAIN_H
#define	XC_MAIN_H

#define FCY _XTAL_FREQ/2

#include <xc.h> // include processor files - each processor file is guarded.  
#include <libpic30.h>
#include <stdio.h>
#include <string.h>
//#include <math.h>
// TODO Insert appropriate #include <>
#include "mcc_generated_files/mcc.h"

#include "Framework/tcpip/tcpip.h"
#include "Framework/sysconf_inc/system_inc.h"
#include "Framework/sysconf_inc/system_config.h"
#include "Framework/sysconf_inc/tcpip_config.h"
#include "Sstype.h"

#include "Modbus/ModbusRTU.h"
#include "Modbus/ModbusTCPIP.h"
#include "Modbus/ModbusTCPIP_Client.h"
//#include "Modbus/ModbusTCPIP_Server.h"
#include "Modbus/ModbusRTU_Slave.h"
#include "Modbus/ModbusRTU_Master.h"

#include "mcc_generated_files/EEPROM3_example.h"
#include "mcc_generated_files/EEPROM3_driver.h"
#include "User.h"
#include "PV/PV.h"





#define bool	_Bool
#define true	1
#define false	0


#define MY_name_INTERFACE_L  1
#define SD_GATEWAY_L    2

#define IT_Connected    1
#define IT_Disconnected 0

#define LS_Connected    1
#define LS_Disconnected 0

#define CLS_Connected    1
#define CLS_Disconnected 0

#define LocalSID 51
#define CloudSID 52

typedef signed char int8_t;
typedef unsigned char   uint8_t;
typedef int  int16_t;
typedef unsigned int  uint16_t;
typedef long  int32_t;
typedef unsigned  long uint32_t;

typedef unsigned char byte;
typedef byte cs_byte;
typedef unsigned char boolean;
// TODO Insert C++ class definitions if appropriate

#define  millis() Get_millis()
//#define __delay_ms(a)   DELAY_milliseconds(a)
//#define __delay_us(a)   DELAY_microseconds(a)

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))
#define word(h, l) (l & 0xff) | ((h & 0xff) << 8)

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

#define NOP() Nop()


// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

