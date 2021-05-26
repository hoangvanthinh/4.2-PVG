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

static UINT16 MAX_Query = 0;
static char bModbusClientInitialised = 0;
static MODBUS_CLIENT_STATE ModbusClientState = (MODBUS_CLIENT_STATE)MBCS_HOME;
static uint16_t Frame_len;
static uint32_t timeout;
static UINT16 query = 0;
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
//static MODBUS_CLIENT_TELEGRAM Client_telegram[MAX_NUM_METER*NUM_FRAME_METER*2];

MODBUS_CLIENT_TELEGRAM Client_telegram[300];  //50x3x2
// static uint16_t   Data42L[MAX_NUM_METER][350];
__eds__ __attribute ((eds))uint16_t   Data42L_Meter [MAX_NUM_METER][350];

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
//	AppConfig.Flags.bIsDHCPEnabled = false ;
//	AppConfig.MyIPAddr.Val = MY_DEFAULT_IP_ADDR_BYTE1 | MY_DEFAULT_IP_ADDR_BYTE2<<8ul 
//					| MY_DEFAULT_IP_ADDR_BYTE3<<16ul | MY_DEFAULT_IP_ADDR_BYTE4<<24ul;
//	AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
//	AppConfig.MyMask.Val = MY_DEFAULT_MASK_BYTE1 | MY_DEFAULT_MASK_BYTE2<<8ul 
//					| MY_DEFAULT_MASK_BYTE3<<16ul | MY_DEFAULT_MASK_BYTE4<<24ul;
//	AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
//	AppConfig.MyGateway.Val = MY_DEFAULT_GATE_BYTE1 | MY_DEFAULT_GATE_BYTE2<<8ul 
//					| MY_DEFAULT_GATE_BYTE3<<16ul | MY_DEFAULT_GATE_BYTE4<<24ul;
//	AppConfig.PrimaryDNSServer.Val = MY_DEFAULT_PRIMARY_DNS_BYTE1 | MY_DEFAULT_PRIMARY_DNS_BYTE2<<8ul  
//					| MY_DEFAULT_PRIMARY_DNS_BYTE3<<16ul  | MY_DEFAULT_PRIMARY_DNS_BYTE4<<24ul;
//	AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2<<8ul  
//					| MY_DEFAULT_SECONDARY_DNS_BYTE3<<16ul  | MY_DEFAULT_SECONDARY_DNS_BYTE4<<24ul;
     
    AppConfig.Flags.bIsDHCPEnabled = false ;
	AppConfig.MyIPAddr.Val = (uint32_t)G42.IP[0] | (uint32_t)G42.IP[1]<<8ul 
					| (uint32_t)G42.IP[2]<<16ul | (uint32_t)G42.IP[3]<<24ul;
	AppConfig.DefaultIPAddr.Val = AppConfig.MyIPAddr.Val;
	AppConfig.MyMask.Val = (uint32_t)G42.SubnetMask[0] | (uint32_t)G42.SubnetMask[1]<<8ul 
					| (uint32_t)G42.SubnetMask[2]<<16ul | (uint32_t)G42.SubnetMask[3]<<24ul;
	AppConfig.DefaultMask.Val = AppConfig.MyMask.Val;
	AppConfig.MyGateway.Val = (uint32_t)G42.Gateway[0] | (uint32_t)G42.Gateway[1]<<8ul 
					| (uint32_t)G42.Gateway[2]<<16ul | (uint32_t)G42.Gateway[3]<<24ul;
	AppConfig.PrimaryDNSServer.Val = (uint32_t)G42.DNS[0] | (uint32_t)G42.DNS[1]<<8ul  
					| (uint32_t)G42.DNS[2]<<16ul  | (uint32_t)G42.DNS[3]<<24ul;
	AppConfig.SecondaryDNSServer.Val = MY_DEFAULT_SECONDARY_DNS_BYTE1 | MY_DEFAULT_SECONDARY_DNS_BYTE2<<8ul  
					| MY_DEFAULT_SECONDARY_DNS_BYTE3<<16ul  | MY_DEFAULT_SECONDARY_DNS_BYTE4<<24ul; 
     
     
