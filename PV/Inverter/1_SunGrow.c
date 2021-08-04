#include "../../SES.h"

void SG110CX_Initialization(DEVICE_INFOR *Inv)
{
    (*Inv).Func = MB_FC_READ_INPUT_REGISTER;
    (*Inv).NumFr = 2;
    (*Inv).Fr[0].u16RegAdd = 5000;
    (*Inv).Fr[0].u16CoilsNo = 75;
    (*Inv).Fr[0].pointer = 0;
    (*Inv).Fr[1].u16RegAdd = 5075;
    (*Inv).Fr[1].u16CoilsNo = 76;
    (*Inv).Fr[1].pointer = 75;      
}

uint8_t SG110CX_CtrlSetup(char type)
{
    return 1;
}

uint8_t SG110CX_GetData(uint8_t index, uint8_t inv_index, char type)
{
    
    __eds__ INVERTER_DATA *inv_data;
    __eds__ uint16_t *Buffer;
    if(type == MODBUS_RTU)
    {
        Buffer = RTU_Buffer[index];
    }
    else if(type == MODBUS_TCP)
    {
        Buffer = TCP_Buffer[index];
    }
    else
    {
        return 0;
    }
    inv_data = &(InvData[inv_index]);
    if (type == MODBUS_RTU || type == MODBUS_TCP)
    {
        //AC Data
        (*inv_data).AC.P = (INT16)((uint32_t)((convert16to32(Buffer[31],Buffer[30]))/1000));
        (*inv_data).AC.W_SF = 0;
        (*inv_data).AC.Q = (INT16)((convert16to32(Buffer[33],Buffer[32]))/1000);
        (*inv_data).AC.VA_SF = 0;
        (*inv_data).AC.S = (INT16)((convert16to32(Buffer[9],Buffer[8]))/1000);
        (*inv_data).AC.VAr_SF = 0;
        
        if(Buffer[1]==1)
        {
            (*inv_data).AC.AN = Buffer[18];
            (*inv_data).AC.BN = Buffer[19];
            (*inv_data).AC.CN = Buffer[20];
            (*inv_data).AC.V_SF = -1;
        }
        else if(Buffer[1]==2)
        {
            (*inv_data).AC.VAB = Buffer[18];
            (*inv_data).AC.VBC = Buffer[19];
            (*inv_data).AC.VCA = Buffer[20];
            (*inv_data).AC.V_SF = -1;
        }
        (*inv_data).AC.IA = Buffer[21];
        (*inv_data).AC.IB = Buffer[22];
        (*inv_data).AC.IC = Buffer[23];
        (*inv_data).AC.A_SF = -1;
        (*inv_data).AC.EP = (uint64_t)(convert16to32(Buffer[4],Buffer[3]));
        
        (*inv_data).AC.PF = Buffer[34];
        (*inv_data).AC.PF_SF = -3;
        
        (*inv_data).AC.F = Buffer[35];
        (*inv_data).AC.Hz_SF = -1;

        //DC data
        (*inv_data).DC.N = 9;
        
        (*inv_data).DC.Mppt_module[0].ID = 1;
        (*inv_data).DC.Mppt_module[0].DCV = Buffer[10];
        (*inv_data).DC.Mppt_module[0].DCA = Buffer[11];
        
        (*inv_data).DC.Mppt_module[1].ID = 2;
        (*inv_data).DC.Mppt_module[1].DCV = Buffer[12];
        (*inv_data).DC.Mppt_module[1].DCA = Buffer[13];
        
        (*inv_data).DC.Mppt_module[2].ID = 3;
        (*inv_data).DC.Mppt_module[2].DCV = Buffer[14];
        (*inv_data).DC.Mppt_module[2].DCA = Buffer[15];
        
        (*inv_data).DC.Mppt_module[3].ID = 4;
        (*inv_data).DC.Mppt_module[3].DCV = Buffer[114];
        (*inv_data).DC.Mppt_module[3].DCA = Buffer[115];
       
        (*inv_data).DC.Mppt_module[4].ID = 5;
        (*inv_data).DC.Mppt_module[4].DCV = Buffer[116];
        (*inv_data).DC.Mppt_module[4].DCA = Buffer[117];
        
        (*inv_data).DC.Mppt_module[5].ID = 6;
        (*inv_data).DC.Mppt_module[5].DCV = Buffer[118];
        (*inv_data).DC.Mppt_module[5].DCA = Buffer[119];
        
        (*inv_data).DC.Mppt_module[6].ID = 7;
        (*inv_data).DC.Mppt_module[6].DCV = Buffer[120];
        (*inv_data).DC.Mppt_module[6].DCA = Buffer[121];
        
        (*inv_data).DC.Mppt_module[7].ID = 8;
        (*inv_data).DC.Mppt_module[7].DCV = Buffer[122];
        (*inv_data).DC.Mppt_module[7].DCA = Buffer[123];
        
        (*inv_data).DC.Mppt_module[8].ID = 9;
        (*inv_data).DC.Mppt_module[8].DCV = Buffer[129];
        (*inv_data).DC.Mppt_module[8].DCA = Buffer[130];
        
        (*inv_data).DC.DCA_SF = -1;
        (*inv_data).DC.DCV_SF = -1;
        (*inv_data).DC.P_DC = (INT16)((convert16to32(Buffer[17],Buffer[16]))/1000);
        (*inv_data).DC.DCW_SF = 0;
        
        //Event
        switch(Buffer[44])
        {
            case 0x0002:
            {
                (*inv_data).Event = AC_OVER_VOLT;
                break;
            }
            case 0x0004:
            {
                (*inv_data).Event = AC_UNDER_VOLT;
                break;
            }
            case 0x0008:
            {
                (*inv_data).Event = OVER_FREQUENCY;
                break;
            }
            case 0x0009:
            {
                (*inv_data).Event = UNDER_FREQUENCY;
                break;
            }
            case 0x000A:
            {
                (*inv_data).Event = GRID_DISCONNECT;
                break;
            }
            case 0x0017:
            {
                (*inv_data).Event = DC_DISCONNECT;
                break;            
            }
            case 0x0024:
            {
                (*inv_data).Event = OVER_TEMP;
                break;            
            }
            case 0x002B:
            {
                (*inv_data).Event = UNDER_TEMP;
                break;            
            }
            case 0x006A:
            {
                (*inv_data).Event = GROUND_FAULT;
                break;            
            }
            default:
            {
                break;
            }
        }
        
        //State
        switch(Buffer[37])
        {
            case 0x8000:
            {
                (*inv_data).Operating_State = OFF;
                break;
            }
            case 0x1400:
            {
                (*inv_data).Operating_State = STANDBY;
                break;
            }
            case 0x1600:
            {
                (*inv_data).Operating_State = STARTING;
                break;
            }
            case 0x5500:
            {
                (*inv_data).Operating_State = FAULT;
                break;
            }
        }
        
        //Temperature
        (*inv_data).T.T_Cabinet = Buffer[7];
        (*inv_data).T.Tmp_SF = -1;
    }
    return 1;
}

uint8_t SG110CX_ResponseCtrl(char type)
{
    return 1;
}
