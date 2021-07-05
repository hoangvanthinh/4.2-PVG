

#include "../SES.h"

struct SETUP_42 SETUP_G_42;
static MODBUS SES_Modbus;
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

//==============================================================================
static void SES_Modbus_sendTxBuffer(void);
static int8_t SES_Modbus_getRxBuffer(void);
static uint16_t SES_Modbus_calcCRC(uint8_t u8length);

static uint8_t validateRequest();

static int8_t process_FC1( uint16_t *regs, uint8_t u8size );
static int8_t process_FC3( uint16_t *regs, uint8_t u8size );
static int8_t process_FC5( uint16_t *regs, uint8_t u8size );
static int8_t process_FC6( uint16_t *regs, uint8_t u8size );
static int8_t process_FC15( uint16_t *regs, uint8_t u8size );
static int8_t process_FC16( uint16_t *regs, uint8_t u8size );
static void buildException( uint8_t u8exception ); // build exception message

static void Modbus(uint8_t u8id, char port, uint8_t u8txenpin);
//static void SES_Modbus_setTimeOut( uint16_t u16timeOut); //!<write communication watch-dog timer
//static uint16_t SES_Modbus_getTimeOut(); //!<get communication watch-dog timer value
//static bool SES_Modbus_getTimeOutState(); //!<get communication watch-dog timer state

//static int8_t SES_Modbus_Slave_poll( uint16_t *regs, uint16_t u8size ); //!<cyclic poll for slave
static int8_t SES_ModbusRTU_Slave_poll( uint16_t *regs, uint16_t u8size );
//static uint16_t SES_Modbus_getInCnt(); //!<number of incoming messages
//static uint16_t SES_Modbus_getOutCnt(); //!<number of outcoming messages
//static uint16_t SES_Modbus_getErrCnt(); //!<error counter
//static uint8_t SES_Modbus_getID(); //!<get slave ID between 1 and 247
//static uint8_t SES_Modbus_getState();
//static uint8_t SES_Modbus_getLastError(); //!<get last error message
//static void SES_Modbus_setID( uint8_t u8id ); //!<write new ID for the slave
//==============================================================================


static void Modbus(uint8_t u8id, char port, uint8_t u8txenpin)
{    
    SES_Modbus.u8id = u8id;
    SES_Modbus.u8txenpin = u8txenpin;
    SES_Modbus.u16timeOut = 1000;
    SES_Modbus.u32overTime = 0;
     
}

