#include "../../SES.h"
#include "2_Deye.h"
#include "3_Sma.h"

//__eds__ __attribute ((eds))
__eds__ __attribute ((eds))INVERTER_DATA InvData_RTU[MAX_INVERTER_RS485];
__eds__ __attribute ((eds))INVERTER_DATA InvData_TCP[MAX_INVERTER_TCP];
__eds__ __attribute ((eds))INVERTER_CONTROL InvCtrl_RTU;
__eds__ __attribute ((eds))INVERTER_CONTROL InvCtrl_TCP;

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
        default:
            break;
    }
}

void Inverter_RTU_GetData(uint8_t index)
{
    static uint8_t I_Inv_rtu = 0;
    InvData_RTU[I_Inv_rtu].SID = G42.Dev_rtu[index].Dev_Setup.SID;
    InvData_RTU[I_Inv_rtu].Type_Dev = G42.Dev_rtu[index].Dev_Setup.Dev_type;
    InvData_RTU[I_Inv_rtu].Series = G42.Dev_rtu[index].Dev_Setup.Series;
    switch(G42.Dev_rtu[index].Dev_Setup.Series)
    {
        case SG110CX:
            SG110CX_GetData(index, I_Inv_rtu, MODBUS_RTU);
            break;
        case SUN6KG03:
            SUN6KG03_GetData(index, I_Inv_rtu, MODBUS_RTU);
            break;
        default:
            break;
    }
    I_Inv_rtu++;
    if(I_Inv_rtu >= G42.Num_inverter_rtu)
    {
        I_Inv_rtu=0;
    }
}

void Inverter_TCP_GetData(uint8_t index)
{
    static uint8_t I_Inv_tcp = 0;
    InvData_TCP[I_Inv_tcp].SID = G42.Dev_rtu[index].Dev_Setup.SID;
    InvData_RTU[I_Inv_tcp].Type_Dev = G42.Dev_rtu[index].Dev_Setup.Dev_type;
    InvData_RTU[I_Inv_tcp].Series = G42.Dev_rtu[index].Dev_Setup.Series;
    switch(G42.Dev_tcp[index].Dev_Setup.Series)
    {
        case SG110CX:
            SG110CX_GetData(index, I_Inv_tcp, MODBUS_TCP);
            break;
        case SUN6KG03:
            SUN6KG03_GetData(index, I_Inv_tcp, MODBUS_TCP);
        default:
            break;
    }
    I_Inv_tcp++;
    if(I_Inv_tcp >= G42.Num_inverter_tcp)
    {
        I_Inv_tcp=0;
    }
}

void Inverter_RTU_CtrlStrToBuffer(void)
{
    switch(InvCtrl_RTU.Series)
    {
        case SG110CX:
            break;
        case SUN6KG03:
            break;
        case STP50:
            STP50_CtrlSetup(MODBUS_RTU);
            break;
        default :
            break;
    }
}

void Inverter_TCP_CtrlStrToBuffer(void)
{
    switch(InvCtrl_TCP.Series)
    {
        case SG110CX:
            break;
        case SUN6KG03:
            break;
        case STP50:
            STP50_CtrlSetup(MODBUS_RTU);
            break;
        default :
            break;
    }
}

void Inverter_RTU_ResponseCtrl(void)
{
    switch(InvCtrl_RTU.Series)
    {
        case SG110CX:
            break;
        case SUN6KG03:
            break;
        case STP50:
            STP50_RTU_ResponseCtrl(MODBUS_RTU);
            break;
        default:
            break;
    }
}