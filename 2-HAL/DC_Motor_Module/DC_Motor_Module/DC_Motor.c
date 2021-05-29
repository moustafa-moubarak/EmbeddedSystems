/*
 * DC_Motor.c
 *
 * Created: 5/27/2021 8:58:03 AM
 *  Author: Moustafa Moubarak
 */ 
#include "DC_Motor.h"

void DC_Motor_Init(void)
{
		Timer_Init(Timer0);		
		DIO_SetPINDir(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);
		DIO_SetPINDir(DIO_PORTC,DIO_PIN4,DIO_PIN_OUTPUT);
	
}

void DC_Motor_Start(void)
{
		Timer_Start(Timer0);
}

void DC_Motor_Stop(void)
{
		DIO_SetPinValue(DIO_PORTC, DIO_PIN3,DIO_PIN_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN4,DIO_PIN_LOW);
}

void DC_Motor_Set_Speed(uint8 speed)
{
		PWM_Generate(Timer0,speed);
}

void DC_Motor_Set_Dir(DC_Motor_Dir dir)
{
	switch(dir)
	{
		case CLOCK_WISE_DIR :
		DIO_SetPinValue(DIO_PORTC, DIO_PIN3, DIO_PIN_HIGH);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN4, DIO_PIN_LOW);
		break;
		case ANTI_CLOCK_WISE_DIR :
		DIO_SetPinValue(DIO_PORTC, DIO_PIN3, DIO_PIN_HIGH);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN4, DIO_PIN_HIGH);
		break;
		default:
		break;
	}
}
void DC_Motor_Toggle (void)
{
	int x =0;
	DIO_ReadPinValue(DIO_PORTC, DIO_PIN3, &x);
	if( x == DIO_PIN_HIGH)
	{
		DC_Motor_Stop();
	}
	else
	{
		DC_Motor_Start();
	}
}