void SES_ModbusRTU_Slave_start(void)
{
    Modbus(1,0,USB);  // Khoi tao Modbus Slave ID 1
    if(SES_Modbus.u8txenpin > 1)
    {
//        EN_RS485_SetLow();
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
//static uint8_t SES_Modbus_getID()
//{
//    return SES_Modbus.u8id;
//}

/**
 * @brief
 * Get input messages counter value
 * This can be useful to diagnose communication
 *
 * @return input messages counter
 * @ingroup buffer
 */
//static uint16_t SES_Modbus_getInCnt()
//{
//    return SES_Modbus.u16InCnt;
//}
/**
 * @brief
 * Get transmitted messages counter value
 * This can be useful to diagnose communication
 *
 * @return transmitted messages counter
 * @ingroup buffer
 */
//static uint16_t SES_Modbus_getOutCnt()
//{
//    return SES_Modbus.u16OutCnt;
//}

/**
 * @brief
 * Get errors counter value
 * This can be useful to diagnose communication
 *
 * @return errors counter
 * @ingroup buffer
 */
//static uint16_t SES_Modbus_getErrCnt()
//{
//    return SES_Modbus.u16errCnt;
//}
/**
 * Get modbus master state
 *
 * @return = 0 IDLE, = 1 WAITING FOR ANSWER
 * @ingroup buffer
 */
//static uint8_t SES_Modbus_getState()
//{
//    return SES_Modbus.u8state;
//}
/**
 * Get the last error in the protocol processor
 *
 * @returnreturn   NO_REPLY = 255      Time-out
 * @return   EXC_FUNC_CODE = 1   Function code not available
 * @return   EXC_ADDR_RANGE = 2  Address beyond available space for Modbus registers
 * @return   EXC_REGS_QUANT = 3  Coils or registers number beyond the available space
 * @ingroup buffer
 */
//static uint8_t SES_Modbus_getLastError()
//{
//    return SES_Modbus.u8lastError;
//}


/**
 * @brief
 * *** Only for Modbus Slave ***
 * This method checks if there is any incoming query
 * Afterwards, it would shoot a validation routine plus a register query
 * Avoid any delay() function !!!!
 * After a successful frame between the Master and the Slave, the time-out timer is reset.
 *
 * @param *regs  register table for communication exchange
 * @param u8size  size of the register table
 * @return 0 if no query, 1..4 if communication error, >4 if correct query processed
 * @ingroup loop
 */
//static int8_t SES_Modbus_Slave_poll( uint16_t *regs, uint16_t u8size )
//{
//
//    SES_Modbus.au16regs = regs;
//    SES_Modbus.u8regsize = u8size;
//	uint8_t u8current;
//
//
//    // check if there is any incoming frame
//    u8current = UART1_RxDataAvailable();
//
//    if (u8current == 0) return 0;
//
//    // check T35 after frame end or still no frame end
//    if (u8current != SES_Modbus.u8lastRec)
//    {
//        SES_Modbus.u8lastRec = u8current;
//        SES_Modbus.u32time = millis();
//        return 0;
//    }
//    if ((unsigned long)(millis() -SES_Modbus.u32time) < (unsigned long)T35) return 0;
//
//    SES_Modbus.u8lastRec = 0;
//    uint8_t i8state = SES_Modbus_getRxBuffer();
//    SES_Modbus.u8lastError = i8state;
//    if (i8state < 7) return i8state;
//
//    // check slave id
//    if (SES_Modbus.au8Buffer[ ID ] != SES_Modbus.u8id) return 0;
//
//    // validate message: CRC, FCT, address and size
//    uint8_t u8exception = validateRequest();
//    if (u8exception > 0)
//    {
//        if (u8exception != NO_REPLY)
//        {
//            buildException( u8exception );
//            SES_Modbus_sendTxBuffer();
//        }
//        SES_Modbus.u8lastError = u8exception;
//        return u8exception;
//    }
//
//    SES_Modbus.u32timeOut = millis();
//    SES_Modbus.u8lastError = 0;
//
//    // process message
//    switch( SES_Modbus.au8Buffer[ FUNC ] )
//    {
//    case MB_FC_READ_COILS:
//        return process_FC1( SES_Modbus.Coils.REG, 32);
//        break;
//    case MB_FC_READ_DISCRETE_INPUT:
//        //return process_FC1( regs, u8size );     
//        break;
//    case MB_FC_READ_INPUT_REGISTER:
//        break;
//    case MB_FC_READ_HOLD_REGISTERS :
//        return process_FC3( regs, u8size );
//        break;
//    case MB_FC_WRITE_COIL:
//        //return process_FC5( regs, u8size );
//        return process_FC5( SES_Modbus.Coils.REG, 32 );
//        break;
//    case MB_FC_WRITE_REGISTER :
//        return process_FC6( regs, u8size );
//        break;
//    case MB_FC_WRITE_MULTIPLE_COILS:
//        //return process_FC15( regs, u8size );
//        return process_FC15( SES_Modbus.Coils.REG, 32 );
//        break;
//    case MB_FC_WRITE_MULTIPLE_REGISTERS :
//        return process_FC16( regs, u8size );
//        break;
//    default:
//        break;
//    }
//    return i8state;
//}
static int8_t SES_ModbusRTU_Slave_poll( uint16_t *regs, uint16_t u8size )
{

//    SES_Modbus.au16regs = regs;
    SES_Modbus.u8regsize = u8size;
	uint8_t u8current;


    // check if there is any incoming frame
    u8current = UART2_RxDataAvailable();

    if (u8current == 0) return 0;

    // check T35 after frame end or still no frame end
    if (u8current != SES_Modbus.u8lastRec)
    {
        SES_Modbus.u8lastRec = u8current;
        SES_Modbus.u32time = millis();
        return 0;
    }
    if ((unsigned long)(millis() -SES_Modbus.u32time) < (unsigned long)T35) return 0;

    SES_Modbus.u8lastRec = 0;
    UINT16 i8state = SES_Modbus_getRxBuffer();
    SES_Modbus.u8lastError = i8state;
    if (i8state < 7) return i8state;

    // check slave id
    if (SES_Modbus.au8Buffer[ ID ] != SES_Modbus.u8id) return 0;

    // validate message: CRC, FCT, address and size
    uint8_t u8exception = validateRequest();
    if (u8exception > 0)
    {
        if (u8exception != NO_REPLY)
        {
            buildException( u8exception );
            SES_Modbus_sendTxBuffer();
        }
        SES_Modbus.u8lastError = u8exception;
        return u8exception;
    }

    SES_Modbus.u32timeOut = millis();
    SES_Modbus.u8lastError = 0;

    // process message
    switch( SES_Modbus.au8Buffer[ FUNC ] )
    {
    case MB_FC_READ_COILS:
        return process_FC1( SES_42.Coils.REG, 64);
        break;
    case MB_FC_READ_DISCRETE_INPUT:     
        break;
    case MB_FC_READ_INPUT_REGISTER:
        break;
    case MB_FC_READ_HOLD_REGISTERS :
        return process_FC3( regs, u8size );
        //return process_FC3( SES_42.SETUP_REGS, u8size );
        break;
    case MB_FC_WRITE_COIL:
        return process_FC5( SES_42.Coils.REG, 64 );
        break;
    case MB_FC_WRITE_REGISTER :
        return process_FC6( regs, u8size );
        break;
    case MB_FC_WRITE_MULTIPLE_COILS:
        return process_FC15( SES_42.Coils.REG, 32 );
        break;
    case MB_FC_WRITE_MULTIPLE_REGISTERS :
        return process_FC16( regs, u8size );
        break;
    default:
        break;
    }
    return i8state;
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
    while ( UART2_RxDataAvailable() )
    {
        SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = UART2_Read();
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
//        EN_RS485_SetHigh();
        // set RS485 transceiver to transmit mode
        //digitalWrite( u8txenpin, HIGH );//////////////////////////////////////////////////////////////////
    }

    // transfer buffer to serial line
    //int s = 
    UART2_WriteBuffer( SES_Modbus.au8Buffer, SES_Modbus.u8BufferSize );

    if (SES_Modbus.u8txenpin > 1)
    {
        // must wait transmission end before changing pin state
        // soft serial does not need it since it is blocking
        // ...but the implementation in SoftwareSerial does nothing
        // anyway, so no harm in calling it.
        
        //port->flush();
        while(!UART2_IsTxDone());
        // return RS485 transceiver to receive mode
        volatile uint32_t u32overTimeCountDown = SES_Modbus.u32overTime;
        while ( u32overTimeCountDown-- > 0);
        //digitalWrite( u8txenpin, LOW );////////////////////////////////////////////////////////////////////////////////
//        EN_RS485_SetLow();
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
 * This method validates slave incoming messages
 *
 * @return 0 if OK, EXCEPTION if anything fails
 * @ingroup buffer
 */
static uint8_t validateRequest()
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

    // check fct code
    bool isSupported = false;
    uint8_t i=0;
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

    // check start address & nb range
    uint16_t u16regs = 0;
    uint8_t u8regs;
    switch ( SES_Modbus.au8Buffer[ FUNC ] )
    {
    case MB_FC_READ_COILS:
        u16regs = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ]) / 16;
        u16regs += word( SES_Modbus.au8Buffer[ NB_HI ], SES_Modbus.au8Buffer[ NB_LO ]) /16;
        u8regs = (uint8_t) u16regs;
        if (u8regs > sizeof(SES_Modbus.Coils.REG)*8) return EXC_ADDR_RANGE;    
        break;
    case MB_FC_READ_DISCRETE_INPUT:
        break;
    case MB_FC_WRITE_MULTIPLE_COILS:
        u16regs = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ]) / 16;
        u16regs += word( SES_Modbus.au8Buffer[ NB_HI ], SES_Modbus.au8Buffer[ NB_LO ]) /16;
        u8regs = (uint8_t) u16regs;
        if (u8regs > sizeof(SES_Modbus.Coils.REG)*8) return EXC_ADDR_RANGE;
        break;
    case MB_FC_WRITE_COIL:
        u16regs = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ]) / 16;
        u8regs = (uint8_t) u16regs;
        if (u8regs > sizeof(SES_Modbus.Coils.REG)*8) return EXC_ADDR_RANGE;
        break;
    case MB_FC_WRITE_REGISTER :
        u16regs = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ]);
        u8regs = (uint8_t) u16regs;
        if (u8regs > SES_Modbus.u8regsize) return EXC_ADDR_RANGE;
        break;
    case MB_FC_READ_HOLD_REGISTERS :
        break;
    case MB_FC_READ_INPUT_REGISTER :
        break;
    case MB_FC_WRITE_MULTIPLE_REGISTERS :
        u16regs = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ]);
        u16regs += word( SES_Modbus.au8Buffer[ NB_HI ], SES_Modbus.au8Buffer[ NB_LO ]);
        u8regs = (uint8_t) u16regs;
        if (u8regs > SES_Modbus.u8regsize) return EXC_ADDR_RANGE;
        break;
    }
    return 0; 
    

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
 * @brief
 * This method processes functions 1 & 2
 * This method reads a bit array and transfers it to the master
 *
 * @return u8BufferSize Response to master length
 * @ingroup discrete
 */
