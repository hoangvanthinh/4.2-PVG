
#include "../SES.h"


MODBUS SES_Modbus;
MODBUS_MASTER_TELEGRAM telegram[4];
uint16_t BUFF_INPUTREGS[125];
uint16_t au16data[125], au16data1[125], au16data2[125]; //!< data array for modbus network sharing
static uint8_t u8state; //!< machine state
static uint8_t u8query; //!< pointer to message query
static unsigned long u32wait;
static int8_t MAX_Query = 0;
//=============================================================================
static void SES_Modbus_setup(uint8_t u8id, char port, uint8_t u8txenpin);
static void SES_ModbusRTU_Frame_Transaction(void);
static void SES_Modbus_start(void);
static void SES_Modbus_setTimeOut( uint16_t u16timeOut); //!<write communication watch-dog timer
//static uint16_t SES_Modbus_getTimeOut(void); //!<get communication watch-dog timer value
//static bool SES_Modbus_getTimeOutState(); //!<get communication watch-dog timer state
static int8_t SES_Modbus_query( MODBUS_MASTER_TELEGRAM telegram ); //!<only for master
static int8_t SES_Modbus_Master_poll(void); //!<cyclic poll for master
static uint8_t validateAnswer();
static uint16_t SES_Modbus_getInCnt(void); //!<number of incoming messages
static uint16_t SES_Modbus_getOutCnt(void); //!<number of outcoming messages
static uint16_t SES_Modbus_getErrCnt(void); //!<error counter
//static uint8_t SES_Modbus_getID(void); //!<get slave ID between 1 and 247
static uint8_t SES_Modbus_getState(void);
//static uint8_t SES_Modbus_getLastError(); //!<get last error message
//static void SES_Modbus_setID( uint8_t u8id ); //!<write new ID for the slave
//static void setTxendPinOverTime( uint32_t u32overTime );
static int8_t SES_Modbus_getRxBuffer(void);
static void SES_Modbus_sendTxBuffer(void);
static uint16_t SES_Modbus_calcCRC(uint8_t u8length);
static void get_FC1();
static void get_FC3();
//=============================================================================


static const unsigned char fctsupported[] =
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


/**
 * @brief
 * This method validates master incoming messages
 *
 * @return 0 if OK, EXCEPTION if anything fails
 * @ingroup buffer
 */
static uint8_t validateAnswer()
{
    // check message crc vs calculated crc
    uint16_t u16MsgCRC =
        ((SES_Modbus.au8Buffer[SES_Modbus.u8BufferSize - 2] << 8)
         | SES_Modbus.au8Buffer[SES_Modbus.u8BufferSize - 1]); // combine the crc Low & High bytes
    if ( SES_Modbus_calcCRC( SES_Modbus.u8BufferSize-2 ) != u16MsgCRC )
    {
        SES_Modbus.u16errCnt ++;
        return NO_REPLY;
    }

    // check exception
    if ((SES_Modbus.au8Buffer[ FUNC ] & 0x80) != 0)
    {
        SES_Modbus.u16errCnt ++;
        return ERR_EXCEPTION;
    }

    // check fct code
    bool isSupported = false;
    uint8_t i = 0;
    for (i = 0; i< sizeof( fctsupported ); i++)
    {
        if (fctsupported[i] == SES_Modbus.au8Buffer[FUNC])
        {
            isSupported = 1;
            break;
        }
    }
    if (!isSupported)
    {
        SES_Modbus.u16errCnt ++;
        return EXC_FUNC_CODE;
    }

    return 0; // OK, no exception code thrown
}
void SES_ModbusRTU_Master_Process(void)
{
    switch( u8state ) 
     {
         case 0: 
           if (millis() > u32wait) u8state++; // wait state
           break;
         case 1: //===========================================================

           SES_Modbus_query( telegram[u8query] ); // send query (only once)
           u8state++;
           u8query++;

           if (u8query >= MAX_Query) u8query = 0;
           break;
         case 2:///////////////////////////////////////////////////////

           SES_Modbus_Master_poll(); // check incoming messages
           if (SES_Modbus_getState() == COM_IDLE) {
             u8state = 0;
             u32wait = millis() + SCAN_RATE; 

           }

           break;
     }

 
    
}

