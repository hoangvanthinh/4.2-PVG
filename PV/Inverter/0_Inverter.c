#include "../../SES.h"

//__eds__ __attribute ((eds))
__eds__ __attribute ((eds))INVERTER_DATA InvData[MAX_INVERTER];
__eds__ __attribute ((eds))INVERTER_CONTROL InvCtrl;

void Inverter_RTU_Init(uint8_t index)
{
    
    switch(G42.Dev_rtu[index].Dev_Setup.Series)
    {
        case SG110CX:
            SG110CX_Initialization(&(G42.Dev_rtu[index].Dev_Setup));
            break;
        case SUN6KG03:
            SUN6KG03_Initialization(&(G42.Dev_rtu[index].Dev_Setup));
            break;
        case STP50:
            STP50_Initialization(&(G42.Dev_rtu[index].Dev_Setup));
            break;
        default:
            break;
    }
    
}

void Inverter_TCP_Init(uint8_t index)
{
    switch(G42.Dev_tcp[index].Dev_Setup.Series)
    {
        case SG110CX:          
            SG110CX_Initialization(&(G42.Dev_tcp[index].Dev_Setup));
            break;
        case SUN6KG03:
            SUN6KG03_Initialization(&(G42.Dev_tcp[index].Dev_Setup));
            break;
        case STP50:
            STP50_Initialization(&(G42.Dev_tcp[index].Dev_Setup));
        default:
            break;
    }
}

uint8_t Inverter_GetData(uint8_t index, char type)
{
    static uint8_t I_Inv = 0;
    if(type = MODBUS_RTU)
    {
        InvData[I_Inv].SID = G42.Dev_rtu[index].Dev_Setup.SID;
        InvData[I_Inv].Series = G42.Dev_rtu[index].Dev_Setup.Series;
        InvData[I_Inv].Modbus_Type = MODBUS_RTU;
    }
    else if(type = MODBUS_TCP)
    {
        InvData[I_Inv].SID = G42.Dev_tcp[index].Dev_Setup.SID;
        InvData[I_Inv].Series = G42.Dev_tcp[index].Dev_Setup.Series;
        InvData[I_Inv].Modbus_Type = MODBUS_TCP;
    }
    else
    {
        return 0;
    }
    switch(InvData[I_Inv].Series)
    {
        case SG110CX:
            SG110CX_GetData(index, I_Inv, MODBUS_RTU);
            break;
        case SUN6KG03:
            SUN6KG03_GetData(index, I_Inv, MODBUS_RTU);
            break;
        case STP50:
            STP50_GetData(index, I_Inv, MODBUS_RTU);
            break;
        default:
            break;
    }
    I_Inv++;
    if(I_Inv >= G42.Num_inverter)
    {
        I_Inv=0;
    }
    return 1;
}

void Inverter_CtrlStrToBuffer(char Modbus_type)
{
    switch(InvCtrl.Series)
    {
        case SG110CX:
            SG110CX_CtrlSetup(Modbus_type);
            break;
        case SUN6KG03:
            SUN6KG03_CtrlSetup(Modbus_type);
            break;
        case STP50:
            STP50_CtrlSetup(Modbus_type);
            break;
        default :
            break;
    }
}


void Inverter_ResponseCtrl(char Modbus_type)
{
    switch(InvCtrl.Series)
    {
        case SG110CX:
            SG110CX_ResponseCtrl(Modbus_type);
            break;
        case SUN6KG03:
            SUN6KG03_ResponseCtrl(Modbus_type);
            break;
        case STP50:
            STP50_ResponseCtrl(Modbus_type);
            break;
        default:
            break;
    }
}