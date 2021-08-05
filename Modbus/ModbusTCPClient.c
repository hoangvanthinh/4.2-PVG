// ModbusClientTCP.c

/*********************************************************************
 *
 *  ModBus Client Application
 *  Module for Microchip TCP/IP Stack
 *   -Implements an example ModBus client and should be used as a basis 
 *	  for creating new TCP client applications
 *	 -Reference: None.  Hopefully AN833 in the future.
 *
 *********************************************************************
 * FileName:        GenericTCPClient.c
 * Dependencies:    TCP, DNS, ARP, Tick
 * Processor:       PIC18, PIC24F, PIC24H, dsPIC30F, dsPIC33F, PIC32
 * Compiler:        Microchip C32 v1.05 or higher
 *					Microchip C30 v3.12 or higher
 *					Microchip C18 v3.30 or higher
 *					HI-TECH PICC-18 PRO 9.63PL2 or higher
 * Company:         Microchip Technology, Inc.
 *
 ********************************************************************/
//#define __MODBUS_C

#include "../SES.h"
//
//#if USE_INVERTER_TCP
//    static UINT8 Num_Inverter = 1;
//#endif
//#if USE_STRCOMBINER_TCP
//    static UINT8 Num_StrCombiner = 0;
//#endif
//#if USE_PANEL_TCP
//    static UINT8 Num_Panel = 0;
//#endif
//#if USE_WEATHER_TCP
//    static UINT8 Num_Weather = 1;
//#endif

UINT16 MAX_Query_TCP =0;
static char bModbusClientInitialised = 0;
static MODBUS_CLIENT_STATE ModbusClientState = (MODBUS_CLIENT_STATE)MBCS_HOME;
static uint16_t Frame_len;
static uint32_t timeout;
static UINT16 query = 0;
static UINT16 ctrl_query = 0;
static uint8_t CS = 0;
//==============================================================================
//static uint8_t C_status_Modbus = 0;
//static uint8_t C_u8state;
//static uint8_t C_u8lastError;
//static uint16_t C_u16InCnt, u16OutCnt;
static uint16_t C_u16errCnt;
static uint8_t C_u8lastRec;
//static uint32_t C_u32time, C_u32timeOut, C_u32overTime;

//static uint8_t  C_u8MBUnitID;                                        ///< Unit Identifier for individual unit-identification
static uint16_t C_u16MBTransactionID                      = 1;       ///< Transaction id for each transaction
static uint16_t C_u16MBProtocolID                         = 0;       ///< Constant
//static uint16_t C_ku16MBResponseTimeout          = 2000;

//=========================================================================================
static MODBUS SES_Modbus;

MODBUS_CLIENT_TELEGRAM Client_telegram[MAX_DEVICE*MAX_FRAME];  //50x3x2
MODBUS_CLIENT_TELEGRAM Ctrl_client_telegame[2*MAX_FRAME];

__eds__ __attribute ((eds))uint16_t TCP_Buffer[MAX_DEVICE+2][500];

// static uint16_t   Data42L[MAX_NUM_METER][350];

 UINT16 Sum_numof_Meter, Sum_Num_Frame;

//WORD SES_INPUTREGS_3X[INPUTREG_SIZE];
//WORD SES_HOLDINGREGS_4X[HOLDINGREG_SIZE];

unsigned char fctsupported[] =
{
    MB_FC_READ_COILS,
    MB_FC_READ_DISCRETE_INPUT,
    MB_FC_READ_HOLD_REGISTERS,
    MB_FC_READ_INPUT_REGISTER,
    MB_FC_WRITE_COIL,
    MB_FC_WRITE_REGISTER,
    MB_FC_WRITE_MULTIPLE_COILS,
    MB_FC_WRITE_MULTIPLE_REGISTERS
};
//============================= APP config ================================
APP_CONFIG AppConfig ;
static  uint8_t SerializedMACAddress[6] = {MY_DEFAULT_MAC_BYTE1, MY_DEFAULT_MAC_BYTE2, 
		MY_DEFAULT_MAC_BYTE3, MY_DEFAULT_MAC_BYTE4, MY_DEFAULT_MAC_BYTE5, MY_DEFAULT_MAC_BYTE6};

static void get_FC3(void);
static uint8_t SES_Modbus_validateAnswer(void);
static void SES_Modbus_TCPIP_Frame_Setup(void);
static void SES_Mosbus_TCPIP_Frame_Control(void);

