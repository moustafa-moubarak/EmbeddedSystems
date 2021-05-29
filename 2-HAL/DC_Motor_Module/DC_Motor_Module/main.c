/*
 * DC_Motor_Module.c
 *
 * Created: 5/27/2021 8:57:17 AM
 * Author : Moustafa Moubarak
 */ 


#include "DC_Motor.h"

int main(void)
{
    DC_Motor_Init();
	DC_Motor_Set_Dir(ANTI_CLOCK_WISE_DIR);
	DC_Motor_Set_Speed(100);
	DC_Motor_Start();
	
	Timer_Init(Timer1);
	/*DC_Motor_Toggle();*/
    while (1) 
    {
		Timer_SetDelay(Timer1,1000);
		Set_CallBack(Timer1,DC_Motor_Toggle);
		Timer_Start(Timer1);
    }
}

