#include "LCD.h"
#include "PORT.h"
#include "DIO.h"
#include "systick.h"

char numbers [10]={'0','1','2','3','4','5','6','7','8','9'};


void LCD_init(){

    Port_Init(PORT_A); // Control
    Port_Init(PORT_B); // DATA

    Port_SetPinDirection(PORT_B,0xFF,PORT_PIN_OUT);
    Port_SetPinDirection(PORT_A,0xE0,PORT_PIN_OUT);

    SYSTICK_delay(10);

    LCD_sendCommand(_8_BIT_MODE_1_LINES_5_X_7_DOTS);

    SYSTICK_delay(5);

    LCD_sendCommand(_8_BIT_MODE_1_LINES_5_X_7_DOTS);

    SYSTICK_delay(100);

    LCD_sendCommand(_8_BIT_MODE_1_LINES_5_X_7_DOTS);

    LCD_sendCommand(_8_BIT_MODE_2_LINES_5_X_7_DOTS);
    LCD_sendCommand(RETURN_CURSOR_HOME);
    LCD_sendCommand(CLEAR_DISPLAY_SCREEN);
    LCD_sendCommand(DISPLAY_CURSOR_BLINKING);

}
void LCD_sendCommand(uint8 command){
    
    DIO_WritePort(PORT_A,0xFF,STD_LOW);
    DIO_WritePort(PORT_B,0xFF,STD_LOW);
    
    SYSTICK_delay(1);

    DIO_WritePort(PORT_B,0XFF,STD_LOW);

    SYSTICK_delay(1);
    
    DIO_WritePort(PORT_B,command,STD_HIGH);
    DIO_WritePort(PORT_A,EN,STD_HIGH);
    
    SYSTICK_delay(10);
 
    
}
void LCD_displayCharacter(uint8 data){
    
    GPIO_PORTA_DATA_R = RS; /* RS = 1, R/W = 0 */
GPIO_PORTB_DATA_R = data;
GPIO_PORTA_DATA_R = EN | RS; /* pulse E */
	SYSTICK_delay(10);
	GPIO_PORTA_DATA_R = 0;
	SYSTICK_delay(40);


}
void LCD_integerToString(int data){

    int data1,data2,data3;
    //uint8 dummy;
		data1 = (data%1000)/100;
  	data2 = (data%100)/10;
	  data3 = (data%10);
  	//itoa(data,buffer,10);

	LCD_displayCharacter(numbers[data1]);
	SYSTICK_delay(10);
	LCD_displayCharacter(numbers[data2]);
	SYSTICK_delay(10);
	LCD_displayCharacter(numbers[data3]);
}
void LCD_displayString(const uint8 *data){

   
	while(*(data)!='\0')
	{
      
        SYSTICK_delay(10);

		LCD_displayCharacter(*(data));

		data++;

	}

}
