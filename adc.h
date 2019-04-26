

#ifndef ADC_H
#define ADC_H

#include "micro_config.h"
#include "macros.h"
#include "std_types.h"



/*This defines to select the trigger source for each Sample Sequencer for each ADC
  Please note that if the sequencer is not activated ,there will be no affect for these triggers*/
#define ADC0_SAMPLE_SEQUNECER0_SOURCE_SELECT     0xFF
#define ADC0_SAMPLE_SEQUNECER1_SOURCE_SELECT		 0xFF
#define ADC0_SAMPLE_SEQUNECER2_SOURCE_SELECT     0xFF 
#define ADC0_SAMPLE_SEQUNECER3_SOURCE_SELECT     0xFF 

#define ADC1_SAMPLE_SEQUNECER0_SOURCE_SELECT     0xFF
#define ADC1_SAMPLE_SEQUNECER1_SOURCE_SELECT		 0xFF
#define ADC1_SAMPLE_SEQUNECER2_SOURCE_SELECT     0xFF 
#define ADC1_SAMPLE_SEQUNECER3_SOURCE_SELECT     0xFF 




/*Enumerations*/

typedef enum
{

ADC_0,ADC_1

}ADC_Number;



typedef enum
{

INTERRUPT_ENABLED,INTERRUPT_DISABLED

}ADC_InterruptSelect;



/* To choose the last sample in a sequence of conversion 
   Also it sets the raw interrupt flag after this chosen Sample
   ,The masked interrutp flag will be set if INTERRUPT_ENABLED 
   is selected from the previous enum*/
typedef enum
{

	SAMPLE_1,
	SAMPLE_2,
	SAMPLE_3,
	SAMPLE_4,
	SAMPLE_5,
	SAMPLE_6,
	SAMPLE_7,
	SAMPLE_8
	
}ADC_EndOfConversion;



/*This decides for each Sample in a sequence wether it reads from the internal temp sensor
  or from the selected analog input */
typedef enum
{

TEMP_SENSOR,NORMAL_SELECT

}ADC_TempSenseOrNormal;



/*The Configure Structure required to initiate the ADC module*/
typedef struct configureAdc
{

	uint8_t AnalogInputs_Select[8];
	ADC_TempSenseOrNormal TempSensorNormal_Select[8];
	ADC_EndOfConversion EOF;
	ADC_Number AN;
	ADC_InterruptSelect IS;
	
	/*Mask to enable and disable the 4 sequencers in the ADC module*/
	uint8_t ActiveSequencer_Mask;
	
}ADC_ConfigureStruct;




/*Functions Prototypes*/


/*This function is used to initiate any of the 2 ADC modules in the controller*/
/*Inputs: Reference to the  required configured settings structure */
void ADC_init(const ADC_ConfigureStruct*);




/*This function is used to stop and all the settings in the ADC module as if it was reset*/
/*Inputs: ADC number to be stopped*/
void ADC_deinit(ADC_Number);


	
/*This function is used to read the Sequencer Result FIFO which contains the converted data*/
/*Input: ADC number to be read*/
/*Return: 12-bit converted data*/
uint16_t ADC_readChannel(ADC_Number);




/*This function is used to set the call back function which will be called in the 
	interrupt handler routine*/
/*Inputs: Pointer to function which takes void and return void and points to the call back function*/ 	
void ADC_setISRCallBack(void(*)(void));




#endif