static void InitAppConfig(void)
{
    memset((void *)&AppConfig, 0x00, sizeof(AppConfig));
    AppConfig.Flags.bInConfigMode = true ;
    
	//AppConfig.Flags.bInConfigMode = false ;
    SerializedMACAddress[5] = G42.IP[3];
    
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
     
//    AppConfig.Flags.bIsDHCPEnabled = false ;
//	AppConfig.MyIPAddr.Val = (uint32_t)G42.IP[0] | (uint32_t)G42.IP[1]<<8ul 
//					| (uint32_t)G42.IP[2]<<16ul | (uint32_t)G42.IP[3]<<24ul;
//	AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
//	AppConfig.MyMask.Val = (uint32_t)G42.SubnetMask[0] | (uint32_t)G42.SubnetMask[1]<<8ul 
//					| (uint32_t)G42.SubnetMask[2]<<16ul | (uint32_t)G42.SubnetMask[3]<<24ul;
//	AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
//	AppConfig.MyGateway.Val = (uint32_t)G42.Gateway[0] | (uint32_t)G42.Gateway[1]<<8ul 
//					| (uint32_t)G42.Gateway[2]<<16ul | (uint32_t)G42.Gateway[3]<<24ul;
//	AppConfig.PrimaryDNSServer.Val = (uint32_t)G42.DNS[0] | (uint32_t)G42.DNS[1]<<8ul  
//					| (uint32_t)G42.DNS[2]<<16ul  | (uint32_t)G42.DNS[3]<<24ul;
//	AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2<<8ul  
//					| MY_DEFAULT_SECONDARY_DNS_BYTE3<<16ul  | MY_DEFAULT_SECONDARY_DNS_BYTE4<<24ul; 
     
     
#endif
     // ?f?t?H???g?ÌNetBIOS?z?X?g?¼?ð?[?h?·?é
     memcpypgm2ram(AppConfig.NetBIOSName, (ROM void *)MY_DEFAULT_HOST_NAME, 16);
     FormatNetBIOSName(AppConfig.NetBIOSName);
}

static void SES_Modbus_TCPIP_Frame_Setup(void)
{
    uint8_t i,j;
    static uint8_t k=0;
    for(i=0; i<G42.Num_Dev_tcp; i++)
    {
        for(j=0; j<G42.Dev_tcp[i].Dev_Setup.NumFr; j++)
        {
            Client_telegram[k].INFOR.IP.val = MAKE_IPV4_ADDRESS(G42.Dev_tcp[i].IP[0],G42.Dev_tcp[i].IP[1],G42.Dev_tcp[i].IP[2],G42.Dev_tcp[i].IP[3]);
            Client_telegram[k].INFOR.PORT = MODBUS_PORT;
            Client_telegram[k].INFOR.u8id = i+1;
            Client_telegram[k].INFOR.u8fct = G42.Dev_tcp[i].Dev_Setup.Func;
            Client_telegram[k].INFOR.Frame.u16CoilsNo = G42.Dev_tcp[i].Dev_Setup.Fr[j].u16CoilsNo;
            Client_telegram[k].INFOR.Frame.u16RegAdd = G42.Dev_tcp[i].Dev_Setup.Fr[j].u16RegAdd;
            Client_telegram[k].INFOR.Frame.pointer = G42.Dev_tcp[i].Dev_Setup.Fr[j].pointer;
            Client_telegram[k].au16reg = TCP_Buffer[i]+Client_telegram[k].INFOR.Frame.pointer;          
            k++;
        }
    }
    //Error IP here   
}

