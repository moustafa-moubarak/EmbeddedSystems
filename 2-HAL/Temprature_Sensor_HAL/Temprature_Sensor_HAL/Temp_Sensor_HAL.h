/*
 * Temp_Sensor_HAL.h
 *
 * Created: 5/15/2021 11:26:08 AM
 *  Author: Moustafa Moubarak
 */ 


#ifndef TEMP_SENSOR_HAL_H_
#define TEMP_SENSOR_HAL_H_

#include "ADC_MCAL.h"

void TempSensor_Intit(void);

void TempSensor_Read(uint16* val);


#endif /* TEMP_SENSOR_HAL_H_ */