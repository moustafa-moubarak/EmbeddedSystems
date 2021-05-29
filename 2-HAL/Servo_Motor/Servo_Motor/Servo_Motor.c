/*
 * Servo_Motor.c
 *
 * Created: 5/29/2021 10:32:54 AM
 *  Author: Moustafa Moubarak
 */ 
#include "Servo_Motor.h"

void Servo_Motor_Init(void)
{
	Timer_Init(Timer1);
	PWM_Freq_Generate(50);
	Timer_Start(Timer1);
	
}

void Servo_Motor_Rotate(float32 degree)
{
	float32 Duty_Cycle = ((degree*5)/180)+5;
	PWM_Generate(Timer1,Duty_Cycle);	
}
