/*
 * SPI.h
 *
 * Created: 6/3/2021 11:59:10 AM
 *  Author: Moustafa Moubarak
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO_MCAL.h"

void SPI_Master_Init(void);
void SPI_Slave_Init(void);

void SPI_Master_InitTrans(void);
void SPI_Master_TermTrans(void);

uint8 SPI_TranSiver(uint8 data);

#endif /* SPI_H_ */