

#if 0
#include "adc.h"
#include "stepper.h"
#include "uart.h"
#include "LCD.h"
#include "PORT.h"
#include "DIO.h"
#include "pwm.h"
#include "systick.h"


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
	
	 /*UART0 Configure (No Interrupt) (POTENTIOMETER) */
		UART_ConfigureStruct UART0_Config=
			{
		UART_0,
		BIT_8_, /*8-BITS WordLength*/
		PARITY_DISABLED, 
		NO_INTERRUPT,
		ODD_PARITY, /*No effect*/
		BIT_1_, /*1 Stop Bit*/
		FIFO_ENABLED	
			};
	
			 /*UART1 Configure (No Interrupt) (2-PUSH BUTTONS) */
		UART_ConfigureStruct UART1_Config=
			{
		UART_1,
		BIT_8_, /*8-BITS WordLength*/
		PARITY_DISABLED, 
		NO_INTERRUPT,
		ODD_PARITY, /*No effect*/
		BIT_1_, /*1 Stop Bit*/
		FIFO_ENABLED	
			}; 

		/*UART2 Configure Receiving with interrupt (LCD)*/
		UART_ConfigureStruct UART2_Config=
			{	
		UART_2,
		BIT_8_, /*8-BITS WordLength*/
		PARITY_DISABLED, 
		INTERRUPT,
		ODD_PARITY, /*No effect*/
		BIT_1_, /*1 Stop Bit*/
		FIFO_ENABLED		
			}; 
	
	
	
	

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
	
	
	
	

					
	
/*LCD Configure*/
LCD_init();	
	
	
	
	

	
/*Initializations*/	
	
	/*Enable Global Interrupts*/
	 __enable_irq();
	


/*2 Push buttons Configure (PF0,PF4) */
Port_Init(PORT_F);		
Port_SetPinDirection(PORT_F,0x11,PORT_PIN_IN);
Port_SetPinPullUp(PORT_F,0x11,0x01);
	
	
/*Initialize ADC0*/	
ADC_init(&ADC0_Config);	
	

/*Initialize UART0*/
UART_init(&UART0_Config);

/*Initialize UART1*/
UART_init(&UART1_Config);

/*Initialize UART2*/
UART_init(&UART2_Config);

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