
#include "uart.h"






/*This global array can only be accessed from this file*/
/*This array holds the different UARTs modules for the tm4c123gh6pm controller*/
/*All these addresses are pre-defined in the mic_config.h*/
static uint32_t USART_baseAddresses[]=
{

	UART0_R_BASE_ADDRESSE,
	UART1_R_BASE_ADDRESSE,
	UART2_R_BASE_ADDRESSE,
	UART3_R_BASE_ADDRESSE,	
	UART4_R_BASE_ADDRESSE,
	UART5_R_BASE_ADDRESSE,
	UART6_R_BASE_ADDRESSE,
	UART7_R_BASE_ADDRESSE

};