#include "../SES.h"


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

void Device_RTU_GetData(uint8_t index)
{
    switch(G42.Dev_rtu[index].Dev_Setup.Dev_type)
    {
        case INVERTER:
            Inverter_RTU_GetData(index);
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

void Device_TCP_GetData(uint8_t index)
{
    switch(G42.Dev_tcp[index].Dev_Setup.Dev_type)
    {
        case INVERTER:
            Inverter_TCP_GetData(index);
            break;
        case PANEL:
            break;
        case STR_COMBINER:
            break;
        case CONTROL_IO:
            break;
        case WEATHER_STATION:
            Weather_TCP_GetData(index);
            break;
        default:
            break;  
    }
}