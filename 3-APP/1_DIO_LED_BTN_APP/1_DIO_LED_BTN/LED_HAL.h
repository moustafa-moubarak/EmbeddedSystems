/*
 * LED_HAL.h
 *
 * Created: 4/13/2021 11:41:26 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef LED_HAL_H_
#define LED_HAL_H_

#include "DIO_MCAL.h"

#define LED0	0
#define LED1	1
#define LED2	2


void LED_Init(uint8 LED);
void LED_ON(uint8 LED);
void LED_OFF(uint8 LED);
void LED_Toggle(uint8 LED);

#endif /* LED_HAL_H_ */