#include "../../SES.h"

//__eds__ __attribute ((eds))
__eds__ __attribute ((eds))INVERTER_DATA InvData_RTU[MAX_INVERTER_RS485];
__eds__ __attribute ((eds))INVERTER_DATA InvData_TCP[MAX_INVERTER_TCP];


void Inverter_RTU_Init(uint8_t index)
{
    switch(G42.Dev_rtu[index].Dev_Setup.Series)
    {
        case SG110CX:
            SG110CX_Initialization(&(G42.Dev_rtu[index].Dev_Setup));
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
        default:
            break;
    }
}

void Inverter_RTU_GetData(uint8_t index)
{
    static uint8_t I_Inv = 0;
    switch(G42.Dev_rtu[index].Dev_Setup.Series)
    {
        case SG110CX:
            SG110CX_GetData(index, I_Inv, MODBUS_RTU);
            break;
        default:
            break;
    }
    I_Inv++;
    if(I_Inv >= G42.Num_inverter_rtu)
    {
        I_Inv=0;
    }
}