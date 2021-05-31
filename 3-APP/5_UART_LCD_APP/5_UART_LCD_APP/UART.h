/*
 * UART.h
 *
 * Created: 5/31/2021 12:38:10 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef UART_H_
#define UART_H_

#include "MCU.h"
#include "BIT_Math.h"
#include "STD.h"

void UART_Init(void);

uint8 UART_Rx (void);

void UART_Tx (uint8 data);

void UART_TxString (uint8* str);



#endif /* UART_H_ */