/*
 * Temp_Sensor_HAL.c
 *
 * Created: 5/15/2021 11:25:29 AM
 *  Author: Moustafa Moubarak
 */ 
#include "Temp_Sensor_HAL.h"

void TempSensor_Intit(void)
{
	ADC_Init();
}

void TempSensor_Read(uint16* val)
{
	uint16 Digital_out = 0;
	uint32 Vin = 0;
	uint16 Temp = 0;
	
	ADC_Read(&Digital_out);
	
	//vin = digital out * step-size
	//Step-size = Vref/(2^resolution) 
	
	Vin = (Digital_out * 5000)/1024;
	
	//LM35 Temprature slope is 10mv/degree celsius
	Temp = Vin / 10;
	*val = Temp;
}