static int8_t process_FC1( uint16_t *regs, uint8_t u8size )
{
    uint8_t u8currentRegister, u8currentBit, u8bytesno, u8bitsno;
    uint8_t u8CopyBufferSize;
    uint16_t u16currentCoil, u16coil;

    // get the first and last coil from the message
    uint16_t u16StartCoil = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ] );
    uint16_t u16Coilno = word( SES_Modbus.au8Buffer[ NB_HI ], SES_Modbus.au8Buffer[ NB_LO ] );

    // put the number of bytes in the outcoming message
    u8bytesno = (uint8_t) (u16Coilno / 8);
    if (u16Coilno % 8 != 0) u8bytesno ++;
    SES_Modbus.au8Buffer[ ADD_HI ]  = u8bytesno;
    SES_Modbus.u8BufferSize         = ADD_LO;
    SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize + u8bytesno - 1 ] = 0;

    // read each coil from the register map and put its value inside the outcoming message
    u8bitsno = 0;

    for (u16currentCoil = 0; u16currentCoil < u16Coilno; u16currentCoil++)
    {
        u16coil = u16StartCoil + u16currentCoil;
        u8currentRegister = (uint8_t) (u16coil / 16);
        u8currentBit = (uint8_t) (u16coil % 16);

        bitWrite(
            SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ],
            u8bitsno,
            bitRead( regs[ u8currentRegister ], u8currentBit ) );
        u8bitsno ++;

        if (u8bitsno > 7)
        {
            u8bitsno = 0;
            SES_Modbus.u8BufferSize++;
        }
    }

    // send outcoming message
    if (u16Coilno % 8 != 0) SES_Modbus.u8BufferSize ++;
    u8CopyBufferSize = SES_Modbus.u8BufferSize +2;
    SES_Modbus_sendTxBuffer();
    return u8CopyBufferSize;
}


