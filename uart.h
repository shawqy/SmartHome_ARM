#ifndef    UART_H
#define    UART_H


/*Note: I already inlcuded the tm4c123gh6pm.h inside the micro_config.h
        No need to include it again*/
#include "micro_config.h"
#include "macros.h"
#include "std_types.h"




/*Enumerations Which are used in the Configure Structure*/
typedef enum
{
	
	UART_0,UART_1,UART_2,UART_3,UART_4,UART_5,UART_6,UART_7
	
}UART_Number;

typedef enum
{

  BIT_5_,BIT_6_,BIT_7_,BIT_8_
	
}UART_WordLength;

typedef enum
{

	FIFO_DISABLED,FIFO_ENABLED

}UART_FIFO;



typedef enum
{

	BIT_1_,BIT_2_

}UART_StopBit;


typedef enum
{
 
	PARITY_DISABLED,PARITY_ENABLED

}UART_ParityEnable;

typedef enum
{
 
	ODD_PARITY,EVEN_PARITY

}UART_ParitySelect;




typedef enum
{

	NO_INTERRUPT,INTERRUPT

}UART_InterruptSelect;





/* Configuration Structures */

/*This structure should be configured by the Driver user to initiate the various UART modules
  With any required settings */
typedef struct configure
{
	
	UART_Number          UN;
	UART_WordLength      UWL;
	UART_ParityEnable    UPE;
	UART_InterruptSelect UIS;
	UART_ParitySelect    UPS;
	UART_StopBit         USB;
	UART_FIFO            UF;
	
}UART_ConfigureStruct;




/*Function Prototypes*/

/*This function initializes the UART module ( GPIO / UART Registers ) */
/*Inputs: Reference to the ConfigureStruct which contains all the required settings to be set*/
void UART_init(const UART_ConfigureStruct*);


/*This function is not full developed untill now*/
void UART_deinit(void);


/*This function sends only one byte of data(Word Length)*/
/*Inputs: The UART number module to be sent from
          The 8-bits word to be sen                     */
void UART_sendByte(UART_Number,const uint8_t);


/*This function receives only one byte of data(Word Length)*/
/*Inputs: The UART number module to receive on*/
/*Return: The 8-bit(one byte) data received*/
uint8_t UART_receiveByte(UART_Number);


/*This function sends any string of any length*/
/*Inputs: The UART number module to be sent from
					Reference to the string(Array of character of 8-bit data each) which contains the data*/
void UART_sendString(UART_Number,const uint8_t*);


/*This function sends any string of any length*/
/*Inputs: The UART number module to receive on 
					Reference to the string(Array of character of 8-bit data each) Which will hold the received data*/
void UART_receiveString(UART_Number,uint8_t*);


#endif
