/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.166.1
        Device            :  dsPIC33EP256MU806
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.41
        MPLAB 	          :  MPLAB X v5.30
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "SES.h"

/*
                         Main application
 */
int main(void)
{ 
    static uint32_t t,tM1 ;
    // initialize the device
    SYSTEM_Initialize();
    Tick_Init_SES();
    TickInit() ;
    t = TickGet();
    tM1 = TickGet();
    
    Read_G42_Setup();

    Information_Device();
    SES_ModbusTCP_Client_Init();
    SES_ModbusRTU_Master_Init();
    SES_ModbusRTU_Slave_start(); 

    // SIM
    SIM_PWR_SetHigh();
    SPEAKER_SetHigh();
    __delay_ms(500);
    SIM_PWR_SetLow();  
    SPEAKER_SetLow();
    
    
    while (1)
    {
//        if(TickGet() - tM1 >= TICK_SECOND/15) 
//        {
//             tM1 = TickGet() ; 
//             MB1_BLUE_Toggle();
//        }
        if(TickGet() - t >= TICK_SECOND) 
        {
            t = TickGet() ;
             RD_RED_Toggle();
        }
     
        SES_ModbusRTU_Master_Process();
        SES_ModbusTCPIP_Client_Process();
        SES_ModbusRTU_Slave_Process();
        

    }
    return 1; 
}
/**
 End of File
*/

