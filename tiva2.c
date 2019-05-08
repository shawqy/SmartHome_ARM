
#if 0
#include "adc.h"
#include "stepper.h"
#include "uart.h"
#include "LCD.h"
#include "PORT.h"
#include "DIO.h"
#include "pwm.h"



/* Tiva2 */
	
/*UART global Checkers*/
uint16_t g_callBackUART2;
	
/*UART Callback prototypes*/

/*UART2 CallBack */
void Tiva2_UART2callBack(void);



void SystemInit(){}
	
	

int main()
{
	
		/*Tiva LaunchPad 2 Configure*/
	
	     /*UART0 Configure*/
	UART_ConfigureStruct UART0_Config; /*Set the proper Settings*/
	
	
			 /*UART1 Configure*/
	UART_ConfigureStruct UART1_Config;/*Set the proper Settings*/
	
	
			/*UART2 Configure*/
	UART_ConfigureStruct UART2_Config;/*Set the proper Settings*/
	
	
	
	
	
	
			 /*ADC Configure Normal*/     
	
	/*Configure the Samples*/
	  /*We will only use Sample0 in Sequencer0*/
	static ADC_Sample Samples[2]={
		
		/*Samples[0]*/
	{
		0x00, /*Sample Number*/
		0x00,	 /*Analog Input Number (PE3) */
		0x01, /*The Last Sample*/
		SEQUENCER_0,
		NORMAL_SELECT,
		INTERRUPT_DISABLED
	},
	 /*Samples[1]*/
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
	
	
	
	

			 /*2 Push buttons Configure*/
	
	
	
			 /*LCD Configure*/
	
	
	
	
	

	
/*Initializations*/	
	
	/*Enable Global Interrupts*/
	 __enable_irq();
	
	
/*Initialize ADC0*/	
ADC_init(&ADC0_Config);	
	

/*Set UART2 CAll Back*/
UART_setReceiveCallBack(Tiva2_UART2callBack,UART_2);
	
	
	
	
	
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
		
		
	
	}
		
	
	return 0;
}	




/* Tiva2 */
	/*UART Callback Implementation*/
			/*UART2 CallBack */
void Tiva2_UART2callBack()
{
	g_callBackUART2++;
}

	#endif
