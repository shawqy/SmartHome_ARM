

#include "pwm.h"

static uint32_t Timer_BaseAdd;

static uint32_t Timer_BaseAddresse[]=
{

TIMER0_R_BASE_ADDRESSE ,
TIMER1_R_BASE_ADDRESSE ,
TIMER2_R_BASE_ADDRESSE ,
TIMER3_R_BASE_ADDRESSE ,
TIMER4_R_BASE_ADDRESSE ,
TIMER5_R_BASE_ADDRESSE ,

};




void TIMER_init(const PWM_TimerConfigStruct * pwm_structPtr)
{
			uint32_t Port_BaseAdd,Port_number;
			uint8_t  Timer_PinNumber[2];		
	
		/****GPIO*****/
	
	/*Get the GPIO port base addresse and the two PWM pins*/
	switch(pwm_structPtr->PWM_TN)
	{
	
		case 0 :					

						Port_BaseAdd=GPIO_PORT_B_APB_BASE_ADDRESSE;
						Port_number=1;
						Timer_PinNumber[0]=6;
						Timer_PinNumber[1]=7;
							break;
		
	case 1 :					

						Port_BaseAdd=GPIO_PORT_B_APB_BASE_ADDRESSE;
						Port_number=1;
						Timer_PinNumber[0]=4;
						Timer_PinNumber[1]=5;
							break;
		
	case 2 :					

						Port_BaseAdd=GPIO_PORT_B_APB_BASE_ADDRESSE;
						Port_number=1;
						Timer_PinNumber[0]=0;
						Timer_PinNumber[1]=1;
							break;
		
	case 3 :					

						Port_BaseAdd=GPIO_PORT_B_APB_BASE_ADDRESSE;
						Port_number=1;
						Timer_PinNumber[0]=2;
						Timer_PinNumber[1]=3;
							break;
		
	case 4 :					

						Port_BaseAdd=GPIO_PORT_C_APB_BASE_ADDRESSE;
						Port_number=2;
						Timer_PinNumber[0]=0;
						Timer_PinNumber[1]=1;
							break;
		
	case 5 :					

						Port_BaseAdd=GPIO_PORT_C_APB_BASE_ADDRESSE;
						Port_number=2;
						Timer_PinNumber[0]=2;
						Timer_PinNumber[1]=3;
							break;
		
	}
	
	
	
		/*Enable Clock for the GPIO Port*/
			SYSCTL_RCGCGPIO_R |=(1<<Port_number);
	

	
		/*Enable clock for the timer module*/
	
		SET_BIT(SYSCTL_RCGCTIMER_R,pwm_structPtr->PWM_TN);
	
		/*Calculate the Timer base address*/
		 Timer_BaseAdd=Timer_BaseAddresse[pwm_structPtr->PWM_TN];

	
	
	/*Disable Timer A and Timer B*/
	(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONTROL_OFFSET)))&=~(1<<0)&~(1<<8);
	
	
	
	/*Select 16/32 Bits */
	(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONFIGURATION_OFFSET)))|=(pwm_structPtr->PWM_TC);


	
	
	
	/*Select the PWM Mode*/
	
	if(pwm_structPtr->PWM_TA && (pwm_structPtr->PWM_TM == PWM) )
	{
	
		/*Configure the direction to be output pin*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_DIRECTION_R_OFFSET)))|=(1<<Timer_PinNumber[0]);

				
		/*Configure the AFSEL*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_AFSEL_R_OFFSET)))|=(1<<Timer_PinNumber[0]);

		
		/*Configure the PCTCL*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_PCTL_R_OFFSET)))|=(7<<Timer_PinNumber[0]);
		
		
		
		/*Select the PWM Mode for Timer A*/
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_MODE_OFFSET)))|=(1<<3)|(1<<0);
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_MODE_OFFSET)))&=~(1<<2)|(1<<1);
	
	
	
	/*Adjust The Duty Cycle*/
	/*Initial 99%*/
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_INTERVAL_LOAD_OFFSET)))=0xBEA0; /*48800*/
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_MATCH_OFFSET)))= 0x1E8; /*488*/
	
		
		
		
	}
	
	
	if(pwm_structPtr->PWM_TB && (pwm_structPtr->PWM_TM == PWM))
	{

		
		/*Configure the direction to be output pin*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_DIRECTION_R_OFFSET)))|=(1<<Timer_PinNumber[1]);

				
		/*Configure the AFSEL*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_AFSEL_R_OFFSET)))|=(1<<Timer_PinNumber[1]);

		
		/*Configure the PCTCL*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_PCTL_R_OFFSET)))|=(7<<Timer_PinNumber[1]);
		
		
	
		/*Select the PWM Mode for Timer B*/	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_MODE_OFFSET)))|=(1<<3)|(1<<0);
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_MODE_OFFSET)))&=~(1<<2)|(1<<1);
	
	
	/*Adjust The Duty Cycle*/
	/*Initial 66%*/
	
	(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_INTERVAL_LOAD_OFFSET)))=0xBEA0; /*48800*/
	
	
	(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_MATCH_OFFSET)))= 0x1E8; /*488*/
	
	
	
	}
	
	
	
	
	
	
	
/*Inverted/NonInverted*/
(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_MODE_OFFSET)))|=(pwm_structPtr->PWM_TI[0]<<6)|(pwm_structPtr->PWM_TI[1]<<14);
	

	
	
	
/*Adjust the PreScalar*/
	
	if(pwm_structPtr->PWM_TC == CONCATENATE)
	{
	
		/*Set only one timer and it will impacts on the second*/ 
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_PRESCALAR_OFFSET )))=pwm_structPtr->PWM_PreScalar[0];

	
	}
	else
	{
	
		/*Timer A Prescalar*/
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_PRESCALAR_OFFSET )))=pwm_structPtr->PWM_PreScalar[0];
		
		
		/*Timer B Prescalar*/
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_PRESCALAR_OFFSET )))=pwm_structPtr->PWM_PreScalar[1];
	
	}
	
	
	
	
	
		/*Renable Timer A / Timer B*/
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONTROL_OFFSET)))|=(1<<0)|(1<<8);



}

