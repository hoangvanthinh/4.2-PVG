/*********************************************************************
 *
 *	MODBUS TCP Server Example Application
 *      Module for Microchip TCP/IP Stack
 *      -Implements an MODBUS Server over TCP on port 502
 *
 *********************************************************************
 * FileName:        MODBUSTCPServer.c
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
#define __MODBUSTCPSERVER_C

//#include "TCPIPConfig.h"
#include "../SES.h"


char ReadByteReverse = 1;           //If a modbus client requires to reverse the byte order for HOLDING REGISTER
char InputByteReverse = 1;
char WriteByteReverse = 0;


_MODBUS_COMMAND MODBUS_COMMAND;
static BYTE iLlegal_Function;
static BYTE MODBUS_RX[MODBUS_RX_BUFFER_SIZE];                //MODBUS TCP buffer
static BYTE MODBUS_TX[MODBUS_TX_BUFFER_SIZE];          //Buffer to transfer MODBUS response
static WORD_VAL1 COIL;
static BYTE COIL_REG[COIL_SIZE];                       //Saves addresses and value for coils
static WORD REG_TEMP[HOLDING_REG_SIZE];
static WORD HOLDING_REG[HOLDING_REG_SIZE];
static WORD    INPUT_REG[INPUT_REG_SIZE];
 APP_CONFIG AppConfig ;

static void InitAppConfig(void) ;
static void MODBUSTCPServer(void);
static void ProcessReceivedMessage(void);
static void readHoldingRegister(void);
static void writeHoldingRegister(void);
static void readInputRegister(void);
//static void writeMultipleCoils(void);
static void writeSingleCoil(void);
static void ModbusError(unsigned char ErrNum);


//============================================================================
static ROM uint8_t SerializedMACAddress[6] = {MY_DEFAULT_MAC_BYTE1, MY_DEFAULT_MAC_BYTE2, 
		MY_DEFAULT_MAC_BYTE3, MY_DEFAULT_MAC_BYTE4, MY_DEFAULT_MAC_BYTE5, MY_DEFAULT_MAC_BYTE6};
// IP?A?h???X?ª?Ã?º?Ãè??˙ê›?Ë
static void InitAppConfig(void)
{
     memset((void *)&AppConfig, 0x00, sizeof(AppConfig));
	AppConfig.Flags.bInConfigMode = true ;
	memcpypgm2ram((void*)&AppConfig.MyMACAddr, (ROM void*)SerializedMACAddress, 
				sizeof(AppConfig.MyMACAddr));
#if defined STACK_USE_DHCP_CLIENT
     AppConfig.Flags.bIsDHCPEnabled = true;
     AppConfig.MyIPAddr.Val = 0;
     AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
     AppConfig.MyMask.Val = 0;
     AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
     AppConfig.MyGateway.Val = 0;
     AppConfig.PrimaryDNSServer.Val = 0;
     AppConfig.SecondaryDNSServer.Val = 0;
#else
	AppConfig.Flags.bIsDHCPEnabled = false ;
	AppConfig.MyIPAddr.Val = MY_DEFAULT_IP_ADDR_BYTE1 | MY_DEFAULT_IP_ADDR_BYTE2<<8ul 
					| MY_DEFAULT_IP_ADDR_BYTE3<<16ul | MY_DEFAULT_IP_ADDR_BYTE4<<24ul;
	AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
	AppConfig.MyMask.Val = MY_DEFAULT_MASK_BYTE1 | MY_DEFAULT_MASK_BYTE2<<8ul 
					| MY_DEFAULT_MASK_BYTE3<<16ul | MY_DEFAULT_MASK_BYTE4<<24ul;
	AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
	AppConfig.MyGateway.Val = MY_DEFAULT_GATE_BYTE1 | MY_DEFAULT_GATE_BYTE2<<8ul 
					| MY_DEFAULT_GATE_BYTE3<<16ul | MY_DEFAULT_GATE_BYTE4<<24ul;
	AppConfig.PrimaryDNSServer.Val = MY_DEFAULT_PRIMARY_DNS_BYTE1 | MY_DEFAULT_PRIMARY_DNS_BYTE2<<8ul  
					| MY_DEFAULT_PRIMARY_DNS_BYTE3<<16ul  | MY_DEFAULT_PRIMARY_DNS_BYTE4<<24ul;
	AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2<<8ul  
					| MY_DEFAULT_SECONDARY_DNS_BYTE3<<16ul  | MY_DEFAULT_SECONDARY_DNS_BYTE4<<24ul;
#endif
     // ?f?t?H???g?ÃNetBIOS?z?X?g?º??çÅ[?h?∑?È
     memcpypgm2ram(AppConfig.NetBIOSName, (ROM void *)MY_DEFAULT_HOST_NAME, 16);
     FormatNetBIOSName(AppConfig.NetBIOSName);
}
void SES_ModbusTCP_Server_Init(void)
{
    InitAppConfig() ;
    StackInit() ;
}
void SES_ModbusTCP_Server_Process(void)
{
        StackTask() ;
        StackApplications();
        MODBUSTCPServer();
}
/*****************************************************************************
  Function:
	void MODBUSTCPServer(void)

  Summary:
	Implements a MODBUS_RX TCP Server.

  Precondition:
	TCP is initialized.

 *   Parameters:
	None

  Returns:
  	None
  ***************************************************************************/
