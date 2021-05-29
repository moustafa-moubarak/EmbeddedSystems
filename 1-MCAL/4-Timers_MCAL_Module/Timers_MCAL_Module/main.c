/*
 * Timers_MCAL_Module.c
 *
 * Created: 5/17/2021 9:35:42 PM
 * Author : Moustafa Moubarak
 */ 

#include "Timer.h"


extern uint32	NUM_OVF_0	;
extern uint8	INIT_VALUE_0 ;

extern uint32	NUM_OVF_1	;
extern uint32	INIT_VALUE_1 ;

int main(void)
{	
	Timer_Init(Timer1);
	PWM_Freq_Generate(50);
	Timer_Start(Timer1);
	PWM_Generate(Timer1,7.5);
	
    while (1) 
    {
    }
}

