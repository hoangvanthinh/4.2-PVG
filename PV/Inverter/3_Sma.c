/*
 * File:   3_Sma.c
 * Author: Chien Tran
 *
 * Created on July 29, 2021, 12:00 AM
 */


#include "../../SES.h"

void STP50_Initialization(DEVICE_INFOR *Inv)
{
    (*Inv).Func = MB_FC_READ_HOLD_REGISTERS;
    (*Inv).NumFr = 4;
    (*Inv).Fr[0].u16RegAdd = 40187;
    (*Inv).Fr[0].u16CoilsNo = 48;
    (*Inv).Fr[0].pointer = 87;
    
    (*Inv).Fr[1].u16RegAdd = 40299;
    (*Inv).Fr[1].u16CoilsNo = 4;
    (*Inv).Fr[1].pointer = 199;
    
    (*Inv).Fr[2].u16RegAdd = 40629;
    (*Inv).Fr[2].u16CoilsNo = 63;
    (*Inv).Fr[2].pointer = 229;
    
    (*Inv).Fr[3].u16RegAdd = 40700;
    (*Inv).Fr[3].u16CoilsNo = 43;
    (*Inv).Fr[3].pointer = 300;
}

uint8_t STP50_CtrlSetup(char type)
{
    uint8_t i = 0;
    __eds__ uint16_t *Buffer;
    __eds__ INVERTER_CONTROL *inv_ctrl;
    if (type == MODBUS_RTU)
    {
        while (i < G42.Num_Dev_rtu && G42.Dev_rtu[i].Dev_Setup.SID != InvCtrl_RTU.SID)
        {
            i++;
        }
        if(i >= G42.Num_Dev_rtu)
        {
            printf("\nSetup control parameters error!\n");
            return 0;
        }
        gCtrlSetup.UID = G42.Dev_rtu[i].Dev_Setup.UID;
        gCtrlResponse.UID = G42.Dev_rtu[i].Dev_Setup.UID;
        Buffer = RTU_Buffer[MAX_DEVICE];
        inv_ctrl = &(InvCtrl_RTU);
    }
    else if (type == MODBUS_TCP)
    {
        Buffer = TCP_Buffer[MAX_DEVICE];
        inv_ctrl = &(InvCtrl_TCP);
    }
    
    gCtrlSetup.Func = MB_FC_WRITE_MULTIPLE_REGISTERS;
    gCtrlSetup.NumFr = 5;
    
    gCtrlSetup.Fr[0].u16RegAdd = 40267;
    gCtrlSetup.Fr[0].u16CoilsNo = 2;
    gCtrlSetup.Fr[0].pointer = 67;
    
    gCtrlSetup.Fr[1].u16RegAdd = 40285;
    gCtrlSetup.Fr[1].u16CoilsNo = 1;
    gCtrlSetup.Fr[1].pointer = 85;
    
    gCtrlSetup.Fr[2].u16RegAdd = 40347;
    gCtrlSetup.Fr[2].u16CoilsNo = 2;
    gCtrlSetup.Fr[2].pointer = 147;

    gCtrlSetup.Fr[3].u16RegAdd = 40352;
    gCtrlSetup.Fr[3].u16CoilsNo = 1;
    gCtrlSetup.Fr[3].pointer = 152;
    
    gCtrlSetup.Fr[4].u16RegAdd = 40358;
    gCtrlSetup.Fr[4].u16CoilsNo = 1;
    gCtrlSetup.Fr[4].pointer = 158;
   
    gCtrlSetup.Fr[4].u16RegAdd = 40364;
    gCtrlSetup.Fr[4].u16CoilsNo = 1;
    gCtrlSetup.Fr[4].pointer = 164;
    
    Buffer[67] = (*inv_ctrl).P.WMax;
    Buffer[68] = (*inv_ctrl).V.VRef;
    Buffer[85] = (*inv_ctrl).ECPNomHz;
    Buffer[147] = (*inv_ctrl).Connection_Control;
    Buffer[148] = (*inv_ctrl).P.WMaxLimPct;
    Buffer[152] = (*inv_ctrl).P.WMaxLim_Ena;
    Buffer[158] = (*inv_ctrl).Q.VArWMaxPct;
    Buffer[164] = (*inv_ctrl).Q.VArPct_Mod;
    
    gCtrlResponse.Func = MB_FC_READ_HOLD_REGISTERS;
    gCtrlResponse.NumFr = 2;
    
    gCtrlResponse.Fr[0].u16RegAdd = 40267;
    gCtrlResponse.Fr[0].u16CoilsNo = 30;
    gCtrlResponse.Fr[0].pointer = 67;
    
    gCtrlResponse.Fr[1].u16RegAdd = 40347;
    gCtrlResponse.Fr[1].u16CoilsNo = 23;
    gCtrlResponse.Fr[1].pointer = 147;
    return 1;
}

