/* 
 * File:   3_Sma.h
 * Author: Chien Tran
 *
 * Created on July 29, 2021, 11:53 AM
 */

#ifndef XC_HEADER_SMA_H
#define	XC_HEADER_SMA_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "0_Inverter.h"

void STP50_Initialization(DEVICE_INFOR *Inv);
void STP50_GetData(uint8_t index, uint8_t inv_index, char type);
uint8_t STP50_CtrlSetup(char type);
uint8_t STP50_RTU_ResponseCtrl(char type);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* 3_SMA_H */

