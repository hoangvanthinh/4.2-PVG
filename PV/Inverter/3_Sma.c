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
    uint8_t i = 0, j = 0;
    __eds__ uint16_t *Buffer;
    __eds__ INVERTER_CONTROL *inv_ctrl;
    if (type == MODBUS_RTU)
    {
        while (i < G42.Num_Dev_rtu && G42.Dev_rtu[i].Dev_Setup.SID != InvCtrl.SID)
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
    }
    else if (type == MODBUS_TCP)
    {
        while (j < G42.Num_Dev_tcp && G42.Dev_tcp[j].Dev_Setup.SID != InvCtrl.SID)
        {
            j++;
        }
        if(i >= G42.Num_Dev_tcp)
        {
            printf("\nSetup control parameters error!\n");
            return 0;
        }
        gCtrlSetup.IP = MAKE_IPV4_ADDRESS(G42.Dev_tcp[j].IP[0],G42.Dev_tcp[j].IP[1],G42.Dev_tcp[j].IP[2],G42.Dev_tcp[j].IP[3]);
        gCtrlResponse.IP = gCtrlSetup.IP;
        Buffer = TCP_Buffer[MAX_DEVICE];
    }
    else
    {
        return 0;
    }
    inv_ctrl = &InvCtrl;
    
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

uint8_t STP50_GetData(uint8_t index, uint8_t inv_index, char type)
{
    __eds__ INVERTER_DATA *inv_data;
    __eds__ uint16_t *Buffer;
    if(type == MODBUS_RTU)
    {
        Buffer = RTU_Buffer[index];
    }
    else if(type == MODBUS_TCP)
    {
        Buffer = TCP_Buffer[index];
    }
    else
    {
        return 0;
    }
    inv_data = &(InvData[inv_index]);
    if (type == MODBUS_RTU || type == MODBUS_TCP)
    {
        //AC
        
//        (*inv_data).AC.VBC = Buffer[71];
//        (*inv_data).AC.VCA = Buffer[72];
//        (*inv_data).AC.VAB = Buffer[70];
        (*inv_data).AC.AN = Buffer[95];
        (*inv_data).AC.BN = Buffer[96];
        (*inv_data).AC.CN = Buffer[97];
        (*inv_data).AC.V_SF = Buffer[98];
        
        (*inv_data).AC.IA = Buffer[88];
        (*inv_data).AC.IB = Buffer[89];
        (*inv_data).AC.IC = Buffer[90];
        (*inv_data).AC.A_SF = Buffer[91];
        
        (*inv_data).AC.PF = Buffer[107];
        (*inv_data).AC.PF_SF = Buffer[108];
        
        (*inv_data).AC.F = Buffer[101];
        (*inv_data).AC.Hz_SF = Buffer[102];
        
        (*inv_data).AC.P = Buffer[99];
        (*inv_data).AC.W_SF = Buffer[100];
        
//        (*inv_data).AC.Q = (INT16)((uint32_t)(convert16to32(Buffer[89],Buffer[88])));
//        (*inv_data).AC.VAr_SF = -1;
        
        (*inv_data).AC.S = Buffer[103];
        (*inv_data).AC.VA_SF = Buffer[104];
        
        (*inv_data).AC.EP = (uint64_t)(convert16to64(Buffer[205],Buffer[204],Buffer[203],Buffer[202]));
        //(*inv_data).AC.EQ = (uint64_t)(convert16to32(Buffer[66],Buffer[65])*100);
        //DC
        (*inv_data).DC.N = Buffer[229];
        
        (*inv_data).DC.Mppt_module[0].ID = Buffer[231];
        (*inv_data).DC.Mppt_module[0].DCA = Buffer[240];
        (*inv_data).DC.Mppt_module[0].DCV = Buffer[241];
        (*inv_data).DC.Mppt_module[0].DCW = Buffer[242];
        
        (*inv_data).DC.Mppt_module[1].ID = Buffer[251];
        (*inv_data).DC.Mppt_module[1].DCA = Buffer[260];
        (*inv_data).DC.Mppt_module[1].DCV = Buffer[261];
        (*inv_data).DC.Mppt_module[1].DCW = Buffer[262];

        (*inv_data).DC.Mppt_module[2].ID = Buffer[271];
        (*inv_data).DC.Mppt_module[2].DCA = Buffer[280];
        (*inv_data).DC.Mppt_module[2].DCV = Buffer[281];
        (*inv_data).DC.Mppt_module[2].DCW = Buffer[282];
        
        (*inv_data).DC.Mppt_module[3].ID = Buffer[291];
        (*inv_data).DC.Mppt_module[3].DCA = Buffer[300];
        (*inv_data).DC.Mppt_module[3].DCV = Buffer[301];
        (*inv_data).DC.Mppt_module[3].DCW = Buffer[302];
        
        (*inv_data).DC.Mppt_module[4].ID = Buffer[311];
        (*inv_data).DC.Mppt_module[4].DCA = Buffer[320];
        (*inv_data).DC.Mppt_module[4].DCV = Buffer[321];
        (*inv_data).DC.Mppt_module[4].DCW = Buffer[322];
        
        (*inv_data).DC.Mppt_module[5].ID = Buffer[331];
        (*inv_data).DC.Mppt_module[5].DCA = Buffer[340];
        (*inv_data).DC.Mppt_module[5].DCV = Buffer[340];
        (*inv_data).DC.Mppt_module[5].DCW = Buffer[342];
        
        (*inv_data).DC.DCA_SF = Buffer[223];
        (*inv_data).DC.DCV_SF = Buffer[224];
        (*inv_data).DC.DCW_SF = Buffer[225];
        
        //Event
        (*inv_data).Event = Buffer[125];
        
        //Operating State
        (*inv_data).Operating_State = Buffer[123];
        
        //Temperature
        (*inv_data).T.T_Cabinet = Buffer[118];
        (*inv_data).T.Tmp_SF = Buffer[122];
        
        (*inv_data).PV_connect = Buffer[199];
        (*inv_data).ECP_connect = Buffer[201];
        
    }
    return 1;
}

uint8_t STP50_ResponseCtrl(char type)
{
    __eds__ INVERTER_CONTROL *inv_ctrl;
    __eds__ uint16_t *Buffer;
    if (type == MODBUS_RTU)
    {
        Buffer = RTU_Buffer[MAX_DEVICE+1];
    }
    else if(type == MODBUS_TCP)
    {
        Buffer = TCP_Buffer[MAX_DEVICE+1];
    }
    else
    {
        return 0;
    }
    inv_ctrl = &InvCtrl;
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