static void MODBUSTCPServer(void)
{
    UINT16 w;
    UINT16 wMaxGet;

    static TCP_SOCKET	MySocket;
    static enum _MODBUSTCPServerState
    {
            SM_HOME = 0,
            SM_RECEIVEDATA,
    } MODBUSTCPServerState = SM_HOME;

    switch(MODBUSTCPServerState)
    {
            case SM_HOME:
                    // Allocate a socket for this server to listen and accept connections on
                    MySocket = TCPOpen(0, TCP_OPEN_SERVER, MODBUS_PORT, TCP_PURPOSE_MODBUS_TCP_SERVER);
                    if(MySocket == INVALID_SOCKET)
                            return;

                    MODBUSTCPServerState = SM_RECEIVEDATA;
                    break;

            case SM_RECEIVEDATA:
                    // See if anyone is connected to us
                    if(!TCPIsConnected(MySocket))
                            return;

                    // Figure out how many bytes have been received and how many we can transmit.
                    wMaxGet = TCPIsGetReady(MySocket);	// Get TCP RX FIFO byte count
                    if(wMaxGet!=0)
                    {
                        TCPGetArray(MySocket, &MODBUS_RX[0], wMaxGet);
                        ProcessReceivedMessage();

                        switch (MODBUS_COMMAND.FunctionCode)
                        {
                            case ReadHoldingRegister:

                                //HOLDING_REG[2]++;
                                //Assemble the data
                                readHoldingRegister();

                                //Test if server sends Exception error to the client
                                if (!(MODBUS_TX[MODBUS_FunctionCode] == 0X83))
                                {
                                    w = 0x09 + MODBUS_TX[8];
                                }

                                else w = 9;

                                TCPPutArray(MySocket, MODBUS_TX, w);
                                //printf("%d\r\n",w);
                                    break;

                            case WriteMultipleRegister:

                                //Assemble the data
                                writeHoldingRegister();

                                //Test if server sends Exception error to the client
                                if (!(MODBUS_TX[MODBUS_FunctionCode] == 0X90))
                                {
                                    w = 12;
                                }

                                else w = 9;
                                
                                
                                TCPPutArray(MySocket, MODBUS_TX, w);

                                    break;

                            case ReadInputRegister:

                                readInputRegister();

                                //Test if server sends Exception error to the client
                                if (!(MODBUS_TX[MODBUS_FunctionCode] == 0X84))
                                {
                                    w = 0x09 + MODBUS_TX[8];
                                }

                                else w = 9;

                                TCPPutArray(MySocket, MODBUS_TX, w);

                                    break;

                            case WriteSingleCoil:

                                //Assemble the data
                                writeSingleCoil();

                                //Test if server sends Exception error to the client
                                if (!(MODBUS_TX[MODBUS_FunctionCode] == 0X85))
                                {
                                    w = 0x09 + MODBUS_TX[8];
                                }

                                else w = 12;

                                TCPPutArray(MySocket, MODBUS_TX, w);

                                    break;
                        }

                    }
                    // If the client requested a function which is not supported by this server
                    if(iLlegal_Function)
                    {
                        TCPPutArray(MySocket, MODBUS_TX, 9);
                        iLlegal_Function = 0;
                    }

                    break;
            }
}

