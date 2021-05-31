/*
 * UART.c
 *
 * Created: 5/31/2021 12:37:58 PM
 *  Author: Moustafa Moubarak
 */ 

#include "UART.h"

void UART_Init(void)
{
	uint32 UBRR_Val = 0;
	
	//Tx Pin output
	SET_BIT(DDRD,1);
	//Rx Pin output
	CLR_BIT(DDRD,0);
	
	//Enable Tx
	SET_BIT(UCSRB, 4);
	
	//Enable Rx
	SET_BIT(UCSRB, 3);
	
	//Stop Bit 1-bit
	CLR_BIT(UCSRC, 3);
	//Asynchronous 
	CLR_BIT(UCSRC, 6);
	//Parity Mode Disable
	CLR_BIT(UCSRC, 4);
	CLR_BIT(UCSRC, 5);
	
	//Data Bits 8-bit Mode
	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);
	CLR_BIT(UCSRB, 2);
	SET_BIT(UCSRC, 1);
	/*//Or we can replace it with
	UCSRC |= 0x86;*/
	
	//Set Baud Rate
	UBRR_Val = (160000 / (16 * 96) ) - 1;
	UBRR = UBRR_Val;
}

uint8 UART_Rx (void)
{
	uint8 data = 0;
	while (GET_BIT(UCSRA,5) == 0);
	
	data = UDR;
	
	return data;
}

void UART_Tx (uint8 data)
{
	UDR = data;
	while(GET_BIT(UCSRA,5) == 0);
}

void UART_TxString (uint8* str)
{
	uint8 i = 0;
	while (str[i] != '\0')
	{
		UART_Tx(str[i]);
		i++;
	}
}