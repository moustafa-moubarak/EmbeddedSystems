/*
 * LCD_Config_HAL.h
 *
 * Created: 4/15/2021 2:25:09 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef LCD_CONFIG_HAL_H_
#define LCD_CONFIG_HAL_H_

#include "DIO_MCAL.h"

#define			LCD_MODE						4

#define			LCD_8BIT_MODE_CMD_PORT			DIO_PORTA
#define			LCD_8BIT_MODE_DATA_PORT			DIO_PORTC
#define			LCD_8BIT_MODE_D_PORT				PORTC

#define			LCD_4BIT_MODE_CMD_PORT			DIO_PORTB
#define			LCD_4BIT_MODE_DATA_PORT			DIO_PORTA
#define			LCD_4BIT_MODE_D_PORT				PORTA


#define			LCD_RS_PIN						DIO_PIN1
#define			LCD_CMD_REG						DIO_PIN_LOW
#define			LCD_DATA_REG					DIO_PIN_HIGH

#define			LCD_RW_PIN						DIO_PIN2
#define			LCD_WRITE						DIO_PIN_LOW
#define			LCD_READ						DIO_PIN_HIGH

#define			LCD_E_PIN						DIO_PIN3	
#define			LCD_E_LOW						DIO_PIN_LOW				
#define			LCD_E_HIGH						DIO_PIN_HIGH				

#define			LCD_DATA_PIN0					DIO_PIN0
#define			LCD_DATA_PIN1					DIO_PIN1
#define			LCD_DATA_PIN2					DIO_PIN2
#define			LCD_DATA_PIN3					DIO_PIN3	
#define			LCD_DATA_PIN4					DIO_PIN4
#define			LCD_DATA_PIN5					DIO_PIN5
#define			LCD_DATA_PIN6					DIO_PIN6
#define			LCD_DATA_PIN7					DIO_PIN7




#endif /* LCD_CONFIG_HAL_H_ */