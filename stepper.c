#include "stepper.h"
static uint32_t Port_baseAddresse;
static STEPPER_Pins Pins[4];
static uint8_t steps[] = {0x9, 0x3, 0x6, 0xC};
static uint16_t nextStep = 0;

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

void STEPPER_clockWise(const uint8_t angle)
{
    //  Get the number of iterations needed to get the specified angle
    uint16_t noOfIterationsCeiled = (angle / (4 * StepAngle)) + 1;

    uint16_t iterationCount = 0;
    uint16_t j;
    while (iterationCount < noOfIterationsCeiled)
    {
        for (j = 0; j < 4; j++)
        {
            (*((volatile uint32_t *)((Port_baseAddresse + GPIO_PORT_DATA_R_OFFSET)))) = (steps[nextStep++ & 3] << Pins[0]);
        }
        iterationCount++;
    }
}
void STEPPER_counterClockWise(const uint8_t angle)
{
    //  Get the number of iterations needed to get the specified angle
    uint16_t noOfIterationsCeiled = (angle / (4 * StepAngle)) + 1;

    uint16_t iterationCount = 0;
    uint16_t j;
    while (iterationCount < noOfIterationsCeiled)
    {
        for (j = 0; j < 4; j++)
        {
            (*((volatile uint32_t *)((Port_baseAddresse + GPIO_PORT_DATA_R_OFFSET)))) = (steps[nextStep-- & 3] << Pins[0]);
        }
        iterationCount++;
    }
}