/**
 * @brief
 * This method processes functions 3 & 4
 * This method reads a word array and transfers it to the master
 *
 * @return u8BufferSize Response to master length
 * @ingroup register
 */
static int8_t process_FC3( uint16_t *regs, uint8_t u8size )
{

    uint16_t u8StartAdd = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ] );
    UINT16 u8regsno = word( SES_Modbus.au8Buffer[ NB_HI ], SES_Modbus.au8Buffer[ NB_LO ] );
    UINT16 u8CopyBufferSize;
    uint16_t i;

    SES_Modbus.au8Buffer[ 2 ]       = u8regsno * 2;
    SES_Modbus.u8BufferSize         = 3;

    for (i = u8StartAdd; i < u8StartAdd + u8regsno; i++)
    {
        SES_Modbus.au8Buffer[SES_Modbus.u8BufferSize ] = highByte(regs[i]);
        SES_Modbus.u8BufferSize++;
        SES_Modbus.au8Buffer[ SES_Modbus.u8BufferSize ] = lowByte(regs[i]);
        SES_Modbus.u8BufferSize++;
    }
    u8CopyBufferSize = SES_Modbus.u8BufferSize +2;
    SES_Modbus_sendTxBuffer();

    return u8CopyBufferSize;
}
/**
 * @brief
 * This method processes function 5
 * This method writes a value assigned by the master to a single bit
 *
 * @return u8BufferSize Response to master length
 * @ingroup discrete
 */
