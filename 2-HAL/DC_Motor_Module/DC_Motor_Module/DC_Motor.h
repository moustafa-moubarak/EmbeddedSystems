/*
 * DC_Motor.h
 *
 * Created: 5/27/2021 8:58:18 AM
 *  Author: Moustafa Moubarak
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Timer.h"
#include "DIO_MCAL.h"
#include "Timer_Config.h"

#define	DCMOTOR_ENA_PWM_Timer0	0
#define DCMOTOR_ENA_PWM_Timer1	1

#define DCMOTOR_ENA_IN1_PORTA	0
#define DCMOTOR_ENA_IN1_PORTB	1
#define DCMOTOR_ENA_IN1_PORTC	2
#define DCMOTOR_ENA_IN1_PORTD	3

#define DCMOTOR_ENA_IN1_PIN0	0
#define DCMOTOR_ENA_IN1_PIN1	1
#define DCMOTOR_ENA_IN1_PIN2	2
#define DCMOTOR_ENA_IN1_PIN3	3
#define DCMOTOR_ENA_IN1_PIN4	4
#define DCMOTOR_ENA_IN1_PIN5	5
#define DCMOTOR_ENA_IN1_PIN6	6
#define DCMOTOR_ENA_IN1_PIN7	7

#define DCMOTOR_ENA_IN2_PORTA	0
#define DCMOTOR_ENA_IN2_PORTB	1
#define DCMOTOR_ENA_IN2_PORTC	2
#define DCMOTOR_ENA_IN2_PORTD	3

#define DCMOTOR_ENA_IN2_PIN0	0
#define DCMOTOR_ENA_IN2_PIN1	1
#define DCMOTOR_ENA_IN2_PIN2	2
#define DCMOTOR_ENA_IN2_PIN3	3
#define DCMOTOR_ENA_IN2_PIN4	4
#define DCMOTOR_ENA_IN2_PIN5	5
#define DCMOTOR_ENA_IN2_PIN6	6
#define DCMOTOR_ENA_IN2_PIN7	7

typedef enum
{
	CLOCK_WISE_DIR,
	ANTI_CLOCK_WISE_DIR,
	}DC_Motor_Dir;

void DC_Motor_Init(void);

void DC_Motor_Start(void);

void DC_Motor_Stop(void);

void DC_Motor_Set_Speed(uint8 speed);

void DC_Motor_Set_Dir(DC_Motor_Dir dir);

void DC_Motor_Toggle (void);



#endif /* DC_MOTOR_H_ */