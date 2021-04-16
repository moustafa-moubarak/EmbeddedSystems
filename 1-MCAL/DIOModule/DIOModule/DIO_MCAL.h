/*
 * DIO_MCAL.h
 *
 * Created: 4/13/2021 3:09:42 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef DIO_MCAL_H_
#define DIO_MCAL_H_

#include "MCU.h"
#include "STD.h"
#include "BIT_Math.h"

#define		DIO_PORTA		0
#define		DIO_PORTB		1
#define		DIO_PORTC		2
#define		DIO_PORTD		3

#define		DIO_PIN0		0
#define		DIO_PIN1		1
#define		DIO_PIN2		2
#define		DIO_PIN3		3
#define		DIO_PIN4		4
#define		DIO_PIN5		5
#define		DIO_PIN6		6
#define		DIO_PIN7		7

#define		DIO_PORT_OUTPUT		0xFF	
#define		DIO_PORT_INPUT		0x00

#define		DIO_PIN_OUTPUT		1
#define		DIO_PIN_INPUT		0

#define		DIO_PORT_HIGH		0xFF
#define		DIO_PORT_LOW		0x00

#define		DIO_PIN_HIGH		1
#define		DIO_PIN_LOW			0

void DIO_SetPortDir(uint8 port, uint8 direction);
void DIO_SetPINDir(uint8 port, uint8 pin, uint8 direction);

void DIO_SetPortValue(uint8 port, uint8 value);
void DIO_SetPinValue(uint8 port, uint8 pin, uint8 value);

void DIO_ReadPinValue(uint8 port, uint8 pin, uint8 *recall_value);
void DIO_ReadPortValue(uint8 port, uint8 *recall_value);

void DIO_TogglePin(uint8 port, uint8 pin);
void DIO_TogglePort(uint8 port);



#endif /* DIO_MCAL_H_ */