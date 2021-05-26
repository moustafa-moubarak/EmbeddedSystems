/*
 * LED_HAL.h
 *
 * Created: 4/13/2021 11:41:26 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef LED_HAL_H_
#define LED_HAL_H_
#include "DIO_MCAL.h"

void LED0_Init(void);
void LED0_ON(void);
void LED0_OFF(void);
void LED0_Toggle(void);

void LED1_Init(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED1_Toggle(void);

void LED2_Init(void);
void LED2_ON(void);
void LED2_OFF(void);
void LED2_Toggle(void);



#endif /* LED_HAL_H_ */