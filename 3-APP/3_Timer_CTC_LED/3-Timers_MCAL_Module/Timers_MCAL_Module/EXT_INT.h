/*
 * EXT_INT.h
 *
 * Created: 4/17/2021 10:50:43 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "MCU.h"
#include "BIT_Math.h"
#include "STD.h"
#include "EXT_INT_Config.h"

#define		GLOBAL_INTERRUPT_ENABLE			0
#define		GLOBAL_INTERRUPT_DISABLE		1

/*From DataSheet get the values of registers to write it in cfile*/
#define		TRIGGER_RISING							0
#define		TRIGGER_FALLING							1				
#define		TRIGGER_LOW_LEVEL						2				
#define		TRIGGER_ANY_LOGICAL_CHANGE				3


void Set_GlobalInterrupt(void);

void External_INT0_Init (void);
void External_INT1_Init (void);
void External_INT2_Init (void);				
				

#endif /* EXT_INT_H_ */