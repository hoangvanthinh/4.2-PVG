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

void Display_PV_paramenters(void)
{
    static uint8_t di=0;
    switch(di)
    {
        case 0:
        {
            printf("\nType of device: INVERTER\n");
            printf("Name device: SUN6KG03\n");
            printf("Phase voltages: %d %d %d\n",InvData_RTU[0].AC.AN,InvData_RTU[0].AC.BN,InvData_RTU[0].AC.CN);
            printf("Line voltages: %d %d %d\n",InvData_RTU[0].AC.VAB,InvData_RTU[0].AC.VBC,InvData_RTU[0].AC.VCA);
            printf("Currents AC: %d %d %d\n",InvData_RTU[0].AC.IA,InvData_RTU[0].AC.IB,InvData_RTU[0].AC.IC);
            printf("Power Factor: %d\n",InvData_RTU[0].AC.PF);
            printf("Powers: %d %d %d\n",InvData_RTU[0].AC.P,InvData_RTU[0].AC.Q,InvData_RTU[0].AC.S);
            printf("Frequency: %d\n",InvData_RTU[0].AC.F);
            printf("Energy: %lld %lld %lld\n",InvData_RTU[0].AC.EP,InvData_RTU[0].AC.EQ,InvData_RTU[0].AC.ES);
            printf("DC current: %d\n",InvData_RTU[0].DC.I_DC);
            printf("DC voltage: %d\n",InvData_RTU[0].DC.U_DC);
            printf("DC power: %d\n",InvData_RTU[0].DC.P_DC);
            printf("Temperature cabinet: %d\n",InvData_RTU[0].T.T_Cabinet);
            printf("Temperature heat sink: %d\n",InvData_RTU[0].T.T_Heat_Sink);
            printf("Temperature transformer: %d\n",InvData_RTU[0].T.T_Tranformer);
            printf("Operation state: %d\n",InvData_RTU[0].Operating_State);
            printf("Event: %d\n",InvData_RTU[0].Event);
            break;
        }
        case 1:
        {
            printf("\nType of device: INVERTER\n");
            printf("Name device: SG110CX\n");
            printf("Phase voltages: %d %d %d\n",InvData_TCP[0].AC.AN,InvData_TCP[0].AC.BN,InvData_TCP[0].AC.CN);
            printf("Line voltages: %d %d %d\n",InvData_TCP[0].AC.VAB,InvData_TCP[0].AC.VBC,InvData_TCP[0].AC.VCA);
            printf("Currents AC: %d %d %d\n",InvData_TCP[0].AC.IA,InvData_TCP[0].AC.IB,InvData_TCP[0].AC.IC);
            printf("Power Factor: %d\n",InvData_TCP[0].AC.PF);
            printf("Powers: %d %d %d\n",InvData_TCP[0].AC.P,InvData_TCP[0].AC.Q,InvData_TCP[0].AC.S);
            printf("Frequency: %d\n",InvData_TCP[0].AC.F);
            printf("Energy: %lld %lld %lld\n",InvData_TCP[0].AC.EP,InvData_TCP[0].AC.EQ,InvData_TCP[0].AC.ES);
            printf("DC current: %d\n",InvData_TCP[0].DC.I_DC);
            printf("DC voltage: %d\n",InvData_TCP[0].DC.U_DC);
            printf("DC power: %d\n",InvData_TCP[0].DC.P_DC);
            printf("Temperature cabinet: %d\n",InvData_TCP[0].T.T_Cabinet);
            printf("Temperature heat sink: %d\n",InvData_TCP[0].T.T_Heat_Sink);
            printf("Temperature transformer: %d\n",InvData_TCP[0].T.T_Tranformer);
            printf("Operation state: %d\n",InvData_TCP[0].Operating_State);
            printf("Event: %d\n",InvData_TCP[0].Event);
            break;
        }
        case 2:
        {
            printf("\nType of device: Weather Station\n");
            printf("Wind speed: %d\n",Weather[0].WIND_SPEED);
            printf("Wind direction: %d\n",Weather[0].WIND_DIRECTION);
            printf("Irradiation: %d\n",Weather[0].IRRADIATION);
            printf("Temperature: %d\n",Weather[0].AMBIENT_T);
            printf("Air humidity: %d\n",Weather[0].AIR_H);
            printf("Atmospheric: %d\n",Weather[0].ATMOSPHERIC);
            printf("Rain: %d\n",Weather[0].RAIN);
            break;
        }
    }
    di++;
    if(di>2)
        di=0;

}