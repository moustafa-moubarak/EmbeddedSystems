/*
 * EXT_INT_HAL.c
 *
 * Created: 4/17/2021 10:47:40 PM
 * Author : Moustafa Moubarak
 */ 

#include "EXT_INT_Config.h"
#include "LED_HAL.h"
#include <avr/interrupt.h>


int main(void)
{
	LED0_Init();
	
	External_INT0_Init();
	
    while (1) 
    {
    }
}
ISR(INT0_vect)
{
	LED0_Toggle();
}

