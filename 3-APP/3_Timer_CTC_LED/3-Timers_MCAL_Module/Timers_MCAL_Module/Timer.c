/*
 * Timer.c
 *
 * Created: 5/17/2021 9:47:22 PM
 *  Author: Moustafa Moubarak
 */ 
#include "Timer.h"
#include <avr/interrupt.h>

uint32	NUM_OVF_0		= 0;
uint8	INIT_VALUE_0	= 0;

uint32	NUM_OVF_1		= 0;
uint32	INIT_VALUE_1	= 0;

void(* PTR_0)(void);
void(* PTR_1)(void);

void Timer_Init(uint8 Timer)
{
	switch(Timer)
	{
		case Timer0:
			#if		TIMER0_WAVEFORM_GEN_Mode		==		Normal
				CLR_BIT(TCCR0, 3);
				CLR_BIT(TCCR0, 6);
				//Enable Global Interrupt
				Set_GlobalInterrupt();
				//Enable Overflow Interrupt
				SET_BIT(TIMSK, 0);
			 
			#elif	TIMER0_WAVEFORM_GEN_Mode		==		CTC
				SET_BIT(TCCR0, 3);
				CLR_BIT(TCCR0, 6);
				//Enable Global Interrupt
				Set_GlobalInterrupt();
				//Enable Output Compare Match Interrupt
				SET_BIT(TIMSK, 1);
			
			#elif	TIMER0_WAVEFORM_GEN_Mode		==		FAST_PWM
				// Fast PWM Mode
				SET_BIT(TCCR0, 3);
				SET_BIT(TCCR0, 6);
				// OC0 Pin Set to Output
				DIO_SetPINDir(PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
				#if		Timer0_PWM_WaveType				==		Non_Inverted
					CLR_BIT(TCCR0, 4);
					SET_BIT(TCCR0, 5);
				#elif	Timer0_PWM_WaveType				==		Inverted
					SET_BIT(TCCR0, 4);
					SET_BIT(TCCR0, 5);
				#endif
			#endif
			
			break;
		 
		case Timer1:
			#if		TIMER1_WAVEFORM_GEN_Mode		==		Normal
				CLR_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				CLR_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);			
				//Enable Global Interrupt
				Set_GlobalInterrupt();
				//Enable Overflow Interrupt
				SET_BIT(TIMSK, 2);
			
			#elif	TIMER1_WAVEFORM_GEN_Mode		==		CTC
				CLR_BIT(TCCR1A,0);
				CLR_BIT(TCCR1A,1);
				SET_BIT(TCCR1B,3);
				CLR_BIT(TCCR1B,4);
				//Enable Global Interrupt
				Set_GlobalInterrupt();
				//Enable Output Compare Match Interrupt
				SET_BIT(TIMSK, 4);
				
			#elif	TIMER0_WAVEFORM_GEN_Mode		==		FAST_PWM
				// Fast PWM Mode
				SET_BIT(TCCR0, 3);
				SET_BIT(TCCR0, 6);
				// OC0 Pin Set to Output
				DIO_SetPINDir(PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
				//Wave type Mode
				#if		Timer0_PWM_WaveType				==		Non_Inverted
					CLR_BIT(TCCR0, 4);
					SET_BIT(TCCR0, 5);
				#elif	Timer0_PWM_WaveType				==		Inverted
					SET_BIT(TCCR0, 4);
					SET_BIT(TCCR0, 5);
				#endif
			#endif
			break;
			
		default:
			break;
	}
}


void Timer_Start(uint8 Timer)
{
	switch(Timer)
	{
		case Timer0:
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
			break;
				
		case Timer1:
			#if		TIMER0_PRESCALER		==		TIMER0_NO_PRESCALLING
			SET_BIT(TCCR1B, 0);
			CLR_BIT(TCCR1B, 1);

			#elif	TIMER0_PRESCALER		==		TIMER0_PRESCALER_8
			SET_BIT(TCCR1B, 1);
			CLR_BIT(TCCR1B, 0);
			

			#elif	TIMER0_PRESCALER		==		TIMER0_PRESCALER_64
			SET_BIT(TCCR1B, 0);
			SET_BIT(TCCR1B, 1);
			
			#elif	TIMER0_PRESCALER		==		TIMER0_PRESCALER_256
			CLR_BIT(TCCR1B, 0);
			CLR_BIT(TCCR1B, 1);
			SET_BIT(TCCR1B, 2);
			
			#elif	TIMER0_PRESCALER		==		TIMER0_PRESCALER_1024
			SET_BIT(TCCR1B, 0);
			CLR_BIT(TCCR1B, 1);
			SET_BIT(TCCR1B, 2);
			
			#endif
			break;
		default:
			break;
	}
}

void Timer0_Stop(uint8 Timer)
{
	switch(Timer)
	{
		case Timer0:
			CLR_BIT(TCCR0, 0);
			CLR_BIT(TCCR0, 1);
			CLR_BIT(TCCR0, 2);
			break;
		case Timer1:
			CLR_BIT(TCCR1B, 0);
			CLR_BIT(TCCR1B, 1);
			CLR_BIT(TCCR1B, 2);
			break;
		default:
			break;
	}
}

Set_CallBack(uint8 Timer,void(* p)(void))
{
	switch(Timer)
	{
		case Timer0:
			PTR_0 = p;
		case Timer1:
			PTR_1 = p;
	}
	
}

void Timer_SetDelay(uint8 Timer, uint32 Delay_Ms)
{
	switch(Timer)
	{
		case Timer0:
		{
			#if		TIMER0_WAVEFORM_GEN_Mode	==		Normal
				uint8	Tick_Time = (PRESCALER_FACTOR_T0/16);
				
				uint32	Total_Ticks = ((Delay_Ms * 1000)/Tick_Time);
				
				NUM_OVF_0 = Total_Ticks/OVF_Ticks_T0 ;
				
				INIT_VALUE_0 = OVF_Ticks_T0 - (Total_Ticks % OVF_Ticks_T0);
				
				TCNT0	=	INIT_VALUE_0;
				
				if(INIT_VALUE_0 != 0)
				{
					NUM_OVF_0++;
				}
				
			#elif	TIMER0_WAVEFORM_GEN_Mode	==		CTC
				if (Delay_Ms < 16)
				{
					uint8 Tick_Time = PRESCALER_FACTOR_T0 / 16;
					uint32 Total_Ticks = (Delay_Ms * 1000) / Tick_Time;
					OCR0 = Total_Ticks - 1;
				}
			#endif
			break;
		}
		case Timer1:
		{
			#if		TIMER1_WAVEFORM_GEN_Mode	==		Normal
				uint8	Tick_Time = (PRESCALER_FACTOR_T1/16);
				
				uint32	Total_Ticks = ((Delay_Ms * 1000)/Tick_Time);
				
				NUM_OVF_1 = Total_Ticks/OVF_Ticks_T1 ;
				
				INIT_VALUE_1 = OVF_Ticks_T1 - (Total_Ticks % OVF_Ticks_T1);
				
				TCNT1	=	INIT_VALUE_1;
				
				if(INIT_VALUE_1 != 0)
				{
					NUM_OVF_1++;
				}
			#elif	TIMER1_WAVEFORM_GEN_Mode	==		CTC
				if (Delay_Ms < 4000)
				{
					uint8 Tick_Time = PRESCALER_FACTOR_T1 / 16;
					uint32 Total_Ticks = (Delay_Ms * 1000) / Tick_Time;
					OCR1A = Total_Ticks - 1;
				}
			#endif
			break;
		}
			default:
			break;
		}
}

void PWM_Generate(uint8 Timer,uint16 Duty_Cycle)
{
	switch(Timer)
	{
		case Timer0:
		#if			Timer0_PWM_WaveType			==		Non_Inverted
		OCR0 = ((Duty_Cycle-OVF_Ticks_T0)/100)-1;
		
		#elif		Timer0_PWM_WaveType			==		Inverted
		OCR0 = 255-((Duty_Cycle * OVF_Ticks_T0)/100);
		#endif
	}
}

ISR(TIMER0_OVF_vect)
{
	static uint32 cnt = 0;
	
	cnt++;
	
	if(cnt == NUM_OVF_0)
	{
		cnt = 0;
		(*PTR_0)();
		TCNT0 - INIT_VALUE_0;
	}
}
ISR(TIMER0_COMP_vect)
{
	(*PTR_0)();
}

ISR(TIMER1_OVF_vect)
{
	static uint32 cnt = 0;
	
	cnt++;
	
	if(cnt == NUM_OVF_1)
	{
		cnt = 0;
		(*PTR_1)();
		TCNT1 - INIT_VALUE_1;
	}
}

ISR(TIMER1_COMPA_vect)
{
	(*PTR_1)();
}