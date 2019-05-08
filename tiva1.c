#if 0
#include "adc.h"
#include "stepper.h"
#include "uart.h"
#include "LCD.h"
#include "PORT.h"
#include "DIO.h"
#include "pwm.h"


	
	
/* Tiva1*/

/*UART global Checkers*/
uint16_t g_callBackUART0;	
uint16_t g_callBackUART1;	
	

/*UART Callback prototypes*/

/*UART0 CallBack */
void Tiva1_UART0callBack(void);

/*UART1 CallBack */
void Tiva1_UART1callBack(void);





void SystemInit(){}
	
	

int main()
{

		/*Tiva LaunchPad 1 Configure*/
	
	
	     /*UART0 Configure Receiving with interrupt (PWM LED) */ 
		UART_ConfigureStruct UART0_Config;
	
			 /*UART1 Configure Receiving with interrupt (STEPPER MOTOR) */
		UART_ConfigureStruct UART1_Config;

		/*UART2 Configure (No Interrupt) (INTERNAL TEMP SENSOR) */
		UART_ConfigureStruct UART2_Config;
	
	
	
	
	
	
			  /*ADC Configure Normal*/     
	
	/*Configure the Samples*/
	  /*We will only use Sample0 in Sequencer0*/
	static ADC_Sample Samples[2]={
		
		/*Sample[0]*/
	{
		0x00, /*Sample Number*/
		0x00,	 /*Analog Input Number (PE3) */
		0x01, /*The Last Sample*/
		SEQUENCER_0,
		TEMP_SENSOR, /*Read from the internal temp sensor*/
		INTERRUPT_DISABLED
	},
	
		/*Sample[1]*/
	{
	
		-1, /*Terminate The loop*/
   	0x02,	 
		0x01, 
		SEQUENCER_0,
		NORMAL_SELECT,
		INTERRUPT_DISABLED
	} 
};
	

	/*Set the proper Settings*/
	ADC_ConfigureStruct ADC0_Config=
	{
		Samples,
		ADC_0,
		0x00, /*Disable The 4 Sequencers Module Interrupts*/
	  0x01, /*Active Sequencer 0*/
		0x10, /*Enable The GPIO Clock For PORTE*/
	
	};
	
	
	
	
	
	/*PWM Led Configure*/
			
	/*NOTE: Connect the LED to PIN PB6*/
	
	/*Adjust the Prescalar*/
static	uint32_t PWM_PreScalar[2]={0x1,0x0};
	/*Determin the Output effect*/
static	PWM_TimerInversion PWM_TimerInversion[2]={INVERTED,INVERTED};
	
	PWM_TimerConfigStruct LED_PWMConfig=
	{
	TIMER_0, /*We will use Timer Block0*/
	PWM, /*PWM MODE*/
	PWM_TimerInversion,
  NO_CONCATENATION,/*16 Bit-Timer Mode*/
	TIMER_A_ENABLED, 
	TIMER_B_DISABLED,
	PWM_PreScalar
	};
	
	
	
		 
	
			 /*Stepper Configure*/
	/*Set the proper Settings*/
STEPPER_ConfigStructure STEPPER_Config=
	{
  0x02, /*PORT C*/
	GPIO_PORT_C_APB_BASE_ADDRESSE,
	{PIN_0,PIN_1,PIN_2,PIN_3}	/*PC0,PC1,PC2,PC3*/
	};
	
	
	
	
	
	



	/*Initializations*/	
	

/*Enable Global Interrupts*/
	 __enable_irq();
		

	

/*Initialize ADC0*/	
ADC_init(&ADC0_Config);	
		
/*Initialize PWM LED*/
TIMER_init(&LED_PWMConfig);


/*initialize STEPPER*/
STEPPER_init(&STEPPER_Config);


/*Set UART0 CAll Back*/
UART_setReceiveCallBack(Tiva1_UART0callBack,UART_0);

/*Set UART1 CAll Back*/
UART_setReceiveCallBack(Tiva1_UART1callBack,UART_1);
	
	
	
	
	while(1)
	{
	
		/*Tiva LaunchPad 1 code*/



		/*Check on the interrupt Value of UART0*/
		/*Receive via UART0*/
		/*PWM the led with the receive value*/	
		
		
		
		/*Check on the interrupt Value of UART1*/
		/*Receive via UART1*/
		/*Rotate the motor with the received direction*/
		
		
		
		/*Read Internal Temp Sensor via ADC*/
		/*Send via UART2*/
		
			
	}
	

	
	return 0;
}	




	
	
/* Tiva1 */
	/*UART Callback Implementation*/
			
			/*UART0 CallBack */
void Tiva1_UART0callBack(void)
{
	g_callBackUART0++;
}

			/*UART1 CallBack */

void Tiva1_UART1callBack(void)
{
	g_callBackUART1++;
}

#endif
