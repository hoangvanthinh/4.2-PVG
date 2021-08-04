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
#ifndef XC_HEADER_PV_H
#define	XC_HEADER_PV_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include "Inverter/0_Inverter.h"
#include "Panels/0_panels.h"
#include "Str_combiner/0_str_combiner.h"
#include "Weather/Weather.h"



// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations
enum DEVICE_TYPE
{
    INVERTER = 0,
    PANEL,
    STR_COMBINER,
    CONTROL_IO,
    WEATHER_STATION
};
typedef struct
{
    uint8_t Control_State;
    uint8_t Dev_Type;
    char Modbus_Type;
}CONTROL_INFOR;

extern __eds__ __attribute ((eds))uint16_t RTU_Buffer[MAX_DEVICE+2][500];
extern __eds__ __attribute ((eds))uint16_t TCP_Buffer[MAX_DEVICE+2][500];

extern CONTROL_INFOR gCtrlInfor;
extern DEVICE_CTRL_INFOR gCtrlSetup;
extern DEVICE_CTRL_INFOR gCtrlResponse;
// Comment a function and leverage automatic documentation with slash star star
void Device_RTU_Init(void);
void Device_TCP_Init(void);

uint8_t Device_GetData(uint8_t index,char type);

void Device_CtrlStrToBuffer(void);

void Device_ResponseCtrl(void);

void Display_PV_paramenters(void);

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

