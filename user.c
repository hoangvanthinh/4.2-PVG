#include "SES.h"


Device_Git Device_Version;
Gateway_setup G42, WEEROM42;
DATA_42 SES_42;

UINT8 Status_Save_Erom;
//UINT64 *Status_Meter;
void Read_G42_Setup(void) {

//   EEPROM_WP_SetLow();
//    Status_Save_Erom = EEPROM3_ReadOneByte(ADD_START_SETUP);
//    if (Status_Save_Erom == VAL_STATUS_EEPROM_YET) {
//        __delay_ms(10);
//        EEPROM3_ReadBlock(ADD_START_SETUP + 1, G42.IP, 4);
//        __delay_ms(10);
//        EEPROM3_ReadBlock(ADD_START_SETUP + 5, G42.SubnetMask, 4);
//        __delay_ms(10);
//        EEPROM3_ReadBlock(ADD_START_SETUP + 9, G42.Gateway, 4);
//        __delay_ms(10);
//        EEPROM3_ReadBlock(ADD_START_SETUP + 13, G42.DNS, 4);
//        __delay_ms(10);
//        EEPROM3_ReadBlock(ADD_START_SETUP + 17, G42.LOCAL_SERVER.IP, 4);
//        __delay_ms(10);
////        G42.HMI_PORT. = EEPROM3_ReadOneByte(ADD_START_SETUP + 21);
//        EEPROM3_ReadBlock(ADD_START_SETUP + 21, G42.LOCAL_SERVER.PORT.val, 2);
//        __delay_ms(10);
//        
//        
//        G42.Num_Interface = EEPROM3_ReadOneByte(ADD_START_SETUP + 100);
//  
//        if (G42.Num_Interface > 50) G42.Num_Interface = 50;
//        __delay_ms(10);
//        static int i = 0;
//        for (i = 0; i < G42.Num_Interface; i++) {
//            EEPROM3_ReadBlock(ADD_START_SETUP + 101 + 5 * i, G42.Interface[i].IP, 4);
//            __delay_ms(10);
//
//            G42.Interface[i].Num_Meter = EEPROM3_ReadOneByte(ADD_START_SETUP + 105 + 5 * i);
//            __delay_ms(10);
//
//        }
//    }
//    else
//    {
        G42.IP[0] = 192;
        G42.IP[1] = 168;
        G42.IP[2] = 0;
        G42.IP[3] = 2;

        G42.SubnetMask[0] = 255;
        G42.SubnetMask[1] = 255;
        G42.SubnetMask[2] = 255;
        G42.SubnetMask[3] = 0;

        G42.Gateway[0] = 192;
        G42.Gateway[1] = 168;
        G42.Gateway[2] = 0;
        G42.Gateway[3] = 1;

        G42.DNS[0] = 192;
        G42.DNS[1] = 168;
        G42.DNS[2] = 0;
        G42.DNS[3] = 1;
        
        G42.LOCAL_SERVER.IP[0] = 192;
        G42.LOCAL_SERVER.IP[1] = 168;
        G42.LOCAL_SERVER.IP[2] = 0;
        G42.LOCAL_SERVER.IP[3] = 1;
        G42.LOCAL_SERVER.PORT.val16 = 502;
        
        G42.Num_inverter_rtu = 1;
        G42.Num_inverter_tcp = 0;
        G42.Num_panel_rtu = 0;
        G42.Num_panel_tcp = 0;
        G42.Num_str_combiner_rtu = 0;
        G42.Num_str_combiner_tcp = 0;
        G42.Num_control_io_rtu = 0;
        G42.Num_control_io_tcp = 0;
        G42.Num_weather = 1;
        
        G42.Num_Dev_rtu = 1;
        G42.Num_Dev_tcp = 1;
        
        G42.Dev_rtu[0].Dev_Setup.Dev_type = INVERTER;
        G42.Dev_rtu[0].Dev_Setup.Series = SG110CX;
        G42.Dev_rtu[0].Dev_Setup.UID = 1;

        G42.Dev_tcp[0].Dev_Setup.Dev_type = WEATHER_STATION;
        G42.Dev_tcp[0].Dev_Setup.Series = 0;
        G42.Dev_tcp[0].IP[0] = 192;
        G42.Dev_tcp[0].IP[1] = 168;
        G42.Dev_tcp[0].IP[2] = 0;
        G42.Dev_tcp[0].IP[3] = 3;
    
        
    //}
    //EEPROM_WP_SetHigh();

    Modbus_RTU_Slave_Add_Setup();

}

