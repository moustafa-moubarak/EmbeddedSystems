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
#include "EXT_INT.h"

#define		Normal				0
#define		PWM					1
#define		CTC					2
#define		FAST_PWM			3

#define		TIMER0_NO_PRESCALLING		0
#define		TIMER0_PRESCALER_8			1
#define		TIMER0_PRESCALER_64			2
#define		TIMER0_PRESCALER_256		3
#define		TIMER0_PRESCALER_1024		4

			

void Timer0_Init(void);

void Timer0_SetDelay(uint32 Delay_Ms);

void Timer0_Start(void);

void Timer0_Stop(void);


#endif /* TIMER_H_ */