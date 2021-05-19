/*
 * Timers_MCAL_Module.c
 *
 * Created: 5/17/2021 9:35:42 PM
 * Author : Moustafa Moubarak
 */ 

#include "Timer.h"
#include "LED_HAL.h"
#include <avr/interrupt.h>

extern uint32	NUM_OVF	;
extern uint8	INIT_VALUE;

int main(void)
{
	LED0_Init();
	Timer0_Init();
	Timer0_SetDelay(2000); 
	Timer0_Start();
    while (1) 
    {
    }
}

ISR(TIMER0_OVF_vect)
{
	static uint32 cnt = 0;
	
	cnt++;
	
	if(cnt == NUM_OVF)
	{
		cnt = 0;
		LED0_Toggle();
		TCNT0 - INIT_VALUE;
	}
	
}

