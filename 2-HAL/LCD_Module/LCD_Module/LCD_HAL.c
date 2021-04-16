/*
 * LCD_HAL.c
 *
 * Created: 4/15/2021 2:24:26 PM
 *  Author: Moustafa Moubarak
 */ 

#include "LCD_HAL.h"

void LCD_Init(void)
{
	#if LCD_MODE	==		8
		DIO_SetPINDir(LCD_8BIT_MODE_CMD_PORT, LCD_RS_PIN,	DIO_PIN_OUTPUT);
		DIO_SetPINDir(LCD_8BIT_MODE_CMD_PORT, LCD_RW_PIN,	DIO_PIN_OUTPUT);
		DIO_SetPINDir(LCD_8BIT_MODE_CMD_PORT, LCD_E_PIN,	DIO_PIN_OUTPUT);
		
		DIO_SetPortDir(LCD_8BIT_MODE_DATA_PORT, DIO_PORT_OUTPUT);
		
		_delay_ms(100);
		
		LCD_Write_Command(0x38);
		LCD_Write_Command(0x0C);
		LCD_Write_Command(0x0E);
		LCD_Write_Command(0x01);
		LCD_Write_Command(0x02);

	#elif LCD_MODE	==		4
		DIO_SetPINDir(LCD_4BIT_MODE_CMD_PORT, LCD_RS_PIN,	DIO_PIN_OUTPUT);
		DIO_SetPINDir(LCD_4BIT_MODE_CMD_PORT, LCD_RW_PIN,	DIO_PIN_OUTPUT);
		DIO_SetPINDir(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN,	DIO_PIN_OUTPUT);
		
		DIO_SetPINDir(LCD_4BIT_MODE_DATA_PORT, LCD_DATA_PIN4, DIO_PIN_OUTPUT);
		DIO_SetPINDir(LCD_4BIT_MODE_DATA_PORT, LCD_DATA_PIN5, DIO_PIN_OUTPUT);
		DIO_SetPINDir(LCD_4BIT_MODE_DATA_PORT, LCD_DATA_PIN6, DIO_PIN_OUTPUT);
		DIO_SetPINDir(LCD_4BIT_MODE_DATA_PORT, LCD_DATA_PIN7, DIO_PIN_OUTPUT);
		
		_delay_ms(100);
	
		LCD_Write_Command(0x33);
		LCD_Write_Command(0x32);
		LCD_Write_Command(0x28);
		LCD_Write_Command(0x06);
		LCD_Write_Command(0x0E);
		LCD_Write_Command(0x01);
		LCD_Write_Command(0x02);
		
	#endif	
}

void LCD_Write_Command(uint8 cmd)
{
	#if		LCD_MODE	==			4
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_RS_PIN, LCD_CMD_REG);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_RW_PIN, LCD_WRITE);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_LOW);

		LCD_4BIT_MODE_D_PORT = (cmd & 0x0F) | (LCD_4BIT_MODE_D_PORT & 0xF0);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_HIGH);
		_delay_ms(1);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_LOW);
	
		LCD_4BIT_MODE_D_PORT = (cmd << 4) | (LCD_4BIT_MODE_D_PORT & 0xF0);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_HIGH);
		_delay_ms(1);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_LOW);
		_delay_ms(5);
	
		
	#elif	LCD_MODE		==		8
		DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT, LCD_RS_PIN, LCD_CMD_REG);
		DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT, LCD_RW_PIN, LCD_WRITE);
		DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_LOW);

		LCD_8BIT_MODE_D_PORT = cmd;
		_delay_ms(5);
		
	#endif

}

void LCD_Clear(void)
{
	LCD_Write_Command(0x01);
}

void LCD_Write_Char (uint8 data)
{
	#if		LCD_MODE	==			4
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_RS_PIN, LCD_DATA_REG);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_RW_PIN, LCD_WRITE);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_LOW);

		LCD_4BIT_MODE_D_PORT = (data & 0x0F) | (LCD_4BIT_MODE_D_PORT & 0xF0);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_HIGH);
		_delay_ms(1);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_LOW);

		LCD_4BIT_MODE_D_PORT = (data << 4) | (LCD_4BIT_MODE_D_PORT & 0xF0);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_HIGH);
		_delay_ms(1);
		DIO_SetPinValue(LCD_4BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_LOW);
		_delay_ms(5);


	#elif	LCD_MODE		==		8
		DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT, LCD_RS_PIN, LCD_DATA_REG);
		DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT, LCD_RW_PIN, LCD_WRITE);
		DIO_SetPinValue(LCD_8BIT_MODE_CMD_PORT, LCD_E_PIN, LCD_E_LOW);

		LCD_8BIT_MODE_D_PORT = data;
		_delay_ms(5);

	#endif
}

void LCD_Write_String (uint8* str)
{
	uint8 cnt = 0;
	while(str[cnt] != '\0')
	{
		LCD_Write_Char(str[cnt]);
		cnt++;
	}
}

void LCD_GoToLoc(uint8 row, uint8 col)
{
	uint8 Loc[2] = {0x80, 0xC0};
	
	LCD_Write_Command(Loc[row]+col);
}

void LCD_Write_Int(sint32 num)
{
	
}
