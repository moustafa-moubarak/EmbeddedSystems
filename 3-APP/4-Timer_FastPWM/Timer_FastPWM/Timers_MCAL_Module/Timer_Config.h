/*
 * Timer_Config.h
 *
 * Created: 5/17/2021 10:05:33 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define		TIMER0_WAVEFORM_GEN_Mode		FAST_PWM
#define		TIMER0_PRESCALER				TIMER0_NO_PRESCALLING
#define		PRESCALER_FACTOR_T0				0
#define		OVF_Ticks_T0					256
#define		Timer0_PWM_WaveType				Non_Inverted

#define		TIMER1_WAVEFORM_GEN_Mode		FAST_PWM
#define		TIMER1_PRESCALER				TIMER1_NO_PRESCALLING
#define		PRESCALER_FACTOR_T1				0
#define		OVF_Ticks_T1					256
#define		Timer1_PWM_WaveType				Non_Inverted



#endif /* TIMER_CONFIG_H_ */