static int8_t process_FC5( uint16_t *regs, uint8_t u8size )
{
    uint8_t u8currentRegister, u8currentBit;
    uint8_t u8CopyBufferSize;
    uint16_t u16coil = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ] );

    // point to the register and its bit
    u8currentRegister = (uint8_t) (u16coil / 16);
    u8currentBit = (uint8_t) (u16coil % 16);

    // write to coil
    bitWrite(
        regs[ u8currentRegister ],
        u8currentBit,
        SES_Modbus.au8Buffer[ NB_HI ] == 0xff );


    // send answer to master
    SES_Modbus.u8BufferSize = 6;
    u8CopyBufferSize = SES_Modbus.u8BufferSize +2;
    SES_Modbus_sendTxBuffer();

    return u8CopyBufferSize;
}
/**
 * @brief
 * This method processes function 6
 * This method writes a value assigned by the master to a single word
 *
 * @return u8BufferSize Response to master length
 * @ingroup register
 */
static int8_t process_FC6( uint16_t *regs, uint8_t u8size )
{

    uint8_t u8add = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ] );
    uint8_t u8CopyBufferSize;
    uint16_t u16val = word( SES_Modbus.au8Buffer[ NB_HI ], SES_Modbus.au8Buffer[ NB_LO ] );

    regs[ u8add ] = u16val;

    // keep the same header
    SES_Modbus.u8BufferSize         = RESPONSE_SIZE;

    u8CopyBufferSize = SES_Modbus.u8BufferSize +2;
    SES_Modbus_sendTxBuffer();

    return u8CopyBufferSize;
}
/**
 * @brief
 * This method processes function 15
 * This method writes a bit array assigned by the master
 *
 * @return u8BufferSize Response to master length
 * @ingroup discrete
 */
