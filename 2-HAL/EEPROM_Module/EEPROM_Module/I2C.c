/*
 * I2C.c
 *
 * Created: 6/12/2021 7:48:28 PM
 *  Author: Moustafa Moubarak
 */ 

#include "I2C.h"

void I2C_Master_Init(void)
{
	/*CLK I2C 400kHz*/
	I2C->TWBR = 0X0C;
	
	CLR_BIT(I2C->TWSR, 0);
	CLR_BIT(I2C->TWSR, 1);
	
	/*Enable I2C*/
	SET_BIT(TWCR, 2);
}

void I2C_Slave_Init(void)
{
	/*Slave Address 0x01*/
	I2C->TWAR = (0x01 << 1);
	
	/*Enable I2C*/
	SET_BIT(TWCR, 2);
}

void I2C_Start_Condition(void)
{
	/*I2C Start Condition(Bit 5)*/
	/*Make the Flag Down to run a process(Bit 7)*/
	/*We need to Enable I2C each time(Bit 2)*/
	TWCR |= 0xA4;
	
	/*Blocking on Flag*/
	while(GET_BIT(TWCR,7) != 0);
	
	/*Blocking on the Operation Status*/
	while ((I2C->TWSR & 0xf8) != START_ACK);
}

void I2C_RepeatedStart(void)
{
	/*I2C Start Condition(Bit 5)*/
	/*Make the Flag Down to run a process(Bit 7)*/
	/*We need to Enable I2C each time(Bit 2)*/
	TWCR = 0xA4;
	
	/*Blocking on Flag*/
	while(GET_BIT(TWCR,7) != 0);
	
	/*Blocking on the Operation Status*/
	while ((I2C->TWSR & 0xf8) != REP_START_ACK);
}

void I2C_Send_SlaveAddr_Write_Operation(uint8 addr)
{
	/*Slave Address with write operation*/
	I2C->TWDR = (addr<<1);
	
	/*Make the Flag Down to run a process(Bit 7)*/
	/*We need to Enable I2C each time(Bit 2)*/
	TWCR = 0x84;
	
	/*Blocking on Flag*/
	while(GET_BIT(TWCR,7) != 0);
	
	/*Blocking on the Operation Status*/
	while ((I2C->TWSR & 0xf8) != SLVAE_ADD_AND_WR_ACK);
}

void I2C_Send_SlaveAddr_Read_Operation(uint8 addr)
{
	/*Slave Address with Read operation*/
	I2C->TWDR = (addr<<1) | (0x01);
	
	/*Make the Flag Down to run a process(Bit 7)*/
	/*We need to Enable I2C each time(Bit 2)*/
	TWCR = 0x84;
	
	/*Blocking on Flag*/
	while(GET_BIT(TWCR,7) != 0);
	
	/*Blocking on the Operation Status*/
	while ((I2C->TWSR & 0xf8) != SLVAE_ADD_AND_RD_ACK);
}

void I2C_Send_DataByte(uint8 data)
{
	/*Send Data Byte*/
	I2C->TWDR = data;
	
	/*Make the Flag Down to run a process(Bit 7)*/
	/*We need to Enable I2C each time(Bit 2)*/
	TWCR = 0x84;
	
	/*Blocking on Flag*/
	while(GET_BIT(TWCR,7) != 0);
	
	/*Blocking on the Operation Status*/
	while ((I2C->TWSR & 0xf8) != WR_BYTE_ACK);
}

uint8 I2C_Read_DataByte(void)
{
	/*Make the Flag Down to run a process(Bit 7)*/
	/*We need to Enable I2C each time(Bit 2)*/
	TWCR = 0x84;
	
	/*Blocking on Flag*/
	while(GET_BIT(TWCR,7) != 0);
	
	/*Blocking on the Operation Status*/
	while ((I2C->TWSR & 0xF8) != RD_BYTE_WITH_ACK);
	
	return I2C->TWDR;
}

void I2C_Stop_Condition(void)
{
	TWCR = 0X94;
}
