

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

	
	
	if(pwm_structPtr->PWM_TA)
	{
	
		/*Configure the direction to be output pin*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_DIRECTION_R_OFFSET)))|=(1<<Timer_PinNumber[0]);

				
		/*Configure the digital enable to be output pin*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_DEN_R_OFFSET)))|=(1<<Timer_PinNumber[0]);
		
		
		/*Configure the AFSEL*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_AFSEL_R_OFFSET)))|=(1<<Timer_PinNumber[0]);

		
		/*Configure the PCTCL*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_PCTL_R_OFFSET)))|=(7<<(Timer_PinNumber[0]*4));
		
	
	}
	
	
	
	if(pwm_structPtr->PWM_TB)
	{
	
		/*Configure the direction to be output pin*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_DIRECTION_R_OFFSET)))|=(1<<Timer_PinNumber[1]);

				
		/*Configure the digital enable to be output pin*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_DEN_R_OFFSET)))|=(1<<Timer_PinNumber[1]);
		
		
		/*Configure the AFSEL*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_AFSEL_R_OFFSET)))|=(1<<Timer_PinNumber[1]);

		
		/*Configure the PCTCL*/
		(*((volatile uint32_t *)(Port_BaseAdd+GPIO_PORT_PCTL_R_OFFSET)))|=(7<<(Timer_PinNumber[1]*4));
		
	
	
	}
	
	
	

	
	
	/*Disable Timer A and Timer B*/
	(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONTROL_OFFSET)))&=~(1<<0);
	
	
	
	/*Select 16/32 Bits */
	(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONFIGURATION_OFFSET)))|=(pwm_structPtr->PWM_TC);


	
	
	
	/*Select the PWM Mode*/
	
	if(pwm_structPtr->PWM_TA && (pwm_structPtr->PWM_TM == PWM) )
	{
		/*Select the PWM Mode for Timer A*/
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_MODE_OFFSET)))|=(1<<3)|(2<<0);
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_MODE_OFFSET)))&=~(1<<2);
	
	
	  /*Inverted/NonInverted*/
	  (*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONTROL_OFFSET)))|=(pwm_structPtr->PWM_TI[0]<<6);
		
		
		
	
		/*Timer A Prescalar*/
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_PRESCALAR_OFFSET )))=pwm_structPtr->PWM_PreScalar[0];
		
	
	
	
	
	/*Adjust The Duty Cycle*/
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_INTERVAL_LOAD_OFFSET)))=0xFFF; /*Max Load Value*/
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_MATCH_OFFSET)))= 0xFFA; /*Random Value */
	
		
		
		/*Renable Timer A */
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONTROL_OFFSET)))|=(1<<0);
		
		
	}
	
	
	if(pwm_structPtr->PWM_TB && (pwm_structPtr->PWM_TM == PWM))
	{

		/*Select the PWM Mode for Timer B*/	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_MODE_OFFSET)))|=(1<<3)|(2<<0);
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_MODE_OFFSET)))&=~(1<<2);
	
		
		
		/*Inverted/NonInverted*/
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONTROL_OFFSET)))|=(pwm_structPtr->PWM_TI[1]<<14);
	
		
		
			/*Timer B Prescalar*/
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_B_PRESCALAR_OFFSET )))=pwm_structPtr->PWM_PreScalar[1];
	
	
	
	/*Adjust The Duty Cycle*/
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_INTERVAL_LOAD_OFFSET)))=0xFFF; /*Max Load Value*/
	
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_MATCH_OFFSET)))= 0xFFA; 	/*Random Value*/
	
	
		/*Renable Timer B */
		(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_CONTROL_OFFSET)))|=(1<<8);

	
	}
	
	


}




void Timer_PWMOut(uint16_t ADC_value)
{

	uint16_t Duty_Cycle,Match_value;
	
	
	/*Make sure that the value is 12 bits only*/
	ADC_value&=(0xFFFF);
	
	
	/*Linearization of the ADC value with the Duty Cycle*/
	/* 0xFFF ===> 99% */
	/* 0x000 ===> 0%  */
	
	Duty_Cycle=(1000.0/4095.0)* ADC_value;
	
	/*Adjust the proper Load value to the corrsoponding Duty Cycle*/
	
	Match_value=(Duty_Cycle/1000.0) * 0xFFFF;
	
	
	/*Adjust only the Interval Load Register*/
(*((volatile uint32_t *)(Timer_BaseAdd+TIMER_GPTM_TIMER_A_MATCH_OFFSET)))=Match_value;
	
	
}









