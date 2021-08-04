#include "../../SES.h"

__eds__ __attribute ((eds))WEATHER_DATA Weather[MAX_WEATHER];

void Weather_station_Init(DEVICE_INFOR *Weather_Setup)
{
    (*Weather_Setup).Func = MB_FC_READ_HOLD_REGISTERS;
    (*Weather_Setup).NumFr = 1;
    (*Weather_Setup).Fr[0].u16RegAdd = 0;
    (*Weather_Setup).Fr[0].u16CoilsNo = 7;
    (*Weather_Setup).Fr[0].pointer = 0;
}
void Weather_GetData(uint8_t index)
{
    static uint8_t I_Wea=0;
    Weather[I_Wea].SID = G42.Dev_tcp[index].Dev_Setup.SID;
    Weather[I_Wea].Series = G42.Dev_tcp[index].Dev_Setup.Series;
    Weather[I_Wea].Modbus_Type =  MODBUS_TCP;
    Weather[I_Wea].WIND_SPEED = TCP_Buffer[index][0];
    Weather[I_Wea].WIND_DIRECTION = TCP_Buffer[index][1];
    Weather[I_Wea].IRRADIATION = TCP_Buffer[index][2];
    Weather[I_Wea].AMBIENT_T = TCP_Buffer[index][3];
    Weather[I_Wea].AIR_H = TCP_Buffer[index][4];
    Weather[I_Wea].RAIN = TCP_Buffer[index][5];
    Weather[I_Wea].ATMOSPHERIC = TCP_Buffer[index][6];
    I_Wea++;
    if(I_Wea >= G42.Num_weather)
    {
        I_Wea=0;
    }
}
