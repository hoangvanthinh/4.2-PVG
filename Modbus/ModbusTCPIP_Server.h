/*********************************************************************
 *
 *	MODBUS TCP Server Example Application
 *      Module for Microchip TCP/IP Stack
 *      -Implements an MODBUS Server over TCP on port 502
 *
 *********************************************************************
 * FileName:        MODBUSTCPServer.h
 * Dependencies:    TCP
 * Processor:       PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 * Compiler:        Microchip C32 v1.05 or higher
 *					Microchip C30 v3.12 or higher
 *					Microchip C18 v3.30 or higher
 *
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 *
 * Copyright (C) 2002-2009 Microchip Technology Inc.  All rights
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and
 * distribute:
 * (i)  the Software when embedded on a Microchip microcontroller or
 *      digital signal controller product ("Device") which is
 *      integrated into Licensee's product; or
 * (ii) ONLY the Software driver source files ENC28J60.c, ENC28J60.h,
 *		ENCX24J600.c and ENCX24J600.h ported to a non-Microchip device
 *		used in conjunction with a Microchip ethernet controller for
 *		the sole purpose of interfacing with the ethernet controller.
 *
 * You should refer to the license agreement accompanying this
 * Software for additional information regarding your rights and
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date    	Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Parthiv Pandya     10/1/13           Original
 *
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *
 *
 ********************************************************************/

#ifndef __MODBUSTCP_H
#define __MODBUSTCP_H

// Defines which port the server will listen on
#define MODBUS_PORT         502

//Define for buffer size
#define HOLDING_REG_SIZE        125
#define INPUT_REG_SIZE          125
#define MODBUS_RX_BUFFER_SIZE   250
#define MODBUS_TX_BUFFER_SIZE   250
#define COIL_SIZE                5


//Modbus Functions
#define	ReadCoil		  1
#define	ReadDiscreteInputs	  2
#define	ReadHoldingRegister	  3
#define	ReadInputRegister	  4
#define	WriteSingleCoil		  5
#define	WriteSingleRegister	  6
#define	WriteMultipleCoils	 15
#define	WriteMultipleRegister    16

//Modbus Errors
#define Illegal_Function_Code   0x01u
#define Illegal_Data_Address    0x02u

//Position of the data in the frame
#define MODBUS_UnitID           6
#define MODBUS_FunctionCode     7
#define MODBUS_BYTE_COUNT       8
#define MODBUS_DataStart       13
#define MODBUS_ExceptionCode    8

//number of words available for READ HOLDING REGISTER
//#define MAX_REG_SIZE 50u //is it same as HOLDING REG SIZE

//Modbus command structure
typedef struct
{
    WORD_VAL TransactionID;       //Transaction ID
    WORD_VAL ProtocolID;          //Protocol ID
    WORD Length;                  //Length
    BYTE UnitID;                  //Unit ID
    BYTE FunctionCode;            //Function code
    WORD_VAL StartAddress;        //Starting register address
    WORD_VAL NumberOfRegister;    //Number of registers
} _MODBUS_COMMAND;                //MODBUS_COMMAND

extern _MODBUS_COMMAND MODBUS_COMMAND;

typedef struct
{
    BYTE Val;
    BYTE Addr;

} WORD_VAL1, WORD_BITS1;


void SES_ModbusTCP_Server_Init(void);
void SES_ModbusTCP_Server_Process(void);
#endif