void Modbus_RTU_Slave_Add_Setup(void) {
    uint8_t i;
    
    SES_42.SETUP_REGS[0] = SD_GATEWAY_L;
    SES_42.SETUP_REGS[1] = Device_Version.SW_Version[0];
    SES_42.SETUP_REGS[2] = Device_Version.SW_Version[1];
    SES_42.SETUP_REGS[3] = Device_Version.SW_Version[2];
    SES_42.SETUP_REGS[4] = Device_Version.SW_Version[3];
    
    SES_42.SETUP_REGS[16] = G42.IP[0];
    SES_42.SETUP_REGS[17] = G42.IP[1];
    SES_42.SETUP_REGS[18] = G42.IP[2];
    SES_42.SETUP_REGS[19] = G42.IP[3];

    SES_42.SETUP_REGS[20] = G42.SubnetMask[0];
    SES_42.SETUP_REGS[21] = G42.SubnetMask[1];
    SES_42.SETUP_REGS[22] = G42.SubnetMask[2];
    SES_42.SETUP_REGS[23] = G42.SubnetMask[3];

    SES_42.SETUP_REGS[24] = G42.Gateway[0];
    SES_42.SETUP_REGS[25] = G42.Gateway[1];
    SES_42.SETUP_REGS[26] = G42.Gateway[2];
    SES_42.SETUP_REGS[27] = G42.Gateway[3];

    SES_42.SETUP_REGS[28] = G42.DNS[0];
    SES_42.SETUP_REGS[29] = G42.DNS[1];
    SES_42.SETUP_REGS[30] = G42.DNS[2];
    SES_42.SETUP_REGS[31] = G42.DNS[3];
    
    SES_42.SETUP_REGS[32] = G42.LOCAL_SERVER.IP[0];
    SES_42.SETUP_REGS[33] = G42.LOCAL_SERVER.IP[1];
    SES_42.SETUP_REGS[34] = G42.LOCAL_SERVER.IP[2];
    SES_42.SETUP_REGS[35] = G42.LOCAL_SERVER.IP[3];
    SES_42.SETUP_REGS[36] = G42.LOCAL_SERVER.PORT.val16;
    //======================================================================
    SES_42.SETUP_REGS[100] = G42.Num_inverter_rtu;
    SES_42.SETUP_REGS[101] = G42.Num_inverter_tcp;
    SES_42.SETUP_REGS[102] = G42.Num_panel_rtu;
    SES_42.SETUP_REGS[103] = G42.Num_panel_tcp;
    SES_42.SETUP_REGS[104] = G42.Num_str_combiner_rtu;
    SES_42.SETUP_REGS[105] = G42.Num_str_combiner_tcp;
    SES_42.SETUP_REGS[106] = G42.Num_control_io_rtu;
    SES_42.SETUP_REGS[100] = G42.Num_control_io_tcp;//Control IO
    SES_42.SETUP_REGS[108] = G42.Num_weather;
    SES_42.SETUP_REGS[109] = G42.Num_Dev_rtu;
    SES_42.SETUP_REGS[110] = G42.Num_Dev_tcp;

    for(i=0; i<SES_42.SETUP_REGS[109]; i++)
    {
        SES_42.SETUP_REGS[111+3*i] = G42.Dev_rtu[i].Dev_Setup.UID;
        SES_42.SETUP_REGS[112+3*i] = G42.Dev_rtu[i].Dev_Setup.Dev_type;
        SES_42.SETUP_REGS[113+3*i] = G42.Dev_rtu[i].Dev_Setup.Series;
    }
    
    for(i=0; i<SES_42.SETUP_REGS[110]; i++)
    {
        SES_42.SETUP_REGS[171+6*i] = G42.Dev_tcp[i].IP[0];
        SES_42.SETUP_REGS[172+6*i] = G42.Dev_tcp[i].IP[1];
        SES_42.SETUP_REGS[173+6*i] = G42.Dev_tcp[i].IP[2];
        SES_42.SETUP_REGS[174+6*i] = G42.Dev_tcp[i].IP[3];
        SES_42.SETUP_REGS[175+6*i] = G42.Dev_rtu[i].Dev_Setup.Dev_type;
        SES_42.SETUP_REGS[176+6*i] = G42.Dev_rtu[i].Dev_Setup.Series;
    }
}

