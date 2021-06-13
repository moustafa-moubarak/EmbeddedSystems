/*
 * EEPROM.h
 *
 * Created: 6/13/2021 10:53:54 AM
 *  Author: Moustafa Moubarak
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"

void EEPROM_Init(void);

void EEPROM_WriteData(uint8 data, uint8 loc);

void EEPROM_WriteMultipleData(uint8* data, uint8 size, uint8 loc);

uint8 EEPROM_ReadData(uint8 loc);

#endif /* EEPROM_H_ */