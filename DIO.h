#ifndef DIO_H
#define DIO_H


#include "micro_config.h"
#include "macros.h"
#include "std_types.h"
#include "PORT.h"



typedef enum
{

STD_LOW,STD_HIGH


}DIO_LevelType;





uint8 DIO_ReadPort(Port port_index , uint8 pins_mask);
/*Return the value of the pins selected by
pins_masks in the port selected by port_index*/

void DIO_WritePort(Port port_index , uint8 pins_mask, DIO_LevelType pin_level);
/*change the value of the pins selected by pins_masks
in the port selected by port_index to input pins_level*/

void DIO_FlipPort (Port port_index, uint8 pins_mask);
/*Toggle the values of the pins selected by pin_masks
in the port selected by port_index*/

#endif
