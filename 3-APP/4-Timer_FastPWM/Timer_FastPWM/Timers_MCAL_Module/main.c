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
	Timer_Init(Timer1);
	PWM_Generate(Timer1, 100);
	Timer_Start(Timer1);
	
	/*LED0_Init();
	Timer_Init(Timer1);
	Set_CallBack(Timer1, LED0_Toggle);
	Timer_SetDelay(Timer1, 15);
	Timer_Start(Timer1);*/
	
    while (1) 
    {
    }
}