void Check_Save_DataSetup(void) {
    if (SES_42.Coils.bits.b0 == 1) {
        SPEAKER_SetHigh();
        __delay_ms(200);
        WEEROM42.IP[0] = SES_42.SETUP_REGS[16];
        WEEROM42.IP[1] = SES_42.SETUP_REGS[17];
        WEEROM42.IP[2] = SES_42.SETUP_REGS[18];
        WEEROM42.IP[3] = SES_42.SETUP_REGS[19];

        WEEROM42.SubnetMask[0] = SES_42.SETUP_REGS[20];
        WEEROM42.SubnetMask[1] = SES_42.SETUP_REGS[21];
        WEEROM42.SubnetMask[2] = SES_42.SETUP_REGS[22];
        WEEROM42.SubnetMask[3] = SES_42.SETUP_REGS[23];

        WEEROM42.Gateway[0] = SES_42.SETUP_REGS[24];
        WEEROM42.Gateway[1] = SES_42.SETUP_REGS[25];
        WEEROM42.Gateway[2] = SES_42.SETUP_REGS[26];
        WEEROM42.Gateway[3] = SES_42.SETUP_REGS[27];

        WEEROM42.DNS[0] = SES_42.SETUP_REGS[28];
        WEEROM42.DNS[1] = SES_42.SETUP_REGS[29];
        WEEROM42.DNS[2] = SES_42.SETUP_REGS[30];
        WEEROM42.DNS[3] = SES_42.SETUP_REGS[31];

        WEEROM42.LOCAL_SERVER.IP[0] = SES_42.SETUP_REGS[32];
        WEEROM42.LOCAL_SERVER.IP[1] = SES_42.SETUP_REGS[33];
        WEEROM42.LOCAL_SERVER.IP[2] = SES_42.SETUP_REGS[34];
        WEEROM42.LOCAL_SERVER.IP[3] = SES_42.SETUP_REGS[35];        
        WEEROM42.LOCAL_SERVER.PORT.val16 = SES_42.SETUP_REGS[36];   
        
        WEEROM42.Num_inverter_rtu = SES_42.SETUP_REGS[100];
        WEEROM42.Num_inverter_tcp = SES_42.SETUP_REGS[101];
        WEEROM42.Num_panel_rtu = SES_42.SETUP_REGS[102];
        WEEROM42.Num_panel_tcp = SES_42.SETUP_REGS[103];
        WEEROM42.Num_str_combiner_rtu = SES_42.SETUP_REGS[104];
        WEEROM42.Num_str_combiner_tcp = SES_42.SETUP_REGS[105];
        WEEROM42.Num_control_io_rtu = SES_42.SETUP_REGS[106];
        WEEROM42.Num_control_io_tcp = SES_42.SETUP_REGS[107];
        WEEROM42.Num_weather = SES_42.SETUP_REGS[108];
        
        WEEROM42.Num_Dev_rtu = SES_42.SETUP_REGS[109];
        WEEROM42.Num_Dev_tcp = SES_42.SETUP_REGS[110];
        uint8_t i;
        for (i = 0; i < WEEROM42.Num_Dev_rtu; i++)
        {
            WEEROM42.Dev_rtu[i].Dev_Setup.Dev_type = SES_42.SETUP_REGS[112+3*i];
            WEEROM42.Dev_rtu[i].Dev_Setup.UID = SES_42.SETUP_REGS[111 + 3*i];
            WEEROM42.Dev_rtu[i].Dev_Setup.Series = SES_42.SETUP_REGS[113 +3*i];
        }
        for (i = 0; i < WEEROM42.Num_Dev_tcp; i++) {
            WEEROM42.Dev_tcp[i].IP[0] = SES_42.SETUP_REGS[171 + 6*i];
            WEEROM42.Dev_tcp[i].IP[1] = SES_42.SETUP_REGS[172 + 6*i];
            WEEROM42.Dev_tcp[i].IP[2] = SES_42.SETUP_REGS[173 + 6*i];
            WEEROM42.Dev_tcp[i].IP[3] = SES_42.SETUP_REGS[174 + 6*i];
            WEEROM42.Dev_tcp[i].Dev_Setup.Dev_type = SES_42.SETUP_REGS[175 + 6*i];
            WEEROM42.Dev_tcp[i].Dev_Setup.Series = SES_42.SETUP_REGS[176 + 6*i];
        }
        Write_WEEROM42();
        SES_42.Coils.bits.b0 = 0;
        SPEAKER_SetLow();
        Reset();
    }
}