static void SES_ModbusRTU_Frame_Transaction(void)
{
   
//    telegram[0].u8id = 1; // slave address
//    telegram[0].u8fct = 4; // function code (this one is write a single register)
//    telegram[0].u16RegAdd = 0; // start address in slave
//    telegram[0].u16CoilsNo = 100; // number of elements (coils or registers) to read
//    telegram[0].au16reg = BUFF_INPUTREGS; // pointer to a memory array 
   
    telegram[0].u8id       = SES_Device->ID;
    telegram[0].u8fct      = SES_Device->Func; 
    telegram[0].u16RegAdd  = SES_Device->REGsAdd; 
    telegram[0].u16CoilsNo = SES_Device->NumberREGs;     
    telegram[0].au16reg    = BUFF_INPUTREGS; 
    
    telegram[1].u8id = 2; // slave address
    telegram[1].u8fct = 16; // function code (this one is write a single register)
    telegram[1].u16RegAdd = 0; // start address in slave
    telegram[1].u16CoilsNo = 100; // number of elements (coils or registers) to read
    telegram[1].au16reg = BUFF_INPUTREGS; // pointer to a memory array 
    
 
}
void SES_ModbusRTU_Master_Init(void)
{
    SES_ModbusRTU_Frame_Transaction();
    SES_Modbus_setup(0,0,RS485);
    MAX_Query = 2;
    SES_Modbus_start();   
    SES_Modbus_setTimeOut(TIMEOUT_RTU);
    u32wait = millis() + 1000;
    u8state = u8query = 0;    
}
static void SES_Modbus_setup(uint8_t u8id, char port, uint8_t u8txenpin)
{    
    SES_Modbus.u8id = u8id;
    SES_Modbus.u8txenpin = u8txenpin;
    SES_Modbus.u16timeOut = 1000;
    SES_Modbus.u32overTime = 0;
     
}

static void SES_Modbus_start(void)
{
    if(SES_Modbus.u8txenpin > 1)
    {
    }
    //while(UART1_Read() >= 0);
    SES_Modbus.u8lastRec = SES_Modbus.u8BufferSize = 0;
    SES_Modbus.u16InCnt = SES_Modbus.u16OutCnt = SES_Modbus.u16errCnt = 0;
    
      
}
/**
 * @brief
 * Method to write a new slave ID address
 *
 * @param 	u8id	new slave address between 1 and 247
 * @ingroup setup
 */
//static void SES_Modbus_setID(uint8_t u8id)
//{
//    if((SES_Modbus.u8id != 0) && (SES_Modbus.u8id <= 247))
//    {
//        SES_Modbus.u8id = u8id;
//    }
//}
/**
 * @brief
 * Method to write the overtime count for txend pin.
 * It waits until count reaches 0 after the transfer is done.
 * With this, you can extend the time between txempty and
 * the falling edge if needed.
 *
 * @param 	uint32_t	overtime count for txend pin
 * @ingroup setup
 */
//static void SES_Modbus_setTxendPinOverTime(uint32_t u32overTime)
//{
//    SES_Modbus.u32overTime = u32overTime;   
//}
/**
 * @brief
 * Method to read current slave ID address
 *
 * @return u8id	current slave address between 1 and 247
 * @ingroup setup
 */
//static uint8_t SES_Modbus_getID(void)
//{
//    return SES_Modbus.u8id;
//}
/**
 * @brief
 * Initialize time-out parameter
 *
 * Call once class has been instantiated, typically within setup().
 * The time-out timer is reset each time that there is a successful communication
 * between Master and Slave. It works for both.
 *
 * @param time-out value (ms)
 * @ingroup setup
 */
