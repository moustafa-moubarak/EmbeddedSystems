/*
 * DIO_MCAL.c
 *
 * Created: 4/13/2021 3:09:23 PM
 *  Author: Moustafa Moubarak
 */ 
#include "DIO_MCAL.h"

void DIO_SetPortDir(uint8 port, uint8 direction)
{
	switch(port)
	{
		case DIO_PORTA:
			DDRA = direction;
			break;
			
		case DIO_PORTB:
			DDRB = direction;
			break;
		
		case DIO_PORTC:
			DDRC = direction;
			break;
		
		case DIO_PORTD:
			DDRD = direction;
			break;
	
		default:
		break;
	}	
}


void DIO_SetPINDir(uint8 port, uint8 pin, uint8 direction)
{
	switch(direction)
	{
		case DIO_PIN_OUTPUT :
			switch(port)
			{
				case(DIO_PORTA):
					SET_BIT(DDRA,pin);
					break;
				
				case(DIO_PORTB):
					SET_BIT(DDRB,pin);
					break;
				
				case(DIO_PORTC):
					SET_BIT(DDRC,pin);
					break;
				
				case(DIO_PORTD):
					SET_BIT(DDRD,pin);
					break;
				
				default:
				break;
			}
			break;
		
		case(DIO_PIN_INPUT):
			switch(port)
			{
				case(DIO_PORTA):
					CLR_BIT(DDRA,pin);
					break;
			
				case(DIO_PORTB):
					CLR_BIT(DDRB,pin);
					break;
			
				case(DIO_PORTC):
					CLR_BIT(DDRC,pin);
					break;
				
				case(DIO_PORTD):
					CLR_BIT(DDRD,pin);
					break;
			
				default:
				break;
			}
			break;
			
			default:
			break;
	}
}

void DIO_SetPortValue(uint8 port, uint8 value)
{
	switch(port)
	{
		case (DIO_PORTA):
			PORTA=value;
			break;
		
		case (DIO_PORTB):
		PORTB=value;
		break;
		
		case (DIO_PORTC):
		PORTC=value;
		break;
		
		case (DIO_PORTD):
		PORTD=value;
		break;
		
		default:
		break;
	}
}

void DIO_SetPinValue(uint8 port, uint8 pin, uint8 value)
{
	switch(value)
	{
		case (DIO_PIN_HIGH):
		switch(port)
		{
			case DIO_PORTA:
				SET_BIT(PORTA,pin);
				break;
			
			case DIO_PORTB:
			SET_BIT(PORTB,pin);
			break;
			
			case DIO_PORTC:
			SET_BIT(PORTC,pin);
			break;
			
			case DIO_PORTD:
			SET_BIT(PORTD,pin);
			break;
			
			default:
			break;
		}
		break;
		
		case (DIO_PIN_LOW):
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(PORTA,pin);
			break;
			
			case DIO_PORTB:
			CLR_BIT(PORTB,pin);
			break;
			
			case DIO_PORTC:
			CLR_BIT(PORTC,pin);
			break;
			
			case DIO_PORTD:
			CLR_BIT(PORTD,pin);
			break;
			
			default:
			break;
		}	
		break;
		
		default:
		break;
	}
}

void DIO_ReadPinValue(uint8 port, uint8 pin, uint8 *recall_value)
{
	switch (port)
	{
		case DIO_PORTA:
			*recall_value = GET_BIT(PINA,pin);
			break;
			
		case DIO_PORTB:
		*recall_value = GET_BIT(PINB,pin);
		break;
		
		case DIO_PORTC:
		*recall_value = GET_BIT(PINC,pin);
		break;
		
		case DIO_PORTD:
		*recall_value = GET_BIT(PIND,pin);
		break;
			
		default:
		break;
	}
}
void DIO_ReadPortValue(uint8 port, uint8 *recall_value)
{
	switch (port)
	{
		case (DIO_PORTA):
			*recall_value = PINA;
			break;
			
		case (DIO_PORTB):
		*recall_value = PINB;
		break;
		
		case (DIO_PORTC):
		*recall_value = PINC;
		break;
		
		case (DIO_PORTD):
		*recall_value = PIND;
		break;	
		
		default:
		break;
	}
}

void DIO_TogglePin(uint8 port, uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA:
			Toggle_BIT(PORTA,pin);
			break;
			
		case DIO_PORTB:
		Toggle_BIT(PORTB,pin);
		break;
		
		case DIO_PORTC:
		Toggle_BIT(PORTC,pin);
		break;
		
		case DIO_PORTD:
		Toggle_BIT(PORTD,pin);
		break;
		
		default:
		break;	
	}
}
void DIO_TogglePort(uint8 port)
{
	switch(port)
	{
		case DIO_PORTA:
			PORTA ^= 0xff;
			break;
			
		case DIO_PORTB:
		PORTB ^= 0xff;
		break;
		
		case DIO_PORTC:
		PORTC ^= 0xff;
		break;
		
		case DIO_PORTD:
		PORTD ^= 0xff;
		break;
		
		default:
		break; 
	}
}


