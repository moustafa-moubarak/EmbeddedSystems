/*
 * BTN_HAL.h
 *
 * Created: 4/14/2021 12:09:45 AM
 *  Author: Moustafa Moubarak
 */ 


#ifndef BTN_HAL_H_
#define BTN_HAL_H_

#include "DIO_MCAL.h"
#include "DIO_MCAL.h"

#define	F_CPU	16000000
#include <util/delay.h>

#define BTN0	0
#define BTN1	1
#define BTN2	2

void BTN0_INIT (void);
uint8 BTN0_GetValue (void);

void BTN1_INIT (void);
uint8 BTN1_GetValue (void);

void BTN2_INIT (void);
uint8 BTN2_GetValue (void);

void BTN_INIT(uint8 BTN);
uint8 BTN_GetValue(uint8 BTN);



#endif /* BTN_HAL_H_ */