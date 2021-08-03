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
#include "../../SES.h"
#include "1_SunGrow.h"
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


enum INVERTER_NAME
{
    SG110CX = 0,
    SUN6KG03,
    STP50
};

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
    HW_TEST_FAILURE
};

enum PVCONN
{
    PV_CONNECTED = 0,
    PV_AVAILABLE,
    PV_IN_OPERATION
};

enum ECPCONN
{
    ECP_DISCONNECTED = 0,
    ECP_CONNECTED
};

enum DC_EVENT
{
    INPUT_UNDER_VOLTAGE,
    INPUT_OVER_CURRENT
};

enum CONN
{
    DISCONNECT = 0,
    CONNECT
};
typedef struct
{
    UINT16 VAB;
    UINT16 VBC;
    UINT16 VCA;
    
    UINT16 AN;
    UINT16 BN;
    UINT16 CN;
    INT16 V_SF;
    
    UINT16 IA;
    UINT16 IB;
    UINT16 IC;
    INT16 A_SF;
    
    
    INT16 PF;
    INT16 PF_SF;
    
    INT16  P,Q,S;
    INT16 W_SF,VAr_SF,VA_SF;
    
    UINT16 F;
    INT16 Hz_SF;
    
    UINT64 EP, EQ, ES;
    
}AC_Electric;

typedef struct
{
    UINT16 ID;      //Input ID
    UINT16 IDStr[8];  //Input ID string
    UINT16 DCA;
    UINT16 DCV;
    UINT16 DCW;
    UINT32 DCWH;
    UINT16 DCEvt;
}MPPT_MODULE;;

typedef struct
{
    UINT16 I_DC, U_DC, P_DC;
    INT16 DCA_SF,DCV_SF,DCW_SF;
    UINT16 N;
    MPPT_MODULE Mppt_module[MAX_MODULE];
}DC_Electric;

typedef struct
{
    INT16 T_Cabinet;
    INT16 T_Heat_Sink;
    INT16 T_Tranformer;
    INT16 Tmp_SF;
}TEMPERATURE_INVERTER;

typedef struct
{
    UINT16 SID;
    UINT8  Type_Dev;
    UINT8  Series;
    UINT16 Operating_State;
    UINT16 Event;
    UINT16 PV_connect;
    UINT16 ECP_connect;
    AC_Electric AC;
    DC_Electric DC;
    TEMPERATURE_INVERTER T;
}INVERTER_DATA;

typedef struct
{
    UINT16 VRef;
    INT16 VRef_SF;
} VOLTAGE_CONTROL;

typedef struct
{
    UINT16 WMax;
    //INT16 WMax_SF;
    
    UINT16 WMaxLimPct ; //Unit: %WMax
    //INT16 WMaxLimPct_SF;
    UINT16 WMaxLimPct_WinTms;
    UINT16 WMaxLimPct_RvrtTms;
    UINT16 WMaxLimPct_RmpTms;
    UINT16 WMaxLim_Ena;
} P_CONTROL;


typedef struct
{
    INT16 VArMaxQ1;
    INT16 VArMaxQ2;
    INT16 VArMaxQ3;
    INT16 VArMaxQ4;
    //INT16 VArMax_SF;
    
    INT16 VArWMaxPct;
    INT16 VArMaxPct;
    INT16 VArAvalPct;
    //INT16 VArPct_SF;
    
    UINT16 VArPct_WinTms;
    UINT16 VArPct_RvrtTms;
    UINT16 VArPct_RmpTms;
    
    UINT16 VArPct_Mod;
    UINT16 VArPct_Ena;
}Q_CONTROL;

typedef struct
{
    INT16 OutPFSet;
    //INT16 OutPFSet_SF;
    
    UINT16 OutPFSet_WinTms;
    UINT16 OutPFSet_RvrtTms;
    UINT16 OutPFSet_RmpTms;
    
    UINT16 OutPFSet_Ena;
}PF_CONTRL;

typedef struct
{
    UINT16 SID;
    UINT8 Series;
    UINT16  Connection_Control;
    VOLTAGE_CONTROL V;
    P_CONTROL P;
    UINT16 VAMAX;
    Q_CONTROL Q;
    UINT16 ECPNomHz;
    PF_CONTRL PF;
}INVERTER_CONTROL;

extern __eds__ __attribute ((eds))INVERTER_DATA InvData_RTU[MAX_INVERTER_RS485];
extern __eds__ __attribute ((eds))INVERTER_DATA InvData_TCP[MAX_INVERTER_TCP];
extern __eds__ __attribute ((eds))INVERTER_CONTROL InvCtrl_RTU;
extern __eds__ __attribute ((eds))INVERTER_CONTROL InvCtrl_TCP;

void Inverter_RTU_Init(uint8_t index);
void Inverter_TCP_Init(uint8_t index);

void Inverter_RTU_GetData(uint8_t index);
void Inverter_TCP_GetData(uint8_t index);

void Inverter_RTU_CtrlStrToBuffer(void);
void Inverter_RTU_ResponseCtrl(void);

void Inverter_TCP_CtrlStrToBuffer(void);
void Inverter_TCP_ResponseCtrl(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

