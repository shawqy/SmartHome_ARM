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
	
	
	     /*UART0 Configure*/
		UART_ConfigureStruct UART0_Config; /*Set the proper Settings*/

			 /*UART1 Configure*/
		UART_ConfigureStruct UART1_Config; /*Set the proper Settings*/
		
			/*UART2 Configure*/
		UART_ConfigureStruct UART2_Config; /*Set the proper Settings*/


	
	
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
	
	
	
	
			 
			 /*Stepper Configure*/
		STEPPER_ConfigStructure STEPPER_Config;/*Set the proper Settings*/
	
	



	/*Initializations*/	
	

/*Enable Global Interrupts*/
	 __enable_irq();
		


/*Initialize ADC0*/	
ADC_init(&ADC0_Config);	
		

	
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