static void SES_Modbus_setTimeOut( uint16_t u16timeOut)
{
    SES_Modbus.u16timeOut = u16timeOut;
}
//static bool SES_Modbus_getTimeOutState(void)
//{
//    return((unsigned long)(millis() - SES_Modbus.u32timeOut) > (unsigned long)SES_Modbus.u16timeOut);
//}
/**
 * @brief
 * Get input messages counter value
 * This can be useful to diagnose communication
 *
 * @return input messages counter
 * @ingroup buffer
 */
static uint16_t SES_Modbus_getInCnt(void)
{
    return SES_Modbus.u16InCnt;
}
/**
 * @brief
 * Get transmitted messages counter value
 * This can be useful to diagnose communication
 *
 * @return transmitted messages counter
 * @ingroup buffer
 */
static uint16_t SES_Modbus_getOutCnt(void)
{
    return SES_Modbus.u16OutCnt;
}

/**
 * @brief
 * Get errors counter value
 * This can be useful to diagnose communication
 *
 * @return errors counter
 * @ingroup buffer
 */
static uint16_t SES_Modbus_getErrCnt(void)
{
    return SES_Modbus.u16errCnt;
}
/**
 * Get modbus master state
 *
 * @return = 0 IDLE, = 1 WAITING FOR ANSWER
 * @ingroup buffer
 */
static uint8_t SES_Modbus_getState(void)
{
    return SES_Modbus.u8state;
}
/**
 * Get the last error in the protocol processor
 *
 * @returnreturn   NO_REPLY = 255      Time-out
 * @return   EXC_FUNC_CODE = 1   Function code not available
 * @return   EXC_ADDR_RANGE = 2  Address beyond available space for Modbus registers
 * @return   EXC_REGS_QUANT = 3  Coils or registers number beyond the available space
 * @ingroup buffer
 */
//static uint8_t SES_Modbus_getLastError(void)
//{
//    return SES_Modbus.u8lastError;
//}


/**
 * @brief
 * *** Only Modbus Master ***
 * Generate a query to an slave with a modbus_t telegram structure
 * The Master must be in COM_IDLE mode. After it, its state would be COM_WAITING.
 * This method has to be called only in loop() section.
 *
 * @see modbus_t
 * @param modbus_t  modbus telegram structure (id, fct, ...)
 * @ingroup loop
 * @todo finish function 15
 */
