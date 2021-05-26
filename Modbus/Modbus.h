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
#ifndef XC_HEADER_Modbus_H
#define	XC_HEADER_Modbus_H

#include <xc.h> // include processor files - each processor file is guarded.  

enum MB_FC
{
    MB_FC_NONE                     = 0,   /*!< null operator */
    MB_FC_READ_COILS               = 1,	/*!< FCT=1 -> read coils or digital outputs */
    MB_FC_READ_DISCRETE_INPUT      = 2,	/*!< FCT=2 -> read digital inputs */
    MB_FC_READ_HOLD_REGISTERS      = 3,	/*!< FCT=3 -> read registers or analog outputs */
    MB_FC_READ_INPUT_REGISTER      = 4,	/*!< FCT=4 -> read analog inputs */
    MB_FC_WRITE_COIL               = 5,	/*!< FCT=5 -> write single coil or output */
    MB_FC_WRITE_REGISTER           = 6,	/*!< FCT=6 -> write single register */
    MB_FC_WRITE_MULTIPLE_COILS     = 15,	/*!< FCT=15 -> write multiple coils or outputs */
    MB_FC_WRITE_MULTIPLE_REGISTERS = 16	/*!< FCT=16 -> write multiple registers */
};

enum
{
    NO_REPLY = 255,
    EXC_FUNC_CODE = 1,
    EXC_ADDR_RANGE = 2,
    EXC_REGS_QUANT = 3,
    EXC_EXECUTE = 4
};
enum ERR_LIST
{
    ERR_NOT_MASTER                = -1,
    ERR_POLLING                   = -2,
    ERR_BUFF_OVERFLOW             = -3,
    ERR_BAD_CRC                   = -4,
    ERR_EXCEPTION                 = -5
};


#define  MAX_BUFFER  270	//!< maximum size for the communication buffer in bytes

//===========================MODBUS=============================================
typedef union
{   
    UINT64 val;
    uint16_t REG[4];
    struct __attribute__((packed)) 
    {
        uint8_t b0 : 1;
        uint8_t b1 : 1;
        uint8_t b2 : 1;
        uint8_t b3 : 1;
        uint8_t b4 : 1;
        uint8_t b5 : 1;
        uint8_t b6 : 1;
        uint8_t b7 : 1;
        uint8_t b8 : 1;
        uint8_t b9 : 1;
        uint8_t b10 : 1;
        uint8_t b11 : 1;
        uint8_t b12 : 1;
        uint8_t b13 : 1;
        uint8_t b14 : 1;
        uint8_t b15 : 1;
        uint8_t b16 : 1;
        uint8_t b17 : 1;
        uint8_t b18 : 1;
        uint8_t b19 : 1;
        uint8_t b20 : 1;
        uint8_t b21 : 1;
        uint8_t b22 : 1;
        uint8_t b23 : 1;
        uint8_t b24 : 1;
        uint8_t b25 : 1;
        uint8_t b26 : 1;
        uint8_t b27 : 1;
        uint8_t b28 : 1;
        uint8_t b29 : 1;
        uint8_t b30 : 1;
        uint8_t b31 : 1;
        uint8_t b32 : 1;
        
        uint8_t b33 : 1;
        uint8_t b34 : 1;
        uint8_t b35 : 1;
        uint8_t b36 : 1;
        uint8_t b37 : 1;
        uint8_t b38 : 1;
        uint8_t b39 : 1;
        uint8_t b40 : 1;
        uint8_t b41 : 1;
        uint8_t b42 : 1;
        uint8_t b43 : 1;
        uint8_t b44 : 1;
        uint8_t b45 : 1;
        uint8_t b46 : 1;
        uint8_t b47 : 1;
        uint8_t b48 : 1;
        uint8_t b49 : 1;
        uint8_t b50 : 1;
        uint8_t b51 : 1;
        uint8_t b52 : 1;
        uint8_t b53 : 1;
        uint8_t b54 : 1;
        uint8_t b55 : 1;
        uint8_t b56 : 1;
        uint8_t b57 : 1;
        uint8_t b58 : 1;
        uint8_t b59 : 1;   
        uint8_t b60 : 1;
        uint8_t b61 : 1;
        uint8_t b62 : 1;
        uint8_t b63 : 1;
        
    }bits;
}STATUS;
//===========================MODBUS=============================================
typedef struct
{
    
    //Stream *port; //!< Pointer to Stream class object (Either HardwareSerial or SoftwareSerial)
    uint8_t u8id; //!< 0=master, 1..247=slave number
    uint8_t u8txenpin; //!< flow control pin: 0=USB or RS-232 mode, >1=RS-485 mode
    uint8_t u8state;
    uint8_t u8lastError;
    uint8_t au8Buffer[MAX_BUFFER];
    UINT16 u8BufferSize;
    uint8_t u8lastRec;
    __eds__ uint16_t *au16regs;
    uint16_t u16InCnt, u16OutCnt, u16errCnt;
    uint16_t u16timeOut;
    uint32_t u32time, u32timeOut, u32overTime;
    uint16_t u8regsize;
    
    STATUS Coils;
    STATUS Inputs;
    uint16_t *HOLDING_REGS;
    uint16_t *INPUT_REGS;
    
}MODBUS;


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

