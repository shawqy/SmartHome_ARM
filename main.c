#include "adc.h"
#include "stepper.h"
#include "uart.h"
#include "LCD.h"
#include "PORT.h"
#include "DIO.h"
#include "pwm.h"



void SystemInit(){}
	
	
/* Tiva2 */
	/*UART Callback prototypes*/
			/*UART2 CallBack */
	
/*uint16_t g_callBackUART2*/	
	


	
	
/* Tiva1 */
	/*UART Callback prototypes*/
			/*UART0 CallBack */
			/*UART1 CallBack */

/*uint16_t g_callBackUART0*/	
/*uint16_t g_callBackUART1*/	
	




int main()
{
	
		/*Tiva LaunchPad 2 Configure*/
	
	     /*UART0 Configure*/
			 /*UART1 Configure*/
			 /*UART2 Configure*/
				
			 /*ADC Configure Normal*/
			 
			 /*2 Push buttons Configure*/
	
			 /*LCD Configure*/
	
	
	
		/*Tiva LaunchPad 1 Configure*/
	
	
	     /*UART0 Configure*/
			 /*UART1 Configure*/
			 /*UART2 Configure*/
	
	
			 /*ADC Configure Temp Sensor*/
			 
			 /*Stepper Configure*/
	
	
	
	while(1)
	{
	
		/*Tiva LaunchPad 2 code*/
		
		/*Read Potentiometer via ADC*/
		/*Send via uart0*/
		
		
		
		/*Read Button1 and Check if High*/
		/*Send via uart1*/
		
		
		
		/*Read Button2 and Check if High*/
		/*Send via uart1*/
		
		
		
		/*Check on the interrupt Value of UART2*/
		/*Receive Via UART2*/
		/*Display the receit on LCD*/
		
		
		
		
		
		
		
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




/* Tiva2 */
	/*UART Callback Implementation*/
			/*UART2 CallBack */
	
	
	
/* Tiva1 */
	/*UART Callback Implementation*/
			/*UART0 CallBack */
			/*UART1 CallBack */