static int8_t SES_Modbus_query( MODBUS_MASTER_TELEGRAM telegram )
{
    uint8_t u8regsno, u8bytesno;
    uint16_t *au16regs;
    au16regs = telegram.au16reg;
    
    if (SES_Modbus.u8id!=0) return -2;
    if (SES_Modbus.u8state != COM_IDLE) return -1;

    if ((telegram.u8id==0) || (telegram.u8id>247)) return -3;

    SES_Modbus.au16regs = telegram.au16reg;

    // telegram header
    SES_Modbus.au8Buffer[ ID ]         = telegram.u8id;
    SES_Modbus.au8Buffer[ FUNC ]       = telegram.u8fct;
    SES_Modbus.au8Buffer[ ADD_HI ]     = highByte(telegram.u16RegAdd );
    SES_Modbus.au8Buffer[ ADD_LO ]     = lowByte( telegram.u16RegAdd );

    switch( telegram.u8fct )
    {
    case MB_FC_READ_COILS:
    case MB_FC_READ_DISCRETE_INPUT:
    case MB_FC_READ_HOLD_REGISTERS:
        SES_Modbus.au8Buffer[ NB_HI ]      = highByte(telegram.u16CoilsNo );
        SES_Modbus.au8Buffer[ NB_LO ]      = lowByte( telegram.u16CoilsNo );
        SES_Modbus.u8BufferSize = 6;
        break;
    case MB_FC_READ_INPUT_REGISTER:
        SES_Modbus.au8Buffer[ NB_HI ]      = highByte(telegram.u16CoilsNo );
        SES_Modbus.au8Buffer[ NB_LO ]      = lowByte( telegram.u16CoilsNo );
        SES_Modbus.u8BufferSize = 6;
        break;
    case MB_FC_WRITE_COIL:
        SES_Modbus.au8Buffer[ NB_HI ]      = ((au16regs[0] > 0) ? 0xff : 0);
        SES_Modbus.au8Buffer[ NB_LO ]      = 0;
        SES_Modbus.u8BufferSize = 6;
        break;
    case MB_FC_WRITE_REGISTER:
        SES_Modbus.au8Buffer[ NB_HI ]      = highByte(au16regs[0]);
        SES_Modbus.au8Buffer[ NB_LO ]      = lowByte(au16regs[0]);
        SES_Modbus.u8BufferSize = 6;
        break;
    case MB_FC_WRITE_MULTIPLE_COILS: // TODO: implement "sending coils"
        u8regsno = telegram.u16CoilsNo / 16;
        u8bytesno = u8regsno * 2;
        if ((telegram.u16CoilsNo % 16) != 0)
        {
            u8bytesno++;
            u8regsno++;
        }

        SES_Modbus.au8Buffer[ NB_HI ]      = highByte(telegram.u16CoilsNo );
        SES_Modbus.au8Buffer[ NB_LO ]      = lowByte( telegram.u16CoilsNo );
        SES_Modbus.au8Buffer[ BYTE_CNT ]    = u8bytesno;
        SES_Modbus.u8BufferSize = 7;
        uint16_t i=0;
        for (i = 0; i < u8bytesno; i++)
        {
            if(i%2)
            {
                SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = lowByte( au16regs[ i/2 ] );
            }
            else
            {
                SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = highByte( au16regs[ i/2] );
            }          
            SES_Modbus.u8BufferSize++;
        }
        break;

    case MB_FC_WRITE_MULTIPLE_REGISTERS:
        SES_Modbus.au8Buffer[ NB_HI ]      = highByte(telegram.u16CoilsNo );
        SES_Modbus.au8Buffer[ NB_LO ]      = lowByte( telegram.u16CoilsNo );
        SES_Modbus.au8Buffer[ BYTE_CNT ]    = (uint8_t) ( telegram.u16CoilsNo * 2 );
        SES_Modbus.u8BufferSize = 7;
       
        for (i=0; i< telegram.u16CoilsNo; i++)
        {
            SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = highByte( SES_Modbus.au16regs[ i ] );
            SES_Modbus.u8BufferSize++;
            SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = lowByte( SES_Modbus.au16regs[ i ] );
            SES_Modbus.u8BufferSize++;
        }
        break;
    }

    SES_Modbus_sendTxBuffer();
    SES_Modbus.u8state = COM_WAITING;
    SES_Modbus.u8lastError = 0;
    return 0;
}

/**
 * @brief *** Only for Modbus Master ***
 * This method checks if there is any incoming answer if pending.
 * If there is no answer, it would change Master state to COM_IDLE.
 * This method must be called only at loop section.
 * Avoid any delay() function.
 *
 * Any incoming data would be redirected to au16regs pointer,
 * as defined in its modbus_t query telegram.
 *
 * @params	nothing
 * @return errors counter
 * @ingroup loop
 */

