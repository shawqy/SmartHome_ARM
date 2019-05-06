
#include "uart.h"

/*This global array can only be accessed from this file*/
/*This array holds the different UARTs modules for the tm4c123gh6pm controller*/
/*All these addresses are pre-defined in the mic_config.h*/
static uint32_t USART_baseAddresses[] =
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
	
/*These pointers to function will used to call the interrupt user defined function inside the ISR*/
static void(*UART0_transCallBackPtr)(void)=NULL_PTR;
static void(*UART0_receiveCallBackPtr)(void)=NULL_PTR;
static void(*UART1_transCallBackPtr)(void)=NULL_PTR;
static void(*UART1_receiveCallBackPtr)(void)=NULL_PTR;






/*ISRs*/


void UART0_Handler()
{
		
	
	 /*Check if the interrupt signaled due to transmission*/
	 if(BIT_IS_SET(UART0_MIS_R,5))
		{
			/*Execute the trans call back function*/
				UART0_transCallBackPtr();
			
			/*Clear The Trans flag*/
			  SET_BIT(UART0_ICR_R,BIT_5);
		}
		
		
		
	 /*Check if the interrupt signaled due to reception*/
	 if(BIT_IS_SET(UART0_MIS_R,4))
		{
			/*Execute the trans call back function*/
				UART0_receiveCallBackPtr();

			/*Clear The Recep flag*/
			  SET_BIT(UART0_ICR_R,BIT_4);
		
		}



}



void UART1_Handler()
{
		
	
	 /*Check if the interrupt signaled due to transmission*/
	 if(BIT_IS_SET(UART1_MIS_R,5))
		{
			/*Execute the trans call back function*/
				UART1_transCallBackPtr();
			
			/*Clear The Trans flag*/
				/*Permission:W1C*/
					SET_BIT(UART1_ICR_R,BIT_5);
		}
		
		
		
	 /*Check if the interrupt signaled due to reception*/
	 if(BIT_IS_SET(UART1_MIS_R,4))
		{
			/*Execute the trans call back function*/
				UART1_receiveCallBackPtr();

			/*Clear The Recep flag*/
				/*Permission:W1C*/			
					SET_BIT(UART1_ICR_R,BIT_4);
		
		}

}




/*********************************************************************/
/*********************************************************************/





/* Send Byte From UART */
void UART_sendByte(UART_Number uNumber, const uint8_t jOneChar)
{

	// 0x00000020 --> TXFF :: Transmitter Full Bit number 5
	while (((*((volatile uint32_t *)((USART_baseAddresses[uNumber] + UART_FLAG_R_OFFSET)))) & 0x00000020)!= 0);
	

	(*((volatile uint32_t *)((USART_baseAddresses[uNumber] + UART_DATA_R_OFFSET)))) = jOneChar;
}

/* Send String From UART */
void UART_sendString(UART_Number uNumber, const uint8_t *jOneWord)
{
	int i;
	for ( i = 0; jOneWord[i] != '\0'; i++)
	{
		UART_sendByte(uNumber, jOneWord[i]);
	}
}

//recieve byte function
uint8_t UART_receiveByte(UART_Number uNumber){
			
	//checking for the RXFE (bit 4) int the FLAG REGISTER....if bit = 0 then not empty and 
	//we will start reading
	while(((*((volatile uint32_t *)(USART_baseAddresses[uNumber]+UART_FLAG_R_OFFSET)))& 0x00000010) != 0);
				
		return (*((volatile uint32_t *)(USART_baseAddresses[uNumber]+UART_DATA_R_OFFSET)));
}

//recieve string function
void UART_receiveString(UART_Number uNumber , uint8_t* Word){
	
	 int i = -1;
	 do{
		i++;
		Word[i] = UART_receiveByte(uNumber);	
	 
	 }while(Word[i] != '#');
	 
	 Word[i] = '\0';
	 
}


