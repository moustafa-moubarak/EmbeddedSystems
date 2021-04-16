/*
 * 1_DIO_LED_BTN.c
 *
 * Created: 4/14/2021 1:28:01 PM
 * Author : Moustafa Moubarak
 */ 

#include "LED_HAL.h"
#include "BTN_HAL.h"

int main(void)
{
	LED_Init(LED0);	
	BTN_INIT(BTN0);
	LED_Init(LED1);
	BTN_INIT(BTN1);
	LED_Init(LED2);
	BTN_INIT(BTN2);
	uint8 val0;
	uint8 val1;
	uint8 val2;
    
	while (1) 
    {
		val0 = BTN_GetValue(BTN0);
		
		if (val0 == 1)
		{
			LED_Toggle(LED0);
		}
		val1 = BTN_GetValue(BTN1);
		
		if (val1 == 1)
		{
			LED_Toggle(LED1);
		}
		val2 = BTN_GetValue(BTN2);
		
		if (val2 == 1)
		{
			LED_Toggle(LED2);
		}
    }
}