static void SES_Mosbus_TCPIP_Frame_Control(void)
{
    uint8_t i;
    for (i = 0; i < gCtrlSetup.NumFr; i++)
    {
        Ctrl_client_telegame[i].INFOR.IP.val = gCtrlResponse.IP;
        Ctrl_client_telegame[i].INFOR.PORT = MODBUS_PORT;
        Ctrl_client_telegame[i].INFOR.u8id = gCtrlResponse.UID;
        Ctrl_client_telegame[i].INFOR.u8fct = gCtrlResponse.Func;
        Ctrl_client_telegame[i].INFOR.Frame.u16CoilsNo = gCtrlResponse.Fr[i].u16CoilsNo;
        Ctrl_client_telegame[i].INFOR.Frame.u16RegAdd = gCtrlResponse.Fr[i].u16RegAdd;
        Ctrl_client_telegame[i].INFOR.Frame.pointer = gCtrlResponse.Fr[i].pointer;
        Ctrl_client_telegame[i].au16reg = TCP_Buffer[MAX_DEVICE]+Ctrl_client_telegame[i].INFOR.Frame.pointer;  
    }
    for (i = 0; i < gCtrlResponse.NumFr; i++)
    {
        Ctrl_client_telegame[i+MAX_FRAME].INFOR.IP.val = gCtrlResponse.IP;
        Ctrl_client_telegame[i+MAX_FRAME].INFOR.PORT = MODBUS_PORT;
        Ctrl_client_telegame[i+MAX_FRAME].INFOR.u8id = gCtrlResponse.UID;
        Ctrl_client_telegame[i+MAX_FRAME].INFOR.u8fct = gCtrlResponse.Func;
        Ctrl_client_telegame[i+MAX_FRAME].INFOR.Frame.u16CoilsNo = gCtrlResponse.Fr[i].u16CoilsNo;
        Ctrl_client_telegame[i+MAX_FRAME].INFOR.Frame.u16RegAdd = gCtrlResponse.Fr[i].u16RegAdd;
        Ctrl_client_telegame[i+MAX_FRAME].INFOR.Frame.pointer = gCtrlResponse.Fr[i].pointer;
        Ctrl_client_telegame[i+MAX_FRAME].au16reg = TCP_Buffer[MAX_DEVICE+1]+Ctrl_client_telegame[i+MAX_FRAME].INFOR.Frame.pointer;  
    }
}

void SES_ModbusTCP_Client_Init(void)
{
        
    ENC_RST_IO = 0;
    DelayMs(100);
    ENC_RST_IO = 1;
    static uint16_t M=0;
    uint8_t i;
    InitAppConfig();
    StackInit();
    Device_TCP_Init();
    for(i=0; i<G42.Num_Dev_tcp; i++)
    {
        M = M+(uint16_t)(G42.Dev_tcp[i].Dev_Setup.NumFr);
    }
    MAX_Query_TCP = M;
    SES_Modbus_TCPIP_Frame_Setup();
    
 
}

static int8_t SES_Modbus_query( MODBUS_CLIENT_TELEGRAM telegram )
{
    uint16_t SES_Modbus_Size = 0;
    uint8_t i;
    uint16_t packetLength;

    //if(C_u8state != COM_IDLE) return -1;
    
    SES_Modbus.au16regs = telegram.au16reg;  // CA 2 DEU TRO DEN  au16data[16], VI  telegram.au16reg => au16data
    
    SES_Modbus.au8Buffer[SES_Modbus_Size++] = highByte(C_u16MBTransactionID);
    SES_Modbus.au8Buffer[SES_Modbus_Size++] = lowByte(C_u16MBTransactionID);
    SES_Modbus.au8Buffer[SES_Modbus_Size++] = highByte(C_u16MBProtocolID);
    SES_Modbus.au8Buffer[SES_Modbus_Size++] = lowByte(C_u16MBProtocolID);
    SES_Modbus_Size += 2;
    packetLength =SES_Modbus_Size;
    SES_Modbus.au8Buffer[SES_Modbus_Size++] = telegram.INFOR.u8id;
    SES_Modbus.au8Buffer[SES_Modbus_Size++] = telegram.INFOR.u8fct;
    
    SES_Modbus.au8Buffer[SES_Modbus_Size++] = highByte(telegram.INFOR.Frame.u16RegAdd);
    SES_Modbus.au8Buffer[SES_Modbus_Size++] = lowByte(telegram.INFOR.Frame.u16RegAdd);
    
    switch(telegram.INFOR.u8fct)
    {
        case MB_FC_READ_COILS:
        case MB_FC_READ_DISCRETE_INPUT:
        case MB_FC_READ_HOLD_REGISTERS:
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ] = highByte(telegram.INFOR.Frame.u16CoilsNo );
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ] = lowByte(telegram.INFOR.Frame.u16CoilsNo );
        case MB_FC_READ_INPUT_REGISTER:
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ] = highByte(telegram.INFOR.Frame.u16CoilsNo );
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ] = lowByte(telegram.INFOR.Frame.u16CoilsNo );
            break;
        case MB_FC_WRITE_COIL:
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ]      = ((telegram.au16reg[0] > 0) ? 0xff : 0);
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ]      = 0;
            break;
        case MB_FC_WRITE_REGISTER:
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ]      = highByte(telegram.au16reg[0]);
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ]      = lowByte(telegram.au16reg[0]);
            break;
        case MB_FC_WRITE_MULTIPLE_COILS: 
        case MB_FC_WRITE_MULTIPLE_REGISTERS:            
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ] = highByte(telegram.INFOR.Frame.u16CoilsNo);
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ] = lowByte(telegram.INFOR.Frame.u16CoilsNo);           
            SES_Modbus.au8Buffer[ SES_Modbus_Size++ ] = telegram.INFOR.Frame.u16CoilsNo << 1;           
            for (i = 0; i < telegram.INFOR.Frame.u16CoilsNo; i++)
            {
              SES_Modbus.au8Buffer[SES_Modbus_Size++] = highByte( telegram.au16reg[ i ] );
              SES_Modbus.au8Buffer[SES_Modbus_Size++] = lowByte(telegram.au16reg[ i ] );
            }
            break;  
    }
    
    SES_Modbus.au8Buffer[SES_Modbus_Size] = 0;
    packetLength = SES_Modbus_Size - packetLength;
    SES_Modbus.au8Buffer[4] = packetLength << 8;
    SES_Modbus.au8Buffer[5] = packetLength;     
    Frame_len = SES_Modbus_Size;
   //=================== CRC =====================================================
