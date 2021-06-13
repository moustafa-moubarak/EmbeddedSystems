/*
 * I2C.h
 *
 * Created: 6/12/2021 7:48:39 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "BIT_Math.h"
#include "STD.h"
#include "MCU.h"

#define			START_ACK					0X08	//Start has been sent
#define			REP_START_ACK				0X10	//Repeated Start
#define			SLVAE_ADD_AND_WR_ACK		0X18	//Master Transmitted (Slave Address + Write Request) ACK
#define			SLVAE_ADD_AND_RD_ACK		0X40	//Master Transmitted (Slave Address + Read Request) ACK
#define			WR_BYTE_ACK					0X28	//Master Transmitted Data ACK
#define			RD_BYTE_WITH_ACK			0X58	//Master Received Data with Acknowledge 
#define			SLAVE_ADD_RCVD_RD_REQ		0XA8	//Slave Address received with Read Request
#define			SLAVE_ADD_RCVD_WR_REQ		0X60	//Slave Address received with Write Request
#define			SLAVE_DATA_RECIEVED			0X80	//Read Byte request received
#define			SLAVE_BYTE_TRANSMITTED		0XC0	//Write byte request received

void I2C_Master_Init(void);

void I2C_Slave_Init(void);

void I2C_Start_Condition(void);

void I2C_RepeatedStart(void);

void I2C_Send_SlaveAddr_Write_Operation(uint8 addr);

void I2C_Send_SlaveAddr_Read_Operation(uint8 addr);

void I2C_Send_DataByte(uint8 data);

uint8 I2C_Read_DataByte(void);

void I2C_Stop_Condition(void);


#endif /* I2C_H_ */