#endif
     // ?f?t?H???g?ÌNetBIOS?z?X?g?¼?ð?[?h?·?é
     memcpypgm2ram(AppConfig.NetBIOSName, (ROM void *)MY_DEFAULT_HOST_NAME, 16);
     FormatNetBIOSName(AppConfig.NetBIOSName);
}

static void SES_Modbus_TCPIP_Frame_Setup(void)
{
    static INT16 n = 0,m = 0,f=0;
    static INT16 i;
    Sum_numof_Meter = 0;
    // TINH TONG SO METER TRONG HE THONG
    for(n = 0; n< G42.Num_Interface; n++)
        Sum_numof_Meter += G42.Interface[n].Num_Meter;
//    printf("Meters: %d \r",Sum_numof_Meter);
    // TONG SO FRAME GUI DI
    Sum_Num_Frame = Sum_numof_Meter*NUM_FRAME_METER;
    // GAN IP VA UID
    for(n = 0; n < G42.Num_Interface; n++)
    {
        
        for(i = 1;i <= G42.Interface[n].Num_Meter;i++)
        {
            G42.Meter[m].ID = i;
            G42.Meter[m].IP[0] = G42.Interface[n].IP[0];
            G42.Meter[m].IP[1] = G42.Interface[n].IP[1];
            G42.Meter[m].IP[2] = G42.Interface[n].IP[2];
            G42.Meter[m].IP[3] = G42.Interface[n].IP[3];    
            G42.Meter[m].IID = n;
            m++;
        }
    }

    
    FRAME Fr42[3];
    Fr42[0].u16RegAdd = 0;
    Fr42[0].u16CoilsNo = 112;
    Fr42[0].pointer = 0;
    
    Fr42[1].u16RegAdd = 199;//200
    Fr42[1].u16CoilsNo = 101;//100
    Fr42[1].pointer = 112;//0+112
    
    Fr42[2].u16RegAdd = 300;
    Fr42[2].u16CoilsNo = 50;//47
    Fr42[2].pointer = 213;  //212 
    //---------------------------- HMI LOCAL -----------------------------------
    for(n=0;n<Sum_numof_Meter;n++)
    {
        for(i=0;i<NUM_FRAME_METER;i++)
        {
            Client_telegram[f].INFOR.IP.val    = MAKE_IPV4_ADDRESS(G42.LOCAL_SERVER.IP[0], G42.LOCAL_SERVER.IP[1], G42.LOCAL_SERVER.IP[2], G42.LOCAL_SERVER.IP[3]);//2
            Client_telegram[f].INFOR.PORT = G42.LOCAL_SERVER.PORT.val16;
            Client_telegram[f].INFOR.IID = LocalSID;
            Client_telegram[f].INFOR.u8id  = n+1; // Meter address
            Client_telegram[f].INFOR.u8fct = MB_FC_WRITE_MULTIPLE_REGISTERS; // function code (this one is write a single register)    
            Client_telegram[f].INFOR.Frame.u16RegAdd = Fr42[i].u16RegAdd;
            Client_telegram[f].INFOR.Frame.u16CoilsNo = Fr42[i].u16CoilsNo;
            Client_telegram[f].INFOR.Frame.pointer   = Fr42[i].pointer;
            Client_telegram[f].au16reg = Data42L_Meter[n] + Client_telegram[f].INFOR.Frame.pointer; // pointer to a memory array   
            f++;
        }
    }
//    printf("F1: %d\r",f);
    // FRAME CUA CAC METER-> INTERFACE = 3 Frame
    for(n = 0; n < Sum_numof_Meter; n++ )
    { 
        for(i=0;i<NUM_FRAME_METER;i++)
        {
            Client_telegram[f].INFOR.IP.val = MAKE_IPV4_ADDRESS(G42.Meter[n].IP[0], G42.Meter[n].IP[1], G42.Meter[n].IP[2], G42.Meter[n].IP[3]);// P2120
            Client_telegram[f].INFOR.PORT = MODBUS_PORT;
            Client_telegram[f].INFOR.IID = G42.Meter[n].IID;
            Client_telegram[f].INFOR.u8id = G42.Meter[n].ID; // slave address
            Client_telegram[f].INFOR.u8fct = MB_FC_READ_HOLD_REGISTERS; // function code (this one is write a single register)

            Client_telegram[f].INFOR.Frame.u16RegAdd  = Fr42[i].u16RegAdd;
            Client_telegram[f].INFOR.Frame.u16CoilsNo = Fr42[i].u16CoilsNo;
            Client_telegram[f].INFOR.Frame.pointer    = Fr42[i].pointer;
            
            Client_telegram[f].au16reg = Data42L_Meter[n] + Client_telegram[f].INFOR.Frame.pointer; // pointer to a memory array   
            f++;
        }
    }

    MAX_Query = Sum_numof_Meter*NUM_FRAME_METER*2;
//    printf("F: %d,MAX_Query: %d \r",f,MAX_Query);
}
void SES_ModbusTCP_Client_Init(void)
{
        
    ENC_RST_IO = 0;
    DelayMs(100);
    ENC_RST_IO = 1;
    
    InitAppConfig() ;
    StackInit() ;
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

    //printf("State: %d",ModbusClientState);
    if(ModbusClientState == MBCS_DISCONNECT)
    {
        
        query++;
        if(query >= MAX_Query)
            query = 0;
        
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

				MySocket = TCPOpen(Client_telegram[query].INFOR.IP.val, TCP_OPEN_IP_ADDRESS, Client_telegram[query].INFOR.PORT, TCP_PURPOSE_MODBUS_CLIENT);
				if(MySocket == INVALID_SOCKET)
				{
                    //printf("INVALID_SOCKET!!!\r\n");
					if( invalid_counts++ > 2 )	
					{
						invalid_counts = 0;
						//error_flag = 68;
                        if(Client_telegram[query].INFOR.IID == 51)
                        {
                            G42.LOCAL_SERVER.Status = LS_Disconnected;
                        }
                        else
                            G42.Interface[Client_telegram[query].INFOR.IID].Status = IT_Disconnected;
                        
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
                    if(Client_telegram[query].INFOR.IID == 51)
                    {
                        G42.LOCAL_SERVER.Status = LS_Disconnected;
                    }
                    else
                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Disconnected;
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
//                        if(Client_telegram[0].u8id >= MAX_Query)
//                            Client_telegram[0].u8id = 1;
//                        Client_telegram[0].au16reg = Data42L[Client_telegram[0].u8id-1];
//                    }
                    
                    SES_Modbus_query(Client_telegram[query]);
                       
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
                    if(Client_telegram[query].INFOR.IID == 51)
                    {
                        G42.LOCAL_SERVER.Status = LS_Disconnected;
                    }
                    else
                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Disconnected;
					ModbusClientState = MBCS_DISCONNECT;
					break;
				}
                // check timeout
				if( (TickGet()-Timer) > (4*TICK_SECOND) )
				{

					// End debug.
                    if(Client_telegram[query].INFOR.IID == 51)
                    {
                        G42.LOCAL_SERVER.Status = LS_Disconnected;
                    }
                    else
                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Disconnected;
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
                    if(Client_telegram[query].INFOR.IID == 51)
                    {
                        G42.LOCAL_SERVER.Status = LS_Connected;
                    }
                    else
                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Connected;
                    ModbusClientState = MBCS_PROCESS_RESPONSE;
                }
                else
                {
                    if(Client_telegram[query].INFOR.IID == 51)
                    {
                        G42.LOCAL_SERVER.Status = LS_Disconnected;
                    }
                    else 
                        G42.Interface[Client_telegram[query].INFOR.IID].Status  = IT_Disconnected;
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