void UART_init(const UART_ConfigureStruct *configure_pointer)
{
	
	
	
	uint8_t uart_num, word_wdth, prt_sel, f_en, stp, prt_en;

	word_wdth = configure_pointer->UWL;
	word_wdth = (word_wdth << 5);

	prt_sel = configure_pointer->UPS;
	prt_sel = (prt_sel << 2);

	f_en = configure_pointer->UF;
	f_en = (f_en << 4);

	stp = configure_pointer->USB;
	stp = (stp << 3);

	prt_en = configure_pointer->UPE;
	prt_en = (prt_en << 1);
	
	
	
	
	
	
	
	/*
SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
	
	UART0_CTL_R &= ~UART_CTL_UARTEN;
	UART0_IBRD_R = 520;    
  UART0_FBRD_R = 53;
	UART0_LCRH_R = ( word_wdth | prt_sel | stp | prt_en| f_en);
	UART0_CTL_R |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);
	
	GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
	GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);
	GPIO_PORTA_DEN_R |= GPIO_PA10_M;*/
	
	
	
	
	
	
	
	
	

	//enable system clk
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;

	//enable GPIO clk
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;



	//determine the the UART Number to know which TX and RX we will use
	uart_num = configure_pointer->UN;



		//enable system clk
		SYSCTL_RCGCUART_R |= (1 << uart_num);


	//disable the UART to set it
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CTL_R_OFFSET)))) &= ~UART_CTL_UARTEN;

	//adjust the Baud Rate
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART0_IBRD_R_OFFSET)))) = 520;
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART0_FBRD_R_OFFSET)))) = 53;

	//adjust the UARTLCRH
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CRH_R_OFFSET)))) |= ( word_wdth | prt_sel | stp | prt_en| f_en);


	//adjuct UARTCC to internal clock
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CC_R_OFFSET)))) = 0;
	
	//enable the UART to set it
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CTL_R_OFFSET)))) |= (UART_CTL_RXE | UART_CTL_TXE | UART_CTL_UARTEN);









	switch (uart_num)
	{
	case UART_0:


		//enable GPIO clk
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
		GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
		GPIO_PORTA_PCTL_R |= (GPIO_PORTA_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PA1_U0TX | GPIO_PCTL_PA0_U0RX);;
		GPIO_PORTA_DEN_R |= GPIO_PA10_M;
		break;

	case UART_1:

		//enable GPIO clk
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;
		GPIO_PORTB_AFSEL_R |= GPIO_PB10_M;
		GPIO_PORTB_DEN_R |= GPIO_PB10_M;
		GPIO_PORTB_PCTL_R |= 0x11;
		break;

	case UART_2:

		//enable GPIO clk
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
		GPIO_PORTD_AFSEL_R |= GPIO_PD76_M;
		GPIO_PORTD_DEN_R |= GPIO_PD76_M;
		GPIO_PORTD_PCTL_R |= 0x11;
		break;

	case UART_3:
		//enable GPIO clk
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
		GPIO_PORTC_AFSEL_R |= GPIO_PC76_M;
		GPIO_PORTC_DEN_R |= GPIO_PC76_M;
		GPIO_PORTC_PCTL_R |= 0x11;
		break;

	case UART_4:

		//enable GPIO clk
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R2;
		GPIO_PORTC_AFSEL_R |= GPIO_PC54_M;
		GPIO_PORTC_DEN_R |= GPIO_PC54_M;
		GPIO_PORTC_PCTL_R |= 0x11;
		break;

	case UART_5:

		//enable GPIO clk
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
		GPIO_PORTE_AFSEL_R |= GPIO_PE54_M;
		GPIO_PORTE_DEN_R |= GPIO_PE54_M;
		GPIO_PORTE_PCTL_R |= 0x11;
		break;

	case UART_6:
	
		//enable GPIO clk
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
		GPIO_PORTD_AFSEL_R |= GPIO_PD54_M;
		GPIO_PORTD_DEN_R |= GPIO_PD54_M;
		GPIO_PORTD_PCTL_R |= 0x11;
		break;

	case UART_7:
	

		//enable GPIO clk
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
		GPIO_PORTE_AFSEL_R |= GPIO_PE10_M;
		GPIO_PORTE_DEN_R |= GPIO_PE10_M;
		GPIO_PORTE_PCTL_R |= 0x11;
		break;
	}

}




void UART_setTransmitCallBack(void(*callBack_ptr)(void),UART_Number UN)
{

if(UN)	UART1_transCallBackPtr=callBack_ptr;
else		UART0_transCallBackPtr=callBack_ptr;

}


void UART_setReceiveCallBack(void(*callBack_ptr)(void),UART_Number UN)
{
	
if(UN)	UART1_receiveCallBackPtr=callBack_ptr;
else    UART0_receiveCallBackPtr=callBack_ptr;

}
