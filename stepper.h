

#ifndef STEPPER_H
#define STEPPER_H




#include "micro_config.h"
#include "macros.h"
#include "std_types.h"


/*Enumerations*/


/*This enum is used in the configuration strucuture to choose the 4 Pins of the connected Port*/
typedef enum
{

PIN_0, /* 0 */
PIN_1, /* 1 */
PIN_2, /* 2 */
PIN_3, /* 3 */
PIN_4, /* 4 */
PIN_5, /* 5 */
PIN_6, /* 6 */
PIN_7  /* 7 */
	
}STEPPER_Pins;





/*Structure*/


/*Configuration Structure*/
typedef struct configstep
{

 uint32_t Port; /*The Port at which the STEPPER driver is connected to*/
	
 STEPPER_Pins Pins[4]; /*The 4 Pins Of The Port at which the STEPPER driver is connected to*/	
	

}STEPPER_ConfigStructure;



/*Prototypes*/


/*This function is used to set the GPIO settings for the STEPPER motor*/
/*Inputs: Reference to the configure structure*/
void STEPPER_init(const STEPPER_ConfigStructure * );


/*This function is used to reset the GPIO settings for the STEPPER motor*/
/*Not fully developed for now*/
void STEPPER_deinit(void);

/*This function is used to rotate the STEPPER motor with any degree in clock wise direction*/
/*Inputs: The desired degree*/
void STEPPER_clockWise(const uint8_t);



/*This function is used to rotate the STEPPER motor with any degree in counter clock wise direction*/
/*Inputs: The desired degree*/
void STEPPER_counterClockWise(const uint8_t);




#endif
