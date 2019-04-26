
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


/* Send Byte From UART */
void UART_sendByte(UART_Number uNumber,const uint8_t jOneChar) {

	// 0x00000020 --> TXFF :: Trasnmitter Full Bit number 5 
	while(!(*((volatile uint32_t *)((USART_baseAddresses[uNumber]+UART_FLAG_R_OFFSET))))
	& 0x00000020){};

	(*((volatile uint32_t *)((USART_baseAddresses[uNumber]+UART_DATA_R_OFFSET)))) = jOneChar ;

}

/* Send String From UART */ 
void UART_sendString(UART_Number uNumber,const uint8_t* jOneWord) {
	for (int i = 0 ; jOneWord[i] != '\0' ; i++) {
		UART_sendByte(uNumber,jOneWord[i]);
	}
}