static int8_t process_FC15( uint16_t *regs, uint8_t u8size )
{
    uint8_t u8currentRegister, u8currentBit, u8frameByte, u8bitsno;
    uint8_t u8CopyBufferSize;
    uint16_t u16currentCoil, u16coil;
    bool bTemp;

    // get the first and last coil from the message
    uint16_t u16StartCoil = word( SES_Modbus.au8Buffer[ ADD_HI ], SES_Modbus.au8Buffer[ ADD_LO ] );
    uint16_t u16Coilno = word( SES_Modbus.au8Buffer[ NB_HI ], SES_Modbus.au8Buffer[ NB_LO ] );


    // read each coil from the register map and put its value inside the outcoming message
    u8bitsno = 0;
    u8frameByte = 7;
    for (u16currentCoil = 0; u16currentCoil < u16Coilno; u16currentCoil++)
    {

        u16coil = u16StartCoil + u16currentCoil;
        u8currentRegister = (uint8_t) (u16coil / 16);
        u8currentBit = (uint8_t) (u16coil % 16);

        bTemp = bitRead(
                    SES_Modbus.au8Buffer[ u8frameByte ],
                    u8bitsno );

        bitWrite(
            regs[ u8currentRegister ],
            u8currentBit,
            bTemp );

        u8bitsno ++;

        if (u8bitsno > 7)
        {
            u8bitsno = 0;
            u8frameByte++;
        }
    }

    // send outcoming message
    // it's just a copy of the incomping frame until 6th byte
    SES_Modbus.u8BufferSize         = 6;
    u8CopyBufferSize = SES_Modbus.u8BufferSize +2;
    SES_Modbus_sendTxBuffer();
    return u8CopyBufferSize;
}
/**
 * @brief
 * This method processes function 16
 * This method writes a word array assigned by the master
 *
 * @return u8BufferSize Response to master length
 * @ingroup register
 */
static int8_t process_FC16( uint16_t *regs, uint8_t u8size )
{
    uint8_t u8StartAdd = SES_Modbus.au8Buffer[ ADD_HI ] << 8 | SES_Modbus.au8Buffer[ ADD_LO ];
    uint8_t u8regsno = SES_Modbus.au8Buffer[ NB_HI ] << 8 | SES_Modbus.au8Buffer[ NB_LO ];
    uint8_t u8CopyBufferSize;
    uint8_t i;
    uint16_t temp;

    // build header
    SES_Modbus.au8Buffer[ NB_HI ]   = 0;
    SES_Modbus.au8Buffer[ NB_LO ]   = u8regsno;
    SES_Modbus.u8BufferSize         = RESPONSE_SIZE;

    // write registers
    for (i = 0; i < u8regsno; i++)
    {
        temp = word(
                   SES_Modbus.au8Buffer[ (BYTE_CNT + 1) + i * 2 ],
                   SES_Modbus.au8Buffer[ (BYTE_CNT + 2) + i * 2 ]);

        regs[ u8StartAdd + i ] = temp;
    }
    u8CopyBufferSize = SES_Modbus.u8BufferSize +2;
    SES_Modbus_sendTxBuffer();

    return u8CopyBufferSize;
}

void SES_ModbusRTU_Slave_Process(void)
{
    
//        static int8_t state = 0,i;
//        state = SES_ModbusRTU_Slave_poll( SES_42.SETUP_REGS, 500 );
//        
//        SES_42.SETUP_REGS[70] = Sum_numof_Meter;
//        //UPDATE STATUS METER
////        for(i = 0; i < 15; i++)
////            Data42L_Meter[i][90] = 1;
//        *Status_Meter = 0; 
//        for(i = 0; i < Sum_numof_Meter; i++)
//        {
//            if(Data42L_Meter[i][90] > 0)
//            {
//                *Status_Meter |= ((UINT64)1 << i);
//            }
//            else
//            {
//                *Status_Meter &= ~((UINT64)1 << i);
//            }
//        }
////        *Status_Meter |= (UINT64)1 << 25;
////        *Status_Meter = 0x00FFFFFF;
//        
//        //UPDATE STATUS INTERFACE
//        for(i = 0; i < G42.Num_Interface; i++)
//        {
//            if(G42.Interface[i].Status)
//            {
//                SES_42.Coils.val |= (UINT64)1 << (i+1);
//            }
//            else
//            {
//                SES_42.Coils.val &= ~((UINT64)1 << (i+1));
//            }
//        }
//        if(G42.LOCAL_SERVER.Status)
//        {
//            SES_42.Coils.val |= (UINT64)1 << 51;
//        }
//        else
//        {
//            SES_42.Coils.val &= ~((UINT64)1 << 51);
//        }
//        Check_Save_DataSetup();
    
}