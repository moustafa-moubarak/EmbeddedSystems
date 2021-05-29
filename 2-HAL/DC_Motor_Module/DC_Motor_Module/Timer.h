/*
 * Timer.h
 *
 * Created: 5/17/2021 9:47:33 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "BIT_Math.h"
#include "MCU.h"
#include "Timer_Config.h"
#include "DIO_MCAL.h"

#define		Normal				0
#define		PC_PWM				1
#define		CTC					2
#define		FAST_PWM			3

#define		TIMER0_NO_PRESCALLING		0
#define		TIMER0_PRESCALER_8			1
#define		TIMER0_PRESCALER_64			2
#define		TIMER0_PRESCALER_256		3
#define		TIMER0_PRESCALER_1024		4

#define		TIMER1_NO_PRESCALLING		0
#define		TIMER1_PRESCALER_8			1
#define		TIMER1_PRESCALER_64			2
#define		TIMER1_PRESCALER_256		3
#define		TIMER1_PRESCALER_1024		4
			
#define		Timer0						0
#define		Timer1						1

#define		Non_Inverted				0
#define		Inverted					1

void Timer_Init(uint8 Timer);

void Timer_Start(uint8 Timer);

void Timer_Stop(uint8 Timer);

void Timer_SetDelay(uint8 Timer, uint32 Delay_Ms);

Set_CallBack(uint8 Timer,void(* p)(void));

void PWM_Generate(uint8 Timer,uint16 Duty_Cycle);

#endif /* TIMER_H_ */