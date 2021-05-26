/*
 * ADC_MCAL.h
 *
 * Created: 5/3/2021 10:42:04 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef ADC_MCAL_H_
#define ADC_MCAL_H_

#include "MCU.h"
#include "BIT_Math.h"
#include "ADC_config_MCAL.h"

#define ADC_VREF_AVCC			0
#define ADC_VREF_AREF			1
#define ADC_VREF_INTERNAL		2	

#define ADC_LEFT_ADJUST			0
#define ADC_RIGHT_ADJUST		1

#define ADC_CHANNEL_0			0
#define ADC_CHANNEL_1			1
#define ADC_CHANNEL_2			2
#define ADC_CHANNEL_3			3
#define ADC_CHANNEL_4			4
#define ADC_CHANNEL_5			5
#define ADC_CHANNEL_6			6
#define ADC_CHANNEL_7			7

#define ADC_AUTO_TRIGGER		1

#define ADC_PRESCALER_CLK		0
#define ADC_PRESCALER_2			1
#define ADC_PRESCALER_4			2
#define ADC_PRESCALER_8			3
#define ADC_PRESCALER_16		4
#define ADC_PRESCALER_32		5
#define ADC_PRESCALER_64		6
#define ADC_PRESCALER_128		7


#define ADC_INERRUPT_DISABLE	0
#define ADC_INERRUPT_ENABLE		1

//Functions
void ADC_Init(void);

void ADC_Read(uint16* value);




#endif /* ADC_MCAL_H_ */