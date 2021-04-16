/*
 * LCD_HAL.h
 *
 * Created: 4/15/2021 2:24:45 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef LCD_HAL_H_
#define LCD_HAL_H_

#include "LCD_Config_HAL.h"
#define	 F_CPU		16000000
#include <util/delay.h>

void LCD_Init(void);

void LCD_Write_Command(uint8 cmd);

void LCD_Clear(void);

void LCD_Write_Char (uint8 data);

void LCD_Write_String (uint8* str);

void LCD_GoToLoc(uint8 row, uint8 col);


#endif /* LCD_HAL_H_ */