/*
 * EXT_INT.c
 *
 * Created: 4/17/2021 10:50:23 PM
 *  Author: Moustafa Moubarak
 */ 

#include "EXT_INT.h"

void Set_GlobalInterrupt(void)
{
	#if		GLOBAL_INTERRUPT		==		GLOBAL_INTERRUPT_ENABLE	
		SET_BIT(SREG, 7);
	
	#elif	GLOBAL_INTERRUPT		==		GLOBAL_INTERRUPT_DISABLE	
		CLR_BIT(SREG, 7);

	#endif
}

void External_INT0_Init (void)
{	
	/*General Interrupt Enable*/
	Set_GlobalInterrupt();

	/*Interrupt FLAG Enable INT0*/
	SET_BIT(GICR,6);
	
		
	#if		EXTERNAL_INT0_TRIGGER		==		TRIGGER_RISING
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		
	#elif	EXTERNAL_INT0_TRIGGER		==		TRIGGER_FALLING
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	
	#elif	EXTERNAL_INT0_TRIGGER		==		TRIGGER_LOW_LEVEL	
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		
	#elif	EXTERNAL_INT0_TRIGGER		==		TRIGGER_ANY_LOGICAL_CHANGE
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		
#endif
}

void External_INT1_Init (void)
{
	Set_GlobalInterrupt();

	/*Interrupt FLAG Enable INT1*/
	SET_BIT(GICR,7);
	
	
	#if		EXTERNAL_INT0_TRIGGER		==		TRIGGER_RISING
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	
	#elif	EXTERNAL_INT0_TRIGGER		==		TRIGGER_FALLING
		CLR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	
	#elif	EXTERNAL_INT0_TRIGGER		==		TRIGGER_LOW_LEVEL
		CLR_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	
	#elif	EXTERNAL_INT0_TRIGGER		==		TRIGGER_ANY_LOGICAL_CHANGE
		SET_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	
	#endif
}
void External_INT2_Init (void)
{
	CLR_BIT(GICR,5);
	/*General Interrupt Enable*/
	Set_GlobalInterrupt();

	/*Interrupt FLAG Enable INT2*/
	SET_BIT(GICR,5);
	
	
	#if		EXTERNAL_INT0_TRIGGER		==		TRIGGER_RISING
	SET_BIT(MCUSR,6);
	
	
	#elif	EXTERNAL_INT0_TRIGGER		==		TRIGGER_FALLING
	CLR_BIT(MCUSR,6);
	
	
	#endif
}