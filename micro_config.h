/*
 * 		Module:  Micro Config
 *
 *		File Name: micro_config.h
 *
 *		Disc: --------
 *
 * 	    Created on: ------
 *
 *      Author: Samir Mossad Ibrahim
 */

#ifndef MICRO_CONFIG_H
#define MICRO_CONFIG_H

#include "tm4c123gh6pm.h"

#define UNLOCK_32_BIT_VALUE 0X4C4F434B

/*GPIO*/
#define GPIO_PORT_A_APB_BASE_ADDRESSE (0x40004000)
#define GPIO_PORT_B_APB_BASE_ADDRESSE (0x40005000)
#define GPIO_PORT_C_APB_BASE_ADDRESSE (0x40006000)
#define GPIO_PORT_D_APB_BASE_ADDRESSE (0x40007000)
#define GPIO_PORT_E_APB_BASE_ADDRESSE (0x40024000)
#define GPIO_PORT_F_APB_BASE_ADDRESSE (0x40025000)

#define GPIO_PORT_DIRECTION_R_OFFSET (0x00000400)
#define GPIO_PORT_DEN_R_OFFSET (0x0000051C)
#define GPIO_PORT_AFSEL_R_OFFSET (0x00000420)
#define GPIO_PORT_AMSEL_R_OFFSET (0x00000528)
#define GPIO_PORT_PCTL_R_OFFSET (0x0000052C)
#define GPIO_PORT_LOCK_R_OFFSET (0x00000520)
#define GPIO_PORT_CR_R_OFFSET (0x00000524)
#define GPIO_PORT_PUR_R_OFFSET (0x00000510)
#define GPIO_PORT_PDR_R_OFFSET (0x00000514)
#define GPIO_PORT_DATA_R_OFFSET (0x00000000)

/*UART*/

#define UART0_R_BASE_ADDRESSE (0x4000C000)
#define UART1_R_BASE_ADDRESSE (0x4000D000)
#define UART2_R_BASE_ADDRESSE (0x4000E000)
#define UART3_R_BASE_ADDRESSE (0x4000F000)
#define UART4_R_BASE_ADDRESSE (0x40010000)
#define UART5_R_BASE_ADDRESSE (0x40011000)
#define UART6_R_BASE_ADDRESSE (0x40012000)
#define UART7_R_BASE_ADDRESSE (0x40013000)

#define UART_DATA_R_OFFSET (0x00000000)
#define UART_FLAG_R_OFFSET (0x00000018)
#define UART_CTL_R_OFFSET (0x00000030)
#define UART_CRH_R_OFFSET (0x0000002C)
#define UART_UARTIM_R_OFFSET (0x00000038)
#define UART0_IBRD_R_OFFSET (0x00000024)
#define UART0_FBRD_R_OFFSET (0x00000028)
#define UART_CC_R_OFFSET 	(0x00000FC8)

#define GPIO_PA10_M (0x03) //UART0
#define GPIO_PB10_M (0x03) //UART1
#define GPIO_PD76_M (0xC0) //UART2
#define GPIO_PC76_M (0xC0) //UART3
#define GPIO_PC54_M (0x30) //UART4
#define GPIO_PE54_M (0x30) //UART5
#define GPIO_PD54_M (0x30) //UART6
#define GPIO_PE10_M (0x03) //UART7

/*ADC*/

#define ADC0_R_BASE_ADDRESSE (0x40038000)
#define ADC1_R_BASE_ADDRESSE (0x40039000)

#define ADC_R_Active_Sequencer_OFFSET (0x00000000)
#define ADC_R_Event_Multiplexer_Select_OFFSET (0x00000014)
#define ADC_Sample_Sequencer0_Control_R_OFFSET (0x00000044)
#define ADC_Sample_Sequencer1_Control_R_OFFSET (0x00000064)
#define ADC_Sample_Sequencer2_Control_R_OFFSET (0x00000084)
#define ADC_Sample_Sequencer3_Control_R_OFFSET (0x000000A4)
#define ADC_Sample_Sequencer0_Mux_Select_R_OFFSET (0x00000040)
#define ADC_Sample_Sequencer1_Mux_Select_R_OFFSET (0x00000060)
#define ADC_Sample_Sequencer2_Mux_Select_R_OFFSET (0x00000080)
#define ADC_Sample_Sequencer3_Mux_Select_R_OFFSET (0x000000A0)
#define ADC_Interrupt_Mask_R_OFFSET (0x00000008)
#define ADC_PSSI_OFFSET (0x00000014)
#define ADC_RIS_OFFSET (0x00000004)
#define ADC_SSFIFO0_OFFSET (0x00000048)
#define ADC_ISC_OFFSET (0x0000000C)




/*  Stepper motor */

#define StepAngle 1.7 //this value depends on the motor it self

typedef enum
{

    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F

} Port;

#endif
