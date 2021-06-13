/*
 * EEPROM.c
 *
 * Created: 6/13/2021 10:53:35 AM
 *  Author: Moustafa Moubarak
 */
#include "EEPROM.h"

void EEPROM_Init(void)
{
	I2C_Master_Init();
}

void EEPROM_WriteData(uint8 data, uint8 loc)
{
	I2C_Start_Condition();
	I2C_Send_SlaveAddr_Write_Operation(0b0101000);
	I2C_Send_DataByte(loc);
	I2C_Send_DataByte(data);
	I2C_Stop_Condition();
}

void EEPROM_WriteMultipleData(uint8* data, uint8 size, uint8 loc)
{
	uint8 i = 0;
	I2C_Start_Condition();
	I2C_Send_SlaveAddr_Write_Operation(0b0101000);
	I2C_Send_DataByte(loc);
	while (i< size)
	{
		I2C_Send_DataByte(data[i]);	
		i++;
	}
	I2C_Stop_Condition();
}


uint8 EEPROM_ReadData(uint8 loc)
{
	uint8 data;
	
	I2C_Start_Condition();
	I2C_Send_SlaveAddr_Write_Operation(0b0101000);
	I2C_Send_DataByte(loc);
	I2C_RepeatedStart();
	I2C_Send_SlaveAddr_Read_Operation(0b0101000);
	
	data = I2C_Read_DataByte();
	I2C_Stop_Condition();
	
	return data;
}