static int8_t SES_Modbus_Master_poll(void)
{
    // check if there is any incoming frame
	uint8_t u8current;
    u8current = UART1_RxDataAvailable();

    if ((unsigned long)(millis() - SES_Modbus.u32timeOut) > (unsigned long)SES_Modbus.u16timeOut)
    {
        SES_Modbus.u8state = COM_IDLE;
        SES_Modbus.u8lastError = NO_REPLY;
        SES_Modbus.u16errCnt++;
        return 0;
    }

    if (u8current == 0) return 0;

    // check T35 after frame end or still no frame end
    if (u8current != SES_Modbus.u8lastRec)
    {
        SES_Modbus.u8lastRec = u8current;
        SES_Modbus.u32time = millis();
        return 0;
    }
    if ((unsigned long)(millis() - SES_Modbus.u32time) < (unsigned long)T35) return 0;

    // transfer Serial buffer frame to auBuffer
    SES_Modbus.u8lastRec = 0;
    uint8_t i8state = SES_Modbus_getRxBuffer();
    if (i8state < 6) //7 was incorrect for functions 1 and 2 the smallest frame could be 6 bytes long
    {
        SES_Modbus.u8state = COM_IDLE;
        SES_Modbus.u16errCnt++;
        return i8state;
    }

    // validate message: id, CRC, FCT, exception
    uint8_t u8exception = validateAnswer();
    if (u8exception != 0)
    {
        SES_Modbus.u8state = COM_IDLE;
        return u8exception;
    }

    // process answer
    switch( SES_Modbus.au8Buffer[ FUNC ] )
    {
    case MB_FC_READ_COILS:
        break;
    case MB_FC_READ_DISCRETE_INPUT:
        // call get_FC1 to transfer the incoming message to au16regs buffer
        get_FC1( );
        break;
    case MB_FC_READ_INPUT_REGISTER:
        get_FC3( );
        break;
    case MB_FC_READ_HOLD_REGISTERS :
        // call get_FC3 to transfer the incoming message to au16regs buffer
        get_FC3( );
        break;
    case MB_FC_WRITE_COIL: 
        break;
    case MB_FC_WRITE_REGISTER :
        break;
    case MB_FC_WRITE_MULTIPLE_COILS:
        break;
    case MB_FC_WRITE_MULTIPLE_REGISTERS :
        // nothing to do
        break;
    default:
        break;
    }
    SES_Modbus.u8state = COM_IDLE;
    return SES_Modbus.u8BufferSize;
}

/* _____PRIVATE FUNCTIONS_____________________________________________________ */

/**
 * @brief
 * This method moves Serial buffer data to the Modbus au8Buffer.
 *
 * @return buffer size if OK, ERR_BUFF_OVERFLOW if u8BufferSize >= MAX_BUFFER
 * @ingroup buffer
 */
static int8_t SES_Modbus_getRxBuffer(void)
{
    bool bBuffOverflow = false;

    if (SES_Modbus.u8txenpin > 1)
    {
        //digitalWrite( u8txenpin, LOW );
        //set 485
    }

    SES_Modbus.u8BufferSize = 0;
    while ( UART1_RxDataAvailable() )
    {
        SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = UART1_Read();
        SES_Modbus.u8BufferSize ++;

        if (SES_Modbus.u8BufferSize >= MAX_BUFFER) bBuffOverflow = true;
    }
    SES_Modbus.u16InCnt++;

    if (bBuffOverflow)
    {
        SES_Modbus.u16errCnt++;
        return ERR_BUFF_OVERFLOW;
    }
    return SES_Modbus.u8BufferSize;
}



/**
 * @brief
 * This method transmits au8Buffer to Serial line.
 * Only if u8txenpin != 0, there is a flow handling in order to keep
 * the RS485 transceiver in output state as long as the message is being sent.
 * This is done with UCSRxA register.
 * The CRC is appended to the buffer before starting to send it.
 *
 * @param nothing
 * @return nothing
 * @ingroup buffer
 */