//#endif //#if defined(STACK_USE_GENERIC_TCP_SERVER_EXAMPLE)


//Function Definition
static void ProcessReceivedMessage(void)
{

    //Transaction Identifier
    MODBUS_COMMAND.TransactionID.v[1] = MODBUS_RX[0];
    MODBUS_COMMAND.TransactionID.v[0] = MODBUS_RX[1];
    //Protocol Identifier
    MODBUS_COMMAND.ProtocolID.v[1] = MODBUS_RX[2];
    MODBUS_COMMAND.ProtocolID.v[0] = MODBUS_RX[3];
    //Number of bytes to receive
    MODBUS_COMMAND.Length = MODBUS_RX[5];
    //Unit Identifier
    MODBUS_COMMAND.UnitID = MODBUS_RX[6];
    //Function code
    MODBUS_COMMAND.FunctionCode = MODBUS_RX[7];
    //Address
    MODBUS_COMMAND.StartAddress.v[1] = MODBUS_RX[8];
    MODBUS_COMMAND.StartAddress.v[0] = MODBUS_RX[9];
    //Number of Register or Quantity
    MODBUS_COMMAND.NumberOfRegister.v[1] = MODBUS_RX[10];
    MODBUS_COMMAND.NumberOfRegister.v[0] = MODBUS_RX[11];

     //Verify the function code
    if(!((MODBUS_COMMAND.FunctionCode == ReadHoldingRegister)      ||
            (MODBUS_COMMAND.FunctionCode == WriteMultipleRegister) ||
            (MODBUS_COMMAND.FunctionCode == ReadInputRegister)     ||
            (MODBUS_COMMAND.FunctionCode == WriteSingleCoil)))
    {
        ModbusError(Illegal_Function_Code);
        memcpy(MODBUS_TX, MODBUS_RX, 9);
        iLlegal_Function = 1;
        return;
    }
}

static void ModbusError(unsigned char ExceptionCode)
{

    MODBUS_RX[4]=0X00;
    MODBUS_RX[5]=0X03;
    MODBUS_RX[MODBUS_FunctionCode]+=0X80;
    MODBUS_RX[MODBUS_ExceptionCode]=ExceptionCode;

     //Copy MODBUS_RX into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 9);

}
/*****************************************************************************
  Function:
	void readHoldingRegister(void

  Summary:
        Implements read holding registers command. 

 *   Parameters:
	None

  Returns:
  	None
  ***************************************************************************/
//Reply with Holding register value
static void readHoldingRegister(void)
{
    unsigned char a;

    //Verify that the data can be sent
    if((MODBUS_COMMAND.StartAddress.Val > ((int)HOLDING_REG_SIZE - 1)) ||
        ((MODBUS_COMMAND.StartAddress.Val - 1 + MODBUS_COMMAND.NumberOfRegister.Val) > (int)HOLDING_REG_SIZE))
    {
        ModbusError(Illegal_Data_Address);
        return;
    }

    //Assemble the data to be sent
    
    //Function code
    MODBUS_RX[7] = MODBUS_COMMAND.FunctionCode;

    MODBUS_RX[8] = (unsigned char)MODBUS_COMMAND.NumberOfRegister.Val*2;
    //Length
    MODBUS_RX[4] = 0X0;
    MODBUS_RX[5] = 0X3 + MODBUS_RX[8];

   
    //memcpy(REG_TEMP, HOLDING_REG + MODBUS_COMMAND.StartAddress.Val, MODBUS_COMMAND.NumberOfRegister.Val*2);
    memcpy(REG_TEMP, INPUT_REG_SES + MODBUS_COMMAND.StartAddress.Val, MODBUS_COMMAND.NumberOfRegister.Val*2);

    for(a = 0;a < MODBUS_COMMAND.NumberOfRegister.Val;a++)
    {
        REG_TEMP[a] = (WORD)((REG_TEMP[a] & 0x00FF) << 8 | (REG_TEMP[a] & 0xFF00) >> 8);
    }
    
    //Copy MODBUS_RX and HOLdING_REG into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 9);
    memcpy(MODBUS_TX + 9, REG_TEMP, MODBUS_COMMAND.NumberOfRegister.Val*2);
    
}

