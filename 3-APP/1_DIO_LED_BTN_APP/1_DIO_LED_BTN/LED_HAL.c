/*
 * LED_HAL.c
 *
 * Created: 4/13/2021 11:41:07 PM
 *  Author: Moustafa Moubarak
 */ 
#include "LED_HAL.h"

void LED_Init(uint8 LED)
{
	switch(LED)
	{
		case LED0:
			DIO_SetPINDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);	
			break;
		case LED1:
			DIO_SetPINDir(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
			break;
		case LED2:
			DIO_SetPINDir(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
			break;	
			
		default:
			break;
	}	
}

void LED_ON(uint8 LED)
{
	switch (LED)
	{
		case LED0:
			DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_PIN_HIGH);
			break;
		case LED1:
			DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
			break;
		case LED2:
			DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
			break;
		
		default:
			break;
	}
	
}

void LED_OFF(uint8 LED)
{
	switch(LED)
	{
		case LED0:
			DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
			break;
		case LED1:
			DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
			break;
		case LED2:
			DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);		
			break;
		
		default:
		break;
	}
}

void LED_Toggle(uint8 LED)
{
	switch (LED)
	{
		case LED0:
			DIO_TogglePin(DIO_PORTC,DIO_PIN2);
			break;
		case LED1:
			DIO_TogglePin(DIO_PORTC,DIO_PIN7);
			break;
		case LED2: 
			DIO_TogglePin(DIO_PORTD,DIO_PIN3);
			break;			
	}
	
}