static void SES_Modbus_sendTxBuffer(void)
{
    // append CRC to message
    uint16_t u16crc = SES_Modbus_calcCRC( SES_Modbus.u8BufferSize );
    SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = u16crc >> 8;
    SES_Modbus.u8BufferSize++;
    SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = u16crc & 0x00ff;
    SES_Modbus.u8BufferSize++;

    if (SES_Modbus.u8txenpin > 1)
    {
        EN_RS485_1_SetHigh();
        // set RS485 transceiver to transmit mode
        //digitalWrite( u8txenpin, HIGH );//////////////////////////////////////////////////////////////////
    }

    // transfer buffer to serial line
    int s;
    s = UART1_WriteBuffer( SES_Modbus.au8Buffer, SES_Modbus.u8BufferSize );

    if (SES_Modbus.u8txenpin > 1)
    {
        // must wait transmission end before changing pin state
        // soft serial does not need it since it is blocking
        // ...but the implementation in SoftwareSerial does nothing
        // anyway, so no harm in calling it.
        
        //port->flush();
        while(!UART1_IsTxDone());
        // return RS485 transceiver to receive mode
        volatile uint32_t u32overTimeCountDown = SES_Modbus.u32overTime;
        while ( u32overTimeCountDown-- > 0);
        EN_RS485_1_SetLow();
        //digitalWrite( u8txenpin, LOW );////////////////////////////////////////////////////////////////////////////////
    }
    //while(UART1_Read() >= 0);

    SES_Modbus.u8BufferSize = 0;

    // set time-out for master
    SES_Modbus.u32timeOut = millis();

    // increase message counter
    SES_Modbus.u16OutCnt++;
}
/**
 * @brief
 * This method calculates CRC
 *
 * @return uint16_t calculated CRC value for the message
 * @ingroup buffer
 */
static uint16_t SES_Modbus_calcCRC(uint8_t u8length)
{
    unsigned int temp, temp2, flag;
    temp = 0xFFFF;
    unsigned char i=0;
    for (i = 0; i < u8length; i++)
    {
        temp = temp ^ SES_Modbus.au8Buffer[i];
        unsigned char j=0;
        for (j = 1; j <= 8; j++)
        {
            flag = temp & 0x0001;
            temp >>=1;
            if (flag)
                temp ^= 0xA001;
        }
    }
    // Reverse byte order.
    temp2 = temp >> 8;
    temp = (temp << 8) | temp2;
    temp &= 0xFFFF;
    // the returned value is already swapped
    // crcLo byte is first & crcHi byte is last
    return temp;
}


/**
 * @brief
 * This method builds an exception message
 *
 * @ingroup buffer
 */
static void buildException( uint8_t u8exception )
{
    uint8_t u8func = SES_Modbus.au8Buffer[ FUNC ];  // get the original FUNC code

    SES_Modbus.au8Buffer[ ID ]      = SES_Modbus.u8id;
    SES_Modbus.au8Buffer[ FUNC ]    = u8func + 0x80;
    SES_Modbus.au8Buffer[ 2 ]       = u8exception;
    SES_Modbus.u8BufferSize         = EXCEPTION_SIZE;
}
/**
 * This method processes functions 1 & 2 (for master)
 * This method puts the slave answer into master data buffer
 *
 * @ingroup register
 * TODO: finish its implementation
 */
static void get_FC1()
{
    uint8_t u8byte, i;
    u8byte = 3;
     for (i=0; i< SES_Modbus.au8Buffer[2]; i++) {
        
        if(i%2)
        {
            SES_Modbus.au16regs[i/2]= word(SES_Modbus.au8Buffer[i+u8byte], lowByte(SES_Modbus.au16regs[i/2]));
        }
        else
        {
           
            SES_Modbus.au16regs[i/2]= word(highByte(SES_Modbus.au16regs[i/2]), SES_Modbus.au8Buffer[i+u8byte]); 
        }
        
     }
}
/**
 * This method processes functions 3 & 4 (for master)
 * This method puts the slave answer into master data buffer
 *
 * @ingroup register
 */
static void get_FC3()
{
    uint8_t u8byte, i;
    u8byte = 3;

    for (i=0; i< SES_Modbus.au8Buffer[ 2 ] /2; i++)
    {
        SES_Modbus.au16regs[ i ] = word(
                            SES_Modbus.au8Buffer[ u8byte ],
                            SES_Modbus.au8Buffer[ u8byte +1 ]);
        u8byte += 2;
    }
}

