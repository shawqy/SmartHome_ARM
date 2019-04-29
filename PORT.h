#ifndef PORT_H
#define PORT_H

#include "micro_config.h"
#include "macros.h"
#include "std_types.h"


typedef enum
{

PORT_PIN_IN,PORT_PIN_OUT


}Port_PinDirectionType;


// uint8 one byte usingned integer

void Port_Init( Port port_index);
/*Initialize port based on selected port_index (0 to
5) by enabling the clock, unlocking the port, and
making the selected mode digital*/

void Port_SetPinDirection(Port port_index, uint8 pins_mask , Port_PinDirectionType I_O );
/*Change the direction of the selected pins by
pins_mask in the port selected by port_index
I_O indecated if the pin is input or output 1 for output
0 for input **Not so sure check datasheet :"D*/

void Port_SetPinPullUp(Port port_index, uint8 pins_mask, uint8 enable);
/*If enable is 1, the selected pins by pins_mask in
the port selected by port_index will be
connected to internal pull-up resistor.
If enable is 0, the selected pins by pins_mask in
the port selected by port_index will be not be
connected to internal pull-up resistor.*/

void Port_SetPinPullDown(Port port_index, uint8 pins_mask, uint8 enable);
/*zae ele fo2 bs pull down bdl pull up !*/


#endif