void STP50_GetData(uint8_t index, uint8_t inv_index, char type)
{
    __eds__ INVERTER_DATA *inv_data;
    __eds__ uint16_t *Buffer;
    if(type == MODBUS_RTU)
    {
        inv_data = &(InvData_RTU[inv_index]);
        Buffer = RTU_Buffer[index];
    }
    else if(type == MODBUS_TCP)
    {
        inv_data = &(InvData_TCP[inv_index]);
        Buffer = TCP_Buffer[index];
    }
    if (type == MODBUS_RTU || type == MODBUS_TCP)
    {
        //AC
        
        (*inv_data).AC.VBC = Buffer[71];
        (*inv_data).AC.VCA = Buffer[72];
        (*inv_data).AC.VAB = Buffer[70];
        (*inv_data).AC.AN = Buffer[180];
        (*inv_data).AC.BN = Buffer[181];
        (*inv_data).AC.CN = Buffer[182];
        (*inv_data).AC.V_SF = -1;
        
        (*inv_data).AC.IA = Buffer[173];
        (*inv_data).AC.IB = Buffer[174];
        (*inv_data).AC.IC = Buffer[175];
        (*inv_data).AC.A_SF = -1;
        
        (*inv_data).AC.PF = Buffer[93];
        (*inv_data).AC.PF_SF = -3;
        
        (*inv_data).AC.F = Buffer[186];
        (*inv_data).AC.Hz_SF = -2;
        
        (*inv_data).AC.P = Buffer[184];
        (*inv_data).AC.W_SF = 1;
        
        (*inv_data).AC.Q = (INT16)((uint32_t)(convert16to32(Buffer[89],Buffer[88])));
        (*inv_data).AC.VAr_SF = -1;
        
        (*inv_data).AC.S = (INT16)((uint32_t)(convert16to32(Buffer[85],Buffer[84])));
        (*inv_data).AC.VA_SF = -1;
        
        (*inv_data).AC.EP = (uint64_t)(convert16to64(Buffer[290],Buffer[289],Buffer[288],Buffer[287]));
        (*inv_data).AC.EQ = (uint64_t)(convert16to32(Buffer[66],Buffer[65])*100);
        //DC
        (*inv_data).DC.P_DC = Buffer[82];
        (*inv_data).DC.DCW_SF = -1;
        
        //Event
        (*inv_data).Event = (UINT32)(convert16to32(Buffer[211],Buffer[210]));
        
        //Operating State
        (*inv_data).Operating_State = Buffer[208];
        
        //Temperature
        (*inv_data).T.T_Cabinet = Buffer[203];
        (*inv_data).T.T_Heat_Sink = (INT16)(Buffer[90]/10);
        (*inv_data).T.Tmp_SF = 0;
        
    }
    
}

uint8_t STP50_RTU_ResponseCtrl(char type)
{
    __eds__ INVERTER_CONTROL *inv_ctrl;
    __eds__ uint16_t *Buffer;
    if (type == MODBUS_RTU)
    {
        inv_ctrl = &(InvCtrl_RTU);
        Buffer = RTU_Buffer[MAX_DEVICE+1];
    }
    else if(type == MODBUS_TCP)
    {
        inv_ctrl = &(InvCtrl_TCP);
        Buffer = TCP_Buffer[MAX_DEVICE+1];
    }
    else
    {
        return 0;
    }
    (*inv_ctrl).P.WMax = Buffer[67];
    (*inv_ctrl).V.VRef = Buffer[68];
    (*inv_ctrl).ECPNomHz = Buffer[85];
    (*inv_ctrl).Connection_Control = Buffer[147];
    (*inv_ctrl).P.WMaxLimPct = Buffer[148];
    (*inv_ctrl).P.WMaxLim_Ena = Buffer[152];
    (*inv_ctrl).Q.VArWMaxPct = Buffer[158];
    (*inv_ctrl).Q.VArPct_Mod = Buffer[164];
    return 1;
}



