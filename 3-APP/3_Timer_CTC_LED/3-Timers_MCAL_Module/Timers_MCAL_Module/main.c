/*
 * Timers_MCAL_Module.c
 *
 * Created: 5/17/2021 9:35:42 PM
 * Author : Moustafa Moubarak
 */ 

#include "Timer.h"
#include "LED_HAL.h"


extern uint32	NUM_OVF_0	;
extern uint8	INIT_VALUE_0 ;

extern uint32	NUM_OVF_1	;
extern uint32	INIT_VALUE_1 ;

int main(void)
{
	LED0_Init();
	Timer_Init(Timer0);
	Set_CallBack(Timer0, LED0_Toggle);
	Timer_SetDelay(Timer0, 15); 
	Timer_Start(Timer0);
    while (1) 
    {
    }
}

/*
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
*/

