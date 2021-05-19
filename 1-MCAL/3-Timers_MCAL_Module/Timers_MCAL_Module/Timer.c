/*
 * Timer.c
 *
 * Created: 5/17/2021 9:47:22 PM
 *  Author: Moustafa Moubarak
 */ 
#include "Timer.h"

uint32	NUM_OVF		= 0;
uint8	INIT_VALUE	= 0;

void Timer0_Init(void)
{
	#if		WAVEFORM_GEN_Mode		==		Normal
		CLR_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
	
	#elif	WAVEFORM_GEN_Mode		==		PWM	
		SET_BIT(TCCR0, 6);
		CLR_BIT(TCCR0, 3);
	
	#elif	WAVEFORM_GEN_Mode		==		CTC
		SET_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
		
	#elif	WAVEFORM_GEN_Mode		==		FAST_PWM		
		SET_BIT(TCCR0, 6);
		SET_BIT(TCCR0, 3);
	#endif	
	
	//Enable Global Interrupt
	Set_GlobalInterrupt();
	
	//Enable Overflow Interrupt
	SET_BIT(TIMSK, 0);
}

void Timer0_SetDelay(uint32 Delay_Ms)
{
	uint8	Tick_Time = (PRESCALER_FACTOR/16);
	
	uint32	Total_Ticks = ((Delay_Ms * 1000)/Tick_Time);
	
	NUM_OVF = Total_Ticks/OVF_Ticks ;
	
	INIT_VALUE = 256 - (Total_Ticks % OVF_Ticks);
	
	TCNT0	=	INIT_VALUE;
	
	if(INIT_VALUE != 0)
	{
		NUM_OVF++;
	}
	
}

void Timer0_Start(void)
{
	#if		TIMER0_PRESCALER		==		TIMER0_NO_PRESCALLING
	SET_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);

	#elif	TIMER0_PRESCALER		==		TIMER0_PRESCALER_8
	SET_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 0);
	

	#elif	TIMER0_PRESCALER		==		TIMER0_PRESCALER_64
	SET_BIT(TCCR0, 0);
	SET_BIT(TCCR0, 1);
	
	#elif	TIMER0_PRESCALER		==		TIMER0_PRESCALER_256
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	
	#elif	TIMER0_PRESCALER		==		TIMER0_PRESCALER_1024
	SET_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	SET_BIT(TCCR0, 2);
	
	#endif	
}

void Timer0_Stop(void)
{
	CLR_BIT(TCCR0, 0);
	CLR_BIT(TCCR0, 1);
	CLR_BIT(TCCR0, 2);
}

