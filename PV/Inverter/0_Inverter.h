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
#ifndef XC_HEADER_INVERTER_H
#define	XC_HEADER_INVERTER_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

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
enum INVETER_OPERATING_STATE
{
    OFF = 1,
    SLEEPING,
    STARTING,
    MPPT,
    THROTTLE,
    SHUTTING_DOWN,
    FAULT,
    STANDBY
  
};
enum INVERTER_EVENT
{
    GROUND_FAULT = 0,
    DC_OVER_VOLT,
    AC_DISCONNECT,
    DC_DISCONNECT,
    GRID_DISCONNECT,
    CABINET_OPEN,
    MANUAL_SHUTDOWN,
    OVER_TEMP,
    OVER_FREQUENCY,
    UNDER_FREQUENCY,
    AC_OVER_VOLT,
    AC_UNDER_VOLT,
    BLOWN_STRING_FUSE,
    UNDER_TEMP,
    MEMORY_LOSS,
    HW_TEST_FAILURE,
  
};
typedef struct
{
    UINT16 VAB;
    UINT16 VBC;
    UINT16 VCA;
    
    UINT16 AN;
    UINT16 BN;
    UINT16 CN;
    
    UINT16 IA;
    UINT16 IB;
    UINT16 IC;
    
    
    INT16 PF;
    INT16  P,Q,S;
    UINT16 F;
    UINT64 EP, EQ, ES;
      
}AC_Electric;


typedef struct
{
    UINT16 I_DC, U_DC, P_DC;
}DC_Electric;



typedef struct
{
    INT16 T_Cabinet;
    INT16 T_Heat_Sink;
    INT16 T_Tranformer;
}TEMPERATURE_INVERTER;


typedef struct
{
    char Operating_State;
    char Event;
    AC_Electric AC;
    DC_Electric DC;
    TEMPERATURE_INVERTER T;

}INVERTER_DATA;



#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