//    static uint16_t u16crc;
//    u16crc  = SES_Modbus_calcCRC( Frame_len);
//    SES_Modbus.au8Buffer[ Frame_len ] = u16crc >> 8;
//    Frame_len++;
//    SES_Modbus.au8Buffer[ Frame_len] = u16crc & 0x00ff;
//    Frame_len++; 
    
    
    //TCP_Send(&port[query], SES_Modbus.au8Buffer, Frame_len);
    timeout = TickGet();
    
    //C_u8state = COM_WAITING;
    C_u8lastRec = 0;
    return 0;
    
}

static void SES_ModbusReq(void)
{

    static uint8_t num_query;

    if(ModbusClientState == MBCS_DISCONNECT)
    {
        if(gCtrlInfor.Control_State == 1 && gCtrlInfor.Modbus_Type == MODBUS_RTU)
        {
            ctrl_query++;
            if(ctrl_query >= gCtrlSetup.NumFr + gCtrlResponse.NumFr)
            {
                Device_ResponseCtrl();
                ctrl_query = 0;
                CS = 0;
                gCtrlInfor.Control_State = 0;
            }
        }
        else
        {
            if(query - num_query >= (G42.Dev_tcp[Client_telegram[query].INFOR.u8id-1].Dev_Setup.NumFr - 1))
            {
                Device_GetData(Client_telegram[query].INFOR.u8id - 1, MODBUS_TCP);
                num_query++;
            }
            query++;
            if(query >= MAX_Query_TCP)
            {
                query = 0;
                num_query = 0;
            }
        }
        
        //query = 1;
    }
}


static uint8_t SES_Modbus_validateAnswer(void)
{
    // check message crc vs calculated crc
//    uint16_t u16MsgCRC =
//        ((SES_Modbus.au8Buffer[SES_Modbus.u8BufferSize - 2] << 8)
//         | SES_Modbus.au8Buffer[SES_Modbus.u8BufferSize - 1]); // combine the crc Low & High bytes
//    if ( SES_Modbus_calcCRC( SES_Modbus.u8BufferSize-2 ) != u16MsgCRC )
//    {
//        SES_Modbus.u16errCnt ++;
//        return NO_REPLY;
//    }

    // check exception
    if ((SES_Modbus.au8Buffer[ FunctionCode ] & 0x80) != 0)
    {
        C_u16errCnt ++;
        return ERR_EXCEPTION;
    }

    // check fct code
    boolean isSupported = false;
    uint8_t i;
    for (i = 0; i< sizeof( fctsupported ); i++)
    {
        if (fctsupported[i] == SES_Modbus.au8Buffer[ FunctionCode ])
        {
            isSupported = 1;
            break;
        }
    }
    if (!isSupported)
    {
        C_u16errCnt ++;
        return EXC_FUNC_CODE;
    }

    return 0; // OK, no exception code thrown
}
static void get_FC3(void)
{
    uint8_t  i;
  
    MB1_BLUE_Toggle();
    for (i=0; i< SES_Modbus.au8Buffer[ 8 ] /2; i++)
    {
        SES_Modbus.au16regs[ i ] = word(
                            SES_Modbus.au8Buffer[ 2*i + 9],
                            SES_Modbus.au8Buffer[ 2*i + 10 ]);      
    }
}


/*********************************************************
 *
 * Listens for ModBus requests and processes them.
 *
 *********************************************************/
