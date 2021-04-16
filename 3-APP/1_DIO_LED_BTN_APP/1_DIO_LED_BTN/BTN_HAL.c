/*
 * BTN_HAL.c
 *
 * Created: 4/14/2021 12:09:26 AM
 *  Author: Moustafa Moubarak
 */ 

#include "BTN_HAL.h"

void BTN_INIT(uint8 BTN)
{
	switch (BTN)
	{
		case BTN0:
			DIO_SetPINDir(DIO_PORTB, DIO_PIN0, DIO_PIN_INPUT);
			break;
			
		case BTN1:
			DIO_SetPINDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);		
			break;
		
		case BTN2:
			DIO_SetPINDir(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
			break;
	}
}

uint8 BTN_GetValue(uint8 BTN)
{
	switch(BTN)
	{
		uint8 value = 0;
		case BTN0:
			DIO_ReadPinValue(DIO_PORTB, DIO_PIN0, &value);
			while (GET_BIT(PINB,0) == 1)
			_delay_ms(20);
			return value;
		break;
			
		case BTN1:
			DIO_ReadPinValue(DIO_PORTB, DIO_PIN4, &value);
			while (GET_BIT(PINB,4) == 1)
			_delay_ms(20);
			
			return value;
		break;
		
		case BTN2:
			DIO_ReadPinValue(DIO_PORTD, DIO_PIN2, &value);
			while (GET_BIT(PIND,2) == 1)
			_delay_ms(20);
		
			return value;
		break;
	}
}

/*
void BTN0_INIT (void)
{
	DIO_SetPINDir(DIO_PORTB, DIO_PIN0, DIO_PIN_INPUT);
}

uint8 BTN0_GetValue (void)
{
	uint8 value = 0;
	DIO_ReadPinValue(DIO_PORTB, DIO_PIN0, &value);
	while (GET_BIT(PINB,0) == 1)
	_delay_ms(20);
	
	return value;
}

void BTN1_INIT (void)
{
	DIO_SetPINDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
}

uint8 BTN1_GetValue (void)
{
	uint8 value = 0;
	DIO_ReadPinValue(DIO_PORTB, DIO_PIN4, &value);
	while (GET_BIT(PINB,4) == 1)
	_delay_ms(20);
	
	return value;
}

void BTN2_INIT (void)
{
	DIO_SetPINDir(DIO_PORTD, DIO_PIN2, DIO_PIN_INPUT);
}

uint8 BTN2_GetValue (void)
{
	uint8 value = 0;
	DIO_ReadPinValue(DIO_PORTD, DIO_PIN2, &value);
	while (GET_BIT(PIND,2) == 1)
	_delay_ms(20);
	
	return value;
}
*/