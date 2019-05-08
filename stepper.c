#include "stepper.h"
#include "systick.h" 
//for systick use 

static uint32_t Port_baseAddresse;
static STEPPER_Pins *Pins;
static uint8_t steps[] = {0x9, 0x3, 0x6, 0xC};
static uint16_t nextStep = 0;
static uint32_t required_delay = 20;
//the required delay will be determined while implementing

/* assume that we will use 4-step sequence 
	no.step		winding A 	winding B 	winding C		winding D
	
	1						1						0						0						1
	
	2						1						1						0						0
	
	3						0						1						1						0
	
	4						0						0						1						1
	
	4 steps * Step angle * no.of iteration needed = angle required
	
	ex: if we want to turn the rotor 80 degree and step angle = 2 degree per step
	
	so, 	4*2*	no of iterations needed = 80  ,  Therefor no of iterations needed = 10
*/



void STEPPER_init(STEPPER_ConfigStructure *  configStruct_ptr)
{
  /*Set the settings to be global*/
  Port_baseAddresse=configStruct_ptr->Port;
	Pins=configStruct_ptr->Pins; /*This will discard the Qualifier of Constant Structure*/
	
	/*Enable Port Clock*/
	 SET_BIT(SYSCTL_RCGCGPIO_R,configStruct_ptr->Port_Number);

	/*Wait for the ready flag to be able to access the Port*/
	 while(BIT_IS_CLEAR(SYSCTL_PRGPIO_R,configStruct_ptr->Port_Number));         
	
	/*Unlock The Port*/
	(*((volatile uint32_t*)(Port_baseAddresse+GPIO_PORT_LOCK_R_OFFSET)))=UNLOCK_32_BIT_VALUE;
	
	
	/*Adjust the Direction*/
	(*((volatile uint32_t*)(Port_baseAddresse+GPIO_PORT_DIRECTION_R_OFFSET)))|=(1<<Pins[0])|(1<<Pins[1])|(1<<Pins[2])|(1<<Pins[3]);
	
	/*Enable The Digital Functionality*/
	(*((volatile uint32_t*)(Port_baseAddresse+GPIO_PORT_DEN_R_OFFSET)))|=(1<<Pins[0])|(1<<Pins[1])|(1<<Pins[2])|(1<<Pins[3]);
	
	
	/*Turn off the Analog Mode*/
	(*((volatile uint32_t*)(Port_baseAddresse+GPIO_PORT_AMSEL_R_OFFSET)))&=~(1<<Pins[0])&~(1<<Pins[1])&~(1<<Pins[2])&~(1<<Pins[3]);
	
  /*Disable The Alternative Function*/
	(*((volatile uint32_t*)(Port_baseAddresse+GPIO_PORT_AFSEL_R_OFFSET)))&=~(1<<Pins[0])&~(1<<Pins[1])&~(1<<Pins[2])&~(1<<Pins[3]);
	
	
	/*Set the Output pins to zero to protect the connected driver*/
	(*((volatile uint32_t*)(Port_baseAddresse+GPIO_PORT_DATA_R_OFFSET)))&=~(1<<Pins[0])&~(1<<Pins[1])&~(1<<Pins[2])&~(1<<Pins[3]);

}

void STEPPER_clockWise(const uint8_t angle)
{
    //  Get the number of iterations needed to get the specified angle
    uint16_t noOfIterationsCeiled = (angle / (4 * StepAngle)) + 1;

    uint16_t j;
    while (noOfIterationsCeiled--)
    {
        for (j = 0; j < 4; j++)
        {
            (*((volatile uint32_t *)((Port_baseAddresse + GPIO_PORT_DATA_R_OFFSET)))) = (steps[nextStep++ & 3] << Pins[0]);
					//delay between steps; kind of tolerance for coils energizing
						SYSTICK_delay(required_delay);
        }
				
    }
}





void STEPPER_counterClockWise(const uint8_t angle)
{
    //  Get the number of iterations needed to get the specified angle
    uint16_t noOfIterationsCeiled = (angle / (4 * StepAngle)) + 1;

    uint16_t j;
    while (noOfIterationsCeiled--)
    {
        for (j = 0; j < 4; j++)
        {
            (*((volatile uint32_t *)((Port_baseAddresse + GPIO_PORT_DATA_R_OFFSET)))) = (steps[nextStep-- & 3] << Pins[0]);
						//same delay 
						SYSTICK_delay(required_delay);
				}
				
       
    }
}
