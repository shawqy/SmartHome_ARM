
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

/* Send Byte From UART */
void UART_sendByte(UART_Number uNumber, const uint8_t jOneChar)
{

	// 0x00000020 --> TXFF :: Transmitter Full Bit number 5
	while (!(*((volatile uint32_t *)((USART_baseAddresses[uNumber] + UART_FLAG_R_OFFSET)))) & 0x00000020)
	{
	};

	(*((volatile uint32_t *)((USART_baseAddresses[uNumber] + UART_DATA_R_OFFSET)))) = jOneChar;
}

/* Send String From UART */
void UART_sendString(UART_Number uNumber, const uint8_t *jOneWord)
{
	for (int i = 0; jOneWord[i] != '\0'; i++)
	{
		UART_sendByte(uNumber, jOneWord[i]);
	}
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

	//enable system clk
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;

	//enable GPIO clk
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;

	//determine the the UART Number to know which TX and RX we will use
	uart_num = configure_pointer->UN;

	switch (uart_num)
	{
	case UART_0:
		GPIO_PORTA_AFSEL_R |= GPIO_PA10_M;
		GPIO_PORTA_DEN_R |= GPIO_PA10_M;
		GPIO_PORTA_PCTL_R |= 0x11;
		break;

	case UART_1:
		GPIO_PORTB_AFSEL_R |= GPIO_PB10_M;
		GPIO_PORTB_DEN_R |= GPIO_PB10_M;
		GPIO_PORTB_PCTL_R |= 0x11;
		break;

	case UART_2:
		GPIO_PORTD_AFSEL_R |= GPIO_PD76_M;
		GPIO_PORTD_DEN_R |= GPIO_PD76_M;
		GPIO_PORTD_PCTL_R |= 0x11;
		break;

	case UART_3:
		GPIO_PORTC_AFSEL_R |= GPIO_PC76_M;
		GPIO_PORTC_DEN_R |= GPIO_PC76_M;
		GPIO_PORTC_PCTL_R |= 0x11;
		break;

	case UART_4:
		GPIO_PORTC_AFSEL_R |= GPIO_PC54_M;
		GPIO_PORTC_DEN_R |= GPIO_PC54_M;
		GPIO_PORTC_PCTL_R |= 0x11;
		break;

	case UART_5:
		GPIO_PORTE_AFSEL_R |= GPIO_PE54_M;
		GPIO_PORTE_DEN_R |= GPIO_PE54_M;
		GPIO_PORTE_PCTL_R |= 0x11;
		break;

	case UART_6:
		GPIO_PORTD_AFSEL_R |= GPIO_PD54_M;
		GPIO_PORTD_DEN_R |= GPIO_PD54_M;
		GPIO_PORTD_PCTL_R |= 0x11;
		break;

	case UART_7:
		GPIO_PORTE_AFSEL_R |= GPIO_PE10_M;
		GPIO_PORTE_DEN_R |= GPIO_PE10_M;
		GPIO_PORTE_PCTL_R |= 0x11;
		break;
	}

	//disable the UART to set it
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CTL_R_OFFSET)))) = ~UART_CTL_UARTEN;

	//adjust the Baud Rate
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART0_IBRD_R_OFFSET)))) = 520;
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART0_FBRD_R_OFFSET)))) = 53;

	//adjust the UARTLCRH
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CRH_R_OFFSET)))) |= word_wdth;
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CRH_R_OFFSET)))) |= prt_sel;
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CRH_R_OFFSET)))) |= stp;
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CRH_R_OFFSET)))) |= prt_en;

	//enable the UART to set it
	(*((volatile uint32_t *)((USART_baseAddresses[uart_num] + UART_CTL_R_OFFSET)))) |= UART_CTL_UARTEN;
}
