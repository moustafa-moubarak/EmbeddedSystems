/*
 * LED_HAL.c
 *
 * Created: 4/13/2021 11:41:07 PM
 *  Author: Moustafa Moubarak
 */ 
#include "LED_HAL.h"

void LED0_Init(void)
{
	DIO_SetPINDir(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);	
}

void LED0_ON(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_HIGH);
}

void LED0_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN2,DIO_PIN_LOW);
}

void LED0_Toggle(void)
{
	DIO_TogglePin(DIO_PORTC,DIO_PIN2);
}


void LED1_Init(void)
{
	DIO_SetPINDir(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
}

void LED1_ON(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_HIGH);
}

void LED1_OFF(void)
{
	DIO_SetPinValue(DIO_PORTC,DIO_PIN7,DIO_PIN_LOW);
}

void LED1_Toggle(void)
{
	DIO_TogglePin(DIO_PORTC,DIO_PIN7);
}


void LED2_Init(void)
{
	DIO_SetPINDir(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
}

void LED2_ON(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_HIGH);
}

void LED2_OFF(void)
{
	DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_PIN_LOW);
}

void LED2_Toggle(void)
{
	DIO_TogglePin(DIO_PORTD,DIO_PIN3);
}