void Write_WEEROM42(void) {
    EEPROM_WP_SetLow();
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP, VAL_STATUS_EEPROM_YET);
    __delay_ms(10);
    EEPROM3_WriteBlock(ADD_START_SETUP + 1, WEEROM42.IP, 4);
    __delay_ms(10);
    EEPROM3_WriteBlock(ADD_START_SETUP + 5, WEEROM42.SubnetMask, 4);
    __delay_ms(10);
    EEPROM3_WriteBlock(ADD_START_SETUP + 9, WEEROM42.Gateway, 4);
    __delay_ms(10);
    EEPROM3_WriteBlock(ADD_START_SETUP + 13, WEEROM42.DNS, 4);
    __delay_ms(10);
    EEPROM3_WriteBlock(ADD_START_SETUP + 17, WEEROM42.LOCAL_SERVER.IP, 4);
    __delay_ms(10);
    EEPROM3_WriteBlock(ADD_START_SETUP + 21, WEEROM42.LOCAL_SERVER.PORT.val, 2);
    __delay_ms(10);
    
    EEPROM3_WriteOneByte(ADD_START_SETUP + 100, WEEROM42.Num_inverter_rtu);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 101, WEEROM42.Num_inverter_tcp);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 102, WEEROM42.Num_panel_rtu);
    __delay_ms(10);    
    EEPROM3_WriteOneByte(ADD_START_SETUP + 103, WEEROM42.Num_panel_tcp);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 104, WEEROM42.Num_str_combiner_rtu);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 105, WEEROM42.Num_str_combiner_tcp);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 106, WEEROM42.Num_control_io_rtu);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 107, WEEROM42.Num_control_io_tcp);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 108, WEEROM42.Num_weather);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 109, WEEROM42.Num_Dev_rtu);
    __delay_ms(10);
    EEPROM3_WriteOneByte(ADD_START_SETUP + 110, WEEROM42.Num_Dev_tcp);
    __delay_ms(10);
    static int i = 0;

    for (i = 0; i < WEEROM42.Num_Dev_rtu; i++) {
        EEPROM3_WriteOneByte(ADD_START_SETUP + 111 + 3 * i, WEEROM42.Dev_rtu[i].Dev_Setup.UID);
        __delay_ms(10);
        EEPROM3_WriteOneByte(ADD_START_SETUP + 112 + 3 * i, WEEROM42.Dev_rtu[i].Dev_Setup.Dev_type);
        __delay_ms(10);
        EEPROM3_WriteOneByte(ADD_START_SETUP + 113 + 3 * i, WEEROM42.Dev_rtu[i].Dev_Setup.Series);
        __delay_ms(10);
    }
    
    for (i = 0; i < WEEROM42.Num_Dev_tcp; i++) {
        EEPROM3_WriteBlock(ADD_START_SETUP + 171 + 6 * i, WEEROM42.Dev_tcp[i].IP, 4);
        __delay_ms(10);
        EEPROM3_WriteOneByte(ADD_START_SETUP + 175 + 6 * i, WEEROM42.Dev_rtu[i].Dev_Setup.Dev_type);
        EEPROM3_WriteOneByte(ADD_START_SETUP + 176 + 6 * i, WEEROM42.Dev_rtu[i].Dev_Setup.Series);
        __delay_ms(10);
    }
    __delay_ms(100);
    EEPROM_WP_SetHigh();

}

void Information_Device(void) {
    
    Device_Version.SW_Version[0] = 3;
    Device_Version.SW_Version[1] = 54;
    Device_Version.SW_Version[2] = 2903;
    Device_Version.SW_Version[3] = 2021;
    
    
    printf("\rI'm Gateway\r");
    printf("PROJECT 04.2\r");
    printf("Development by SES-Tech\r");
    printf("Hardware version: 0.02.20200810 \r");
    printf("Firmware version: 4.2MG810-3.3\r");
    printf("My IP: %d.%d.%d.%d\r", G42.IP[0], G42.IP[1], G42.IP[2], G42.IP[3]);
    printf("Number of RTU device: %d\r", G42.Num_Dev_rtu);
    printf("Number of TCP device: %d\r", G42.Num_Dev_tcp);
    static int i;
    for (i = 0; i < G42.Num_Dev_rtu; i++) {
        printf("ID of Device RTU [%d]: %d\r", i, G42.Dev_rtu[i].Dev_Setup.UID);
    }  
    for (i = 0; i < G42.Num_Dev_tcp; i++) {
        printf("IP of Device RTU [%d]: %d.%d.%d.%d\r", i, G42.Dev_tcp[i].IP[0]
                , G42.Dev_tcp[i].IP[1]
                , G42.Dev_tcp[i].IP[2]
                , G42.Dev_tcp[i].IP[3]
                );       
    }

}

uint32_t convert16to32(uint16_t h, uint16_t l)
{
    uint32_t u32;
    u32 = ((uint32_t)h)<<16 | (uint32_t)l;
    return u32;
}
