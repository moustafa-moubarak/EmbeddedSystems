/*
 * Timer_Config.h
 *
 * Created: 5/17/2021 10:05:33 PM
 *  Author: Moustafa Moubarak
 */ 


#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

#define		TIMER0_WAVEFORM_GEN_Mode		CTC
#define		TIMER0_PRESCALER				TIMER0_PRESCALER_1024
#define		PRESCALER_FACTOR_T0				1024
#define		OVF_Ticks_T0					256

#define		TIMER1_WAVEFORM_GEN_Mode		CTC
#define		TIMER1_PRESCALER				TIMER1_PRESCALER_256
#define		PRESCALER_FACTOR_T1				1024
#define		OVF_Ticks_T1					65536



#endif /* TIMER_CONFIG_H_ */