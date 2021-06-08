/*
 * 5_UART_LCD_APP.c
 *
 * Created: 5/31/2021 10:14:17 PM
 * Author : Moustafa Moubarak
 */ 

#include "LCD_HAL.h"
#include "UART.h"

int main(void)
{
	uint8 data = 0;
	LCD_Init();
	UART_Init();
	
	
	
 
    while (1) 
    {
		data = UART_Rx();
		if (data)
		{
			LCD_Write_Char(data);
			data = 0;
		}
    }
}

