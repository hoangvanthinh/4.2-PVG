#include "../SES.h"

CONTROL_INFOR gCtrlInfor;
DEVICE_CTRL_INFOR gCtrlSetup;
DEVICE_CTRL_INFOR gCtrlResponse;

void Device_RTU_Init(void)
{
    uint8_t i;
    for(i=0; i<G42.Num_Dev_rtu; i++)
    {
        switch(G42.Dev_rtu[i].Dev_Setup.Dev_type)
        {
            case INVERTER:
                Inverter_RTU_Init(i);
                break;
            case PANEL:
                break;
            case STR_COMBINER:
                break;
            case CONTROL_IO:
                break;
            case WEATHER_STATION:
                break;
            default:
                break;
        }
    }
}

void Device_TCP_Init(void)
{
    uint8_t i;
    for(i=0; i<G42.Num_Dev_tcp; i++)
    {
        switch(G42.Dev_tcp[i].Dev_Setup.Dev_type)
        {
            case INVERTER:
                Inverter_TCP_Init(i);
                break;
            case PANEL:
                break;
            case STR_COMBINER:
                break;
            case CONTROL_IO:
                break;
            case WEATHER_STATION:
                Weather_station_Init(&(G42.Dev_tcp[i].Dev_Setup));
                break;
            default:
                break;
        }
    }
}

uint8_t Device_GetData(uint8_t index, char type)
{
    uint8_t device_type;
    if(type == MODBUS_RTU)
    {
        device_type = G42.Dev_rtu[index].Dev_Setup.Dev_type;
    }
    else if(type == MODBUS_TCP)
    {
        device_type  = G42.Dev_tcp[index].Dev_Setup.Dev_type;
    }
    else
    {
        return 0;
    }
    switch(device_type)
    {
        case INVERTER:
            Inverter_GetData(index,type);
            break;
        case PANEL:
            break;
        case STR_COMBINER:
            break;
        case CONTROL_IO:
            break;
        case WEATHER_STATION:
            Weather_GetData(index);
            break;
        default:
            break;              
    }
    return 1;
}

void Device_ResponseCtrl(void)
{
    switch(gCtrlInfor.Dev_Type)
    {
        case INVERTER:
            Inverter_ResponseCtrl(gCtrlInfor.Modbus_Type);
            break;
        case CONTROL_IO:
            break;
        default:
            break;
    }
}


void Device_CtrlStrToBuffer(void)
{
    switch(gCtrlInfor.Dev_Type)
    {
        case INVERTER:
            Inverter_CtrlStrToBuffer(gCtrlInfor.Modbus_Type);
            break;
        case CONTROL_IO:
            break;
        default:
            break;
    }
}

void Display_PV_paramenters(void)
{

}