static void writeHoldingRegister(void)
{
    char a;

    //Verify that the data can be sent
    if((MODBUS_COMMAND.StartAddress.Val > ((int)HOLDING_REG_SIZE - 1)) ||
        ((MODBUS_COMMAND.StartAddress.Val - 1 + MODBUS_COMMAND.NumberOfRegister.Val) > (int)HOLDING_REG_SIZE))
    {
        ModbusError(Illegal_Data_Address);
        return;
    }

    //Assemble the data to be sent
    MODBUS_RX[7] = MODBUS_COMMAND.FunctionCode;

    MODBUS_RX[8] = 0x00; //Byte Count
    //Length
    MODBUS_RX[4] = 0X0;
    MODBUS_RX[5] = 0X6;


    //Copy MODBUS_RX into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 12);

    //a = MODBUS_RX[12];// so byte
    //memcpy(REG_TEMP, MODBUS_RX + 13, a);
    memcpy(REG_TEMP, MODBUS_RX + 13,MODBUS_COMMAND.NumberOfRegister.Val*2);
    
    for(a = 0;a < MODBUS_COMMAND.NumberOfRegister.Val;a++)
    {
        REG_TEMP[(BYTE)a] = ((REG_TEMP[(BYTE)a] & 0x00FF) << 8 | (REG_TEMP[(BYTE)a] & 0xFF00) >> 8);
    }
    memcpy(HOLDING_REG + MODBUS_COMMAND.StartAddress.Val, REG_TEMP, MODBUS_COMMAND.NumberOfRegister.Val*2);
    
}


//Read Input register
static void readInputRegister(void)
{
    char a;

    //Verify that the data can be sent
    if((MODBUS_COMMAND.StartAddress.Val > ((int)INPUT_REG_SIZE - 1)) ||
        ((MODBUS_COMMAND.StartAddress.Val - 1 + MODBUS_COMMAND.NumberOfRegister.Val) > (int)INPUT_REG_SIZE))
    {
        ModbusError(Illegal_Data_Address);
        return;
    }

    //Assemble the data to be sent
    //Function code
    MODBUS_RX[7] = MODBUS_COMMAND.FunctionCode;

    MODBUS_RX[8] = (char)MODBUS_COMMAND.NumberOfRegister.Val*2;
    //Length
    MODBUS_RX[4] = 0X0;
    MODBUS_RX[5] = 0X3 + MODBUS_RX[8];

    //change the byte order of INPUT_REG
    if (InputByteReverse)
    {
        for(a=0; a<sizeof(INPUT_REG); a++)
        {
            INPUT_REG[(BYTE)a] = (WORD)((INPUT_REG[(BYTE)a] & 0xFF) << 8 | (INPUT_REG[(BYTE)a] & 0xFF00) >> 8);
        }
       InputByteReverse = 0;
    }

    //Copy MODBUS_RX and HOLEING_REG into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 9);
    memcpy(MODBUS_TX + 9,INPUT_REG + MODBUS_COMMAND.StartAddress.Val,MODBUS_COMMAND.NumberOfRegister.Val*2);
}

//Write single coil
static void writeSingleCoil(void)
{

//    BYTE *ptCoil;      // Pointer to save Coil value, ON/OFF
//    int i;
    
    //Assemble the data to be sent
    MODBUS_RX[7] = MODBUS_COMMAND.FunctionCode;

    MODBUS_RX[8] = 0x00; //Byte Count
    //Length
    MODBUS_RX[4] = 0X0;
    MODBUS_RX[5] = 0X6;

    //Copy MODBUS_RX into MODBUS_TX and send MODBUS_TX as response
    memcpy(MODBUS_TX, MODBUS_RX, 12);

    COIL.Addr = MODBUS_RX[9];
    COIL.Val = MODBUS_RX[10];
    COIL_REG[COIL.Addr] = COIL.Val;

}

