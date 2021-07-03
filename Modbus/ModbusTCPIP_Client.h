// ModbusTCPClient.h


#include "ModbusTCPIP.h"

#define MODBUS_PORT		502 


/** C O N S T A N T S ***********************************************************/

#define MAKE_IPV4_ADDRESS(d,c,b,a) ((uint32_t)(((uint32_t)a << 24) | ((uint32_t)b<<16) | ((uint32_t)c << 8) | (uint32_t)d))

typedef struct
{
    union{
        uint32_t val;
        uint8_t s_addr_byte[4];
    };
}inAddr_t;

typedef struct
{
    uint16_t u16RegAdd;    /*!< Address of the first register to access at slave/s */
    uint16_t u16CoilsNo;   /*!< Number of coils or registers to access */
    uint16_t pointer;
}FRAME;

typedef struct 
{
    inAddr_t IP;
    UINT16 PORT;
    uint8_t u8id;          /*!< Slave address between 1 and 247. 0 means broadcast */
    uint8_t u8fct;         /*!< Function code: 1, 2, 3, 4, 5, 6, 15 or 16 */
    uint8_t NumFrame;
    FRAME Frame; 
    UINT8 IID;
    
}_INFORMATION_DEVICE;

typedef struct
{
//    inAddr_t IP;
//    uint8_t u8id;          /*!< Slave address between 1 and 247. 0 means broadcast */
//    uint8_t u8fct;         /*!< Function code: 1, 2, 3, 4, 5, 6, 15 or 16 */
//    uint16_t u16RegAdd;    /*!< Address of the first register to access at slave/s */
//    uint16_t u16CoilsNo;   /*!< Number of coils or registers to access */
//    __eds__ int *__eds__ *au16reg __attribute__((space(psv)));
   __eds__ uint16_t *au16reg;     /*!< Pointer to memory image in master */
    
    _INFORMATION_DEVICE INFOR;
}  MODBUS_CLIENT_TELEGRAM;
//extern Client_modbus_FR Client_telegram[4];

enum MB_REP
{
    MBIllegalFunction            = 0x01,
    MBIllegalDataAddress         = 0x02,
    MBIllegalDataValue              = 0x03,
    MBIllegalResponseLength         = 0x04,
    MBServerConnectionTimeOut       = 0x05,
    MBSuccess                     = 0x00,
    MBInvalidTransactionID        = 0xE0,
    MBInvalidFunction             = 0xE1,
    MBResponseTimedOut            = 0xE2,

    MBInvalidUnitID               = 0xE3,
    MBInvalidProtocol             = 0xE4
};
typedef enum
{
	MBCS_HOME = 0,
	MBCS_SOCKET_OBTAINED,
	MBCS_SEND_REQUEST,
	MBCS_WAIT_RESPONSE,
	MBCS_PROCESS_RESPONSE,
	MBCS_DISCONNECT,
	MBCS_RELEASE
}
MODBUS_CLIENT_STATE;



#define INPUTREG_SIZE 125
#define HOLDINGREG_SIZE 125
#define Client_Modbus_Scanrate  100
//#define MAX_BUFF 100
//#define NUM_FRAME_WEATHER 1 
//#define MAX_NUM_WEATHER_STATION 10//30
/** P R O T O T Y P E S ***********************************************************/
//extern UINT16 Sum_numof_Meter, Sum_Num_Frame;
//extern __eds__ __attribute ((eds))uint16_t   Data42L_Meter [MAX_NUM_METER][350];

void SES_ModbusTCP_Client_Init(void);
void SES_ModbusTCPIP_Client_Process(void);

