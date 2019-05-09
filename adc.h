

#ifndef ADC_H
#define ADC_H

#include "micro_config.h"
#include "macros.h"
#include "std_types.h"


/*Shifting Macros*/
#define SHIFT(A,B)   ((A*4)+(B))



/*This defines to select the trigger source for each Sample Sequencer for each ADC
  Please note that if the sequencer is not activated ,there will be no affect for these triggers*/
#define ADC0_SAMPLE_SEQUNECERS_SOURCE_SELECT     0xFFFF
#define ADC1_SAMPLE_SEQUNECERS_SOURCE_SELECT     0xFFFF




/*Enumerations*/

typedef enum
{

ADC_0,ADC_1

}ADC_Number;



typedef enum
{

ADC_INTERRUPT_DISABLED,ADC_INTERRUPT_ENABLED

}ADC_InterruptSelect;


typedef enum
{

	SEQUENCER_0,
	SEQUENCER_1,
	SEQUENCER_2,
	SEQUENCER_3
	
}ADC_Sequencer;



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

NORMAL_SELECT,TEMP_SENSOR

}ADC_TempSenseOrNormal;



typedef struct sample
{
	
	suint8_t SampleNumber; /*signed 8-bits*/
	uint8_t AnalogInput;
	uint8_t LastSample; /* 1 means it is the last sample in its sequencer*/
  ADC_Sequencer SequencerNumber;
	ADC_TempSenseOrNormal T_OR_N;
	ADC_InterruptSelect IS;
	

}ADC_Sample;


/*The Configure Structure required to initiate the ADC module*/
typedef struct configureAdc
{

	/*Reference to Samples Array in all sequencers presented in ADC Module*/
	/*If you don't need to fill all the samples
	  Fill the Sample after the last one with sample number -ve*/ 
	ADC_Sample* Samples;
	ADC_Number AN;
	 
	/*Mask to enable and disable interrutps for the 4 sequencers the ADC module*/
	uint8_t InterruptSelect_Mask;
	
	/*Mask to enable and disable the 4 sequencers in the ADC module*/
	uint8_t ActiveSequencer_Mask;
	
	/*Mask to enable the ports clock for ADC module*/
	uint8_t PortGPIOClock_Mask;
	
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
void ADC_setISRCallBack(void(*)(void),ADC_Number);




#endif