static MODBUS_CLIENT_STATE ModbusRequestTask(void)
{
	

	static TCP_SOCKET	MySocket = INVALID_SOCKET;
	//static char		buffer[20];
	static DWORD	Timer;

	static unsigned char received = 0;

	static BYTE error_flag = 0;


	if( !bModbusClientInitialised )
	{
		ModbusClientState = MBCS_DISCONNECT;
		bModbusClientInitialised = 1;
	}
    SES_ModbusReq();
//    printf("S: %d\r\n",ModbusClientState);
//	printf("MySocket: %d\r\n",(int)MySocket);
	{	
		
		if((MySocket == INVALID_SOCKET && ModbusClientState != MBCS_DISCONNECT))
			ModbusClientState = MBCS_HOME;	

		// Handle session state
		switch(ModbusClientState)
		{
			case MBCS_HOME: // Opens the socket at the specified port to listen for request.
			{
				static char invalid_counts = 0;
			
				// Connect a socket to the remote TCP server
                if(gCtrlInfor.Control_State == 1 && gCtrlInfor.Modbus_Type == MODBUS_TCP)
                {
                    if (CS == 0)
                    {
                        Device_CtrlStrToBuffer();
                        SES_Mosbus_TCPIP_Frame_Control();
                        CS = 1;
                    }
                    MySocket = TCPOpen(Ctrl_client_telegame[ctrl_query].INFOR.IP.val, TCP_OPEN_IP_ADDRESS, Ctrl_client_telegame[ctrl_query].INFOR.PORT, TCP_PURPOSE_MODBUS_CLIENT);
                }
                else
                {
                    MySocket = TCPOpen(Client_telegram[query].INFOR.IP.val, TCP_OPEN_IP_ADDRESS, Client_telegram[query].INFOR.PORT, TCP_PURPOSE_MODBUS_CLIENT);
                }
				if(MySocket == INVALID_SOCKET)
				{
                    //printf("INVALID_SOCKET!!!\r\n");
					if( invalid_counts++ > 2 )	
					{
						invalid_counts = 0;
						//error_flag = 68;
//                        if(Client_telegram[query].INFOR.IID == 51)
//                        {
//                            G42.LOCAL_SERVER.Status = LS_Disconnected;
//                        }
//                        else
//                            G42.Interface[Client_telegram[query].INFOR.IID].Status = IT_Disconnected;
//                        
						ModbusClientState = MBCS_DISCONNECT;
					}	
					break;
				}
				invalid_counts = 0;
				Timer = TickGet();
				ModbusClientState = MBCS_SOCKET_OBTAINED;
			}	
				break;
			
			case MBCS_SOCKET_OBTAINED:  // This listens out for new requests and checks the message header.
			{
				if( !TCPIsConnected(MySocket))// || TCPWasReset(MySocket) )
				{
                   
					//if(TickGet()-Timer > 1.5*TICK_SECOND)
                    if((float)TickGet()-(float)Timer > 1.5 *(float)TICK_SECOND)
//					if((float)TickGet()-(float)Timer > 6.0f*(float)TICK_SECOND)
					{
						error_flag = 1;
//                        if(Client_telegram[query].INFOR.IID == 51)
//                        {
//                            G42.LOCAL_SERVER.Status = LS_Disconnected;
//                        }
//                        else
//                            G42.Weather_station[Client_telegram[query].INFOR.IID].Status  = IT_Disconnected;
                        ModbusClientState = MBCS_DISCONNECT;
					}
					break;
				}

				{
					WORD w;

					// This is starting of a new message. Clear the TCPIP rx buffer first.
					TCPDiscard(MySocket);

					
//                    if(query == 0)
//                    {
//                        Client_telegram[0].u8id ++;
//                        if(Client_telegram[0].u8id >= MAX_Query_TCP)
//                            Client_telegram[0].u8id = 1;
//                        Client_telegram[0].au16reg = Data42L[Client_telegram[0].u8id-1];
//                    }
                    if(gCtrlInfor.Control_State == 1 && gCtrlInfor.Modbus_Type == MODBUS_TCP)
                    {
                        SES_Modbus_query(Ctrl_client_telegame[ctrl_query]);
                    }
                    else
                    {
                        SES_Modbus_query(Client_telegram[query]);
                    }
                       
                    w = TCPPutArray(MySocket, SES_Modbus.au8Buffer, Frame_len);
			
                    if( w >= Frame_len)
					{
						// Sending completed.
						TCPFlush(MySocket);
						Timer = TickGet();
						received = 0;
						ModbusClientState = MBCS_WAIT_RESPONSE;
                        
						break;
					}
							
				}	
                break;	
			}
			
			case MBCS_WAIT_RESPONSE:
			{
				WORD w;
				if( !TCPIsConnected(MySocket))// || TCPWasReset(MySocket) )
				{

					if( (error_flag / 10) == 6 )
						error_flag += 150;
					else if( error_flag == 0 )
						error_flag = 30;  // Socket reset.
//                    if(Client_telegram[query].INFOR.IID == 51)
//                    {
//                        G42.LOCAL_SERVER.Status = LS_Disconnected;
//                    }
//                    else
//                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Disconnected;
					ModbusClientState = MBCS_DISCONNECT;
					break;
				}
                // check timeout
				if( (TickGet()-Timer) > (4*TICK_SECOND) )
				{

					// End debug.
//                    if(Client_telegram[query].INFOR.IID == 51)
//                    {
//                        G42.LOCAL_SERVER.Status = LS_Disconnected;
//                    }
//                    else
//                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Disconnected;
					ModbusClientState = MBCS_DISCONNECT;
					break;
				}

				w = TCPIsGetReady(MySocket);
                if(w < 6) break;
				received += TCPGetArray(MySocket, SES_Modbus.au8Buffer, w);
				
				// We are waiting for a MCU_REQUEST_BLOCK data here...
				uint8_t u8exception;
                u8exception = SES_Modbus_validateAnswer();
                if(!u8exception)
                {
//                    if(Client_telegram[query].INFOR.IID == 51)
//                    {
//                        G42.LOCAL_SERVER.Status = LS_Connected;
//                    }
//                    else
//                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Connected;
                    ModbusClientState = MBCS_PROCESS_RESPONSE;
                }
                else
                {
//                    if(Client_telegram[query].INFOR.IID == 51)
//                    {
//                        G42.LOCAL_SERVER.Status = LS_Disconnected;
//                    }
//                    else 
//                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Disconnected;
//                    printf("Exception %d",u8exception);
                }
		
				break;
			}	

			case MBCS_PROCESS_RESPONSE:  // Processes the request and forms the response packet.
			{
                switch (SES_Modbus.au8Buffer[FunctionCode])
                {
                    case MB_FC_READ_COILS:
                        ModbusClientState = MBCS_DISCONNECT;
                        break;
                    case MB_FC_READ_DISCRETE_INPUT:
                        ModbusClientState = MBCS_DISCONNECT;
                        break;
                    case MB_FC_READ_HOLD_REGISTERS:
                        get_FC3();
                        ModbusClientState = MBCS_DISCONNECT;
                        break;
                    case MB_FC_READ_INPUT_REGISTER:
                        get_FC3();
                        ModbusClientState = MBCS_DISCONNECT;
                        break;
                    case MB_FC_WRITE_COIL:
                        ModbusClientState = MBCS_DISCONNECT;
                        break;
                    case MB_FC_WRITE_REGISTER:
                        ModbusClientState = MBCS_DISCONNECT;
                        break;
                    case MB_FC_WRITE_MULTIPLE_COILS: 
                        ModbusClientState = MBCS_DISCONNECT;
                        break;
                    case MB_FC_WRITE_MULTIPLE_REGISTERS:
                        ModbusClientState = MBCS_DISCONNECT;
                        break;
                }
				
			}
				break;
			
			case MBCS_DISCONNECT:
			{	
				if( MySocket != INVALID_SOCKET )
				{
					TCPDiscard(MySocket);
					TCPDisconnect(MySocket);
					TCPClose(MySocket);
					MySocket = INVALID_SOCKET;
				}	
							
				ModbusClientState = (MODBUS_CLIENT_STATE)MBCS_HOME;
				break;
			}
			case MBCS_RELEASE:
			{
				// Call this if we are going to connect to another server.
				if( MySocket != INVALID_SOCKET )
				{
					TCPDiscard(MySocket);
					TCPDisconnect(MySocket);
					TCPClose(MySocket);
					MySocket = INVALID_SOCKET;
				}
				ModbusClientState = (MODBUS_CLIENT_STATE)MBCS_DISCONNECT;
				break;
			}
			default:
				break;
		}
		
		return ModbusClientState;
	}		
    
}  // #if defined(APP_USE_MODBUS_CLIENT).
void SES_ModbusTCPIP_Client_Process(void)
{
        StackTask() ;
        StackApplications();
        ModbusRequestTask(); 

}