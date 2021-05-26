/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
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

#include "../SES.h"

uint16_t EEPROM_DEVICE_ADDRESS = (0xA8 >> 1);
//uint16_t EEPROM_DEVICE_ADDRESS = (0xA0 >> 1);

#define PAGESIZE    256
#define MIN(a,b) (a<b?a:b)

typedef struct
{
    uint8_t *data;
    uint16_t *dataSize;
} block_t;
    
static uint16_t eeprom_flipAddress(uint16_t address)
{
    return (address << 8) | (address >> 8);
}

static uint8_t getMSBAddress(uint32_t address)
{
    uint8_t deviceAddress;
    deviceAddress = (address & 0xF0000) >> 16;
    return (deviceAddress);
}

static void setDeviceAddress(uint8_t MSBAddress)
{
    switch(MSBAddress)
    {
        case 0x0:
            EEPROM_DEVICE_ADDRESS = (0xA8 >> 1);
            break;
        case 0x1:
            EEPROM_DEVICE_ADDRESS = (0xAA >> 1);
            break;
        case 0x2:
            EEPROM_DEVICE_ADDRESS = (0xAC >> 1);
            break;
        case 0x3:
            EEPROM_DEVICE_ADDRESS = (0xAE >> 1);
            break;
        default:
            break;
        
    }
}

static void resetDeviceAddress()
{
    switch(EEPROM_DEVICE_ADDRESS)
    {
        case 0x54:
            EEPROM_DEVICE_ADDRESS = (0xAA >> 1);
            break;
        case 0x55:
            EEPROM_DEVICE_ADDRESS = (0xAC >> 1);
            break;
        case 0x56:
            EEPROM_DEVICE_ADDRESS = (0xAE >> 1);
            break;
        case 0x57:
            EEPROM_DEVICE_ADDRESS = (0xA8 >> 1);
            break;
        default:
            break;
        
    }
}

static i2c_operations_t write1ByteHandler(void *p)
{
    i2c_setBuffer(p,1);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_continue;
}

static i2c_operations_t read1ByteHandler(void *p)
{
    i2c_setBuffer(p,1);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_restart_read;
}
static i2c_operations_t i2crestart_write(void *p)
{
    return i2c_restart_write;
}
void EEPROM3_WriteOneByte(uint32_t address, uint8_t data)
{
    uint8_t MSBAddress = getMSBAddress(address);
    setDeviceAddress(MSBAddress);
    while(!i2c_open(EEPROM_DEVICE_ADDRESS)); // sit here until we get the bus..
    address = eeprom_flipAddress(address); 
    i2c_setDataCompleteCallback(write1ByteHandler,&data);
    i2c_setBuffer(&address,2);
    i2c_setAddressNACKCallback(i2crestart_write,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
    NOP();
}

uint8_t EEPROM3_ReadOneByte(uint32_t address)
{
    uint8_t readData = 0;
    uint8_t MSBAddress = getMSBAddress(address);
    setDeviceAddress(MSBAddress);
    while(!i2c_open(EEPROM_DEVICE_ADDRESS)); // sit here until we get the bus..
    address = eeprom_flipAddress(address); 
    i2c_setDataCompleteCallback(read1ByteHandler,&readData);
    i2c_setBuffer(&address,2);
    i2c_setAddressNACKCallback(i2crestart_write,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
    return readData;
}

static i2c_operations_t writeBlockHandler(void *payload)
{
    block_t *pgData = payload;
    i2c_setBuffer(pgData->data,*pgData->dataSize);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_continue;
}

static void EEPROM3_WritePage(uint16_t address, uint8_t* data, uint16_t count)
{
    while(!i2c_open(EEPROM_DEVICE_ADDRESS)); // sit here until we get the bus..
    address = eeprom_flipAddress(address); 

    block_t blk = {0};
    blk.data = data;
    blk.dataSize = &count;

    i2c_setDataCompleteCallback(writeBlockHandler,&blk);
    i2c_setBuffer(&address,2);
    i2c_setAddressNACKCallback(i2crestart_write,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
    NOP();

}

void EEPROM3_WriteBlock(uint32_t address, void *dataBlock, uint16_t dataBlockByteCount)
{   
    uint8_t MSBAddress = getMSBAddress(address);
    setDeviceAddress(MSBAddress);
    uint16_t wordAddress = (address & 0x00FFFF);
    uint16_t pageAddress = wordAddress & 0xFF00;
    uint32_t byte2write = PAGESIZE - (wordAddress - pageAddress);
    uint8_t *block = dataBlock;
    do
    {
        byte2write = MIN(byte2write,dataBlockByteCount);
        EEPROM3_WritePage(wordAddress,block,byte2write);
        wordAddress = wordAddress + byte2write;
        if(wordAddress == 0){
            resetDeviceAddress();
        }
        block = block + byte2write;
        dataBlockByteCount = dataBlockByteCount - byte2write;
        byte2write = PAGESIZE;
		__delay_ms(5);
		__delay_ms(5);
    } while(dataBlockByteCount);
}

static i2c_operations_t readBlockHandler(void *payload)
{
    block_t *pgData = payload;
    i2c_setBuffer(pgData->data,*pgData->dataSize);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_restart_read;
}

void EEPROM3_ReadBlock(uint32_t address, void* data, uint16_t count)
{
    uint8_t MSBAddress = getMSBAddress(address);
    setDeviceAddress(MSBAddress);
    uint16_t wordAddress = (address & 0x00FFFF);
    while(!i2c_open(EEPROM_DEVICE_ADDRESS)); // sit here until we get the bus..
    wordAddress = eeprom_flipAddress(wordAddress); 
    block_t blk = {0};
    blk.data = data;
    blk.dataSize = &count;
    i2c_setDataCompleteCallback(readBlockHandler,&blk);
    i2c_setBuffer(&wordAddress,2);
    i2c_setAddressNACKCallback(i2crestart_write,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
    
}