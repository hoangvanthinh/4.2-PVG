/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_USER_H
#define	XC_USER_H

#include "SES.h"

#define ADD_START_SETUP 1000
#define ADD_BEGIN_ID_TEMPERATURE (ADD_START_SETUP + 100)
#define VAL_STATUS_EEPROM_YET   111


union data{
    int8_t val[2];
    int16_t val16;
};

typedef struct
{
    STATUS Connected;
    STATUS Coils;
//    STATUS Input_Decrete;
//    uint16_t HOLDING_REGS[300];
//    uint16_t INPUT_REGS[10];
    uint16_t SETUP_REGS[400];
} DATA_42;

extern DATA_42 SES_42;

typedef struct
{
    UINT16 HW_Version[4];
    UINT16 SW_Version[4];
}Device_Git;

extern Device_Git Device_Version;
typedef struct
{
    uint8_t IP[4];
    uint8_t ID;
    UINT8 IID;
}METER;

typedef struct
{
    UINT8 IP[4];
    UINT8 Num_Meter;
    UINT8 Status;
    
}_INTERFACE;
typedef struct
{
    UINT8 IP[4];
    union data PORT;
    UINT8 Status;
}SERVER_LOCAL;


typedef struct
{
    UINT8 IP_Cloud[4];
    union data PORT;
    UINT8 Status;
}SERVER_CLOUD;

typedef struct
{
    UINT8 IP[4];
    UINT8 MAC[6];
    UINT8 SubnetMask[4];
    UINT8 Gateway[4];
    UINT8 DNS[4];
    
    SERVER_LOCAL LOCAL_SERVER;
    SERVER_CLOUD CLOUD_SERVER;

    UINT8 Num_Interface;    
    _INTERFACE Interface[50];
    METER Meter[50]; 
            
}Gateway_setup;


extern Gateway_setup G42, WEEROM42;

extern UINT64 *Status_Meter;

void Read_G42_Setup(void);
void Modbus_RTU_Slave_Add_Setup(void);
void Check_Save_DataSetup(void);
void Write_WEEROM42(void);
void Information_Device(void);

//void READ_MY_IP(void);
//void WRITE_MY_IP(uint32_t address,void* data, uint16_t count);


// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

