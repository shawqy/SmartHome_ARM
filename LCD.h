#ifndef LCD_H_
#define LCD_H_


#include "micro_config.h"
#include "macros.h"
#include "std_types.h"


#define	CLEAR_DISPLAY_SCREEN    0x01
#define RETURN_CURSOR_HOME      0x02
#define DISPLAY_CURSOR_BLINKING 0x0F
#define FORCE_CURSOR_1ST_LINE 0x80
#define FORCE_CURSOR_2ND_LINE 0xC0

#define _8_BIT_MODE_1_LINES_5_X_7_DOTS		0x30
#define _8_BIT_MODE_2_LINES_5_X_7_DOTS		0x38
#define _4_BIT_MODE_1_LINES_5_X_7_DOTS		0x20
#define _4_BIT_MODE_2_LINES_5_X_7_DOTS		0x28

#define RS 0x20 
#define RW 0x40 
#define EN 0x80 

void LCD_init();
void LCD_sendCommand(uint8 command);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const uint8 *data);

void LCD_integerToString(int data);


//void LCD_clearScreen();

 
#endif
