/*
 * MCU.h
 *
 * Created: 3/13/2021 2:23:47 PM
 *  Author: Ali
 */ 


#ifndef MCU_H_
#define MCU_H_

#include  "STD.h"

/****************** DIO REG ******************/

#define		PORTA		*((volatile uint8*) 0x3B)
#define		DDRA		*((volatile uint8*) 0x3A)
#define		PINA		*((volatile uint8*) 0x39)

#define		PORTB		*((volatile uint8*) 0x38)
#define		DDRB		*((volatile uint8*) 0x37)
#define		PINB		*((volatile uint8*) 0x36)

#define		PORTC		*((volatile uint8*) 0x35)
#define		DDRC		*((volatile uint8*) 0x34)
#define		PINC		*((volatile uint8*) 0x33)

#define		PORTD		*((volatile uint8*) 0x32)
#define		DDRD		*((volatile uint8*) 0x31)
#define		PIND		 *((volatile uint8*) 0x30)

/****************** EXT INT REG ******************/

#define		SREG		*((volatile uint8*) 0x5F)
#define		MCUCR		*((volatile uint8*) 0x55)
#define		MCUSR		*((volatile uint8*) 0x54)
#define		GICR		*((volatile uint8*) 0x5B)
#define		GIFR		*((volatile uint8*) 0x5A)

/****************** ADC REG ******************/

#define		ADMUX		(*(volatile uint8*)(0x27))
#define		ADCSRA		(*(volatile uint8*)(0x26))
#define		ADCH		(*(volatile uint8*)(0x25))
#define		ADCL		(*(volatile uint8*)(0x24))
#define		SFIOR		(*(volatile uint8*)(0x50))
#define		ADC_FINAL	(*(volatile uint16*)(0x24))


#endif /* MCU_H_ */