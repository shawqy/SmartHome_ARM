
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

	// 0x00000020 --> TXFF :: Transmitter Full Bit number 5 
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
uint8_t UART_receiveByte(UART_Number uNumber){
			
	//checking for the RXFE (bit 4) int the FLAG REGISTER....if bit = 0 then not empty and 
	//we will start reading
	while(((*((volatile uint32_t *)(USART_baseAddresses[uNumber]+UART_FLAG_R_OFFSET)))
	& 0x00000010) != 0){};
				
		return (*((volatile uint32_t *)((USART_baseAddresses[uNumber]+UART_DATA_R_OFFSET))));
}

void UART_receiveString(UART_Number uNumber , uint8_t* Word){
	
	 int i = -1;
	 do{
			i++;
			Word[i] = UART_receiveByte(uNumber);	
	 
	 }while(Word[i] != '#');
	 
	 Word[i] = '/0';
	 
}
