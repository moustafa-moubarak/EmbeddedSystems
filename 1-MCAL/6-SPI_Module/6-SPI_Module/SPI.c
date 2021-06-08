/*
 * SPI.c
 *
 * Created: 6/3/2021 11:58:58 AM
 *  Author: Moustafa Moubarak
 */ 

#include "SPI.h"

void SPI_Master_Init(void)
{
	//MOSI PIN
	DIO_SetPINDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	//MISO Pin
	DIO_SetPINDir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	//CLK Pin
	DIO_SetPINDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	//SS Pin
	DIO_SetPINDir(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	
	SPI->SPCR |= 0x53;
	
}
void SPI_Slave_Init(void)
{
	//MOSI PIN
	DIO_SetPINDir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	//MISO Pin
	DIO_SetPINDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	//CLK Pin
	DIO_SetPINDir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	//SS Pin
	DIO_SetPINDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);

	SPI->SPCR |= 0x40;	
	
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
}

void SPI_Master_InitTrans(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_LOW);
}
void SPI_Master_TermTrans(void)
{
	DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_PIN_HIGH);
}

uint8 SPI_TranSiver(uint8 data)
{
	uint8 rec_data = 0;
	
	SPI->SPDR = data;
	
	while (GET_BIT(SPI->SPSR , 7) == 0);
	
	rec_data = SPI->SPDR;
	
	return rec_data;
}