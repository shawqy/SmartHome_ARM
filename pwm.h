


#ifndef PWM_H
#define PWM_H




/*Note: I already inlcuded the tm4c123gh6pm.h inside the micro_config.h
        No need to include it again*/
#include "micro_config.h"
#include "macros.h"
#include "std_types.h"



/*Enums*/

typedef enum
{

TIMER_0,
TIMER_1,
TIMER_2,
TIMER_3,
TIMER_4,
TIMER_5	

}PWM_TimerNumber;




typedef enum
{

	PWM,
	ONE_SHOT,
	REAL_TIME,
	INPUT_EDGE
	
}PWM_TimerMode;



typedef enum
{

  TIMER_A_DISABLED,
	TIMER_A_ENABLED
	

}PWM_TimerA;


typedef enum
{
  TIMER_B_DISABLED,
	TIMER_B_ENABLED

}PWM_TimerB;


typedef enum
{

	NON_INVERTED,
	INVERTED
	
}PWM_TimerInversion;



typedef enum
{
	
	CONCATENATE,NO_CONCATENATION=4
	
}PWM_TimerConcatenate;





/*Configuration Structure*/

typedef struct pwmconfig
{

	PWM_TimerNumber PWM_TN; /*To select one of the 16/32 Bit-timers*/
	
	PWM_TimerMode		PWM_TM;	/*To select the mode of the selected timer*/

	PWM_TimerInversion PWM_TI[2];	/*To adjust the inversion fro timerA and timerB inside the selected timer block*/
	
  PWM_TimerConcatenate PWM_TC;	/*To choose 16 or 32 bit timer operation*/

	PWM_TimerA		PWM_TA;	/*To enable/disable timerA*/
	
	PWM_TimerB		PWM_TB;	/*to enable/disable timerB*/
	
	uint32_t PWM_PreScalar[2];	/*to set the prescalar for Timer A and Timer B, and adjust the desired Timer Frequency*/
															/*In case in concatenation PreScalar[1] is ignored*/
	

}PWM_TimerConfigStruct;




/**Prototyopes**/



/*This function is used to set the settings of any timer module*/
/*Please note that this init function only sets the PWM settings*/
/*Inputs: Reference to the configure structure*/
void TIMER_init(const PWM_TimerConfigStruct *);


/*This function is used to map the ADC 12-Bit value to the right Duty Cycle value*/
/*Inputs: Any Value*/
void Timer_PWMOut(uint16_t);




#endif


