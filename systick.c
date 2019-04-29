
#include "systick.h"

static volatile uint32_t milliseconds=0;


void SysTick_Handler(void)
{
	
	milliseconds++;
 	NVIC_ST_CURRENT_R|=0;

		
}

void SYSTICK_init(const SysTick_Configure * ptr_configure)
{


	RESET_BIT(NVIC_ST_CTRL_R,BIT_0);
	
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_RELOAD_R=0;
	
	
	
	
	switch(ptr_configure->Clock)
	{
		
		case F_CPU_4:  
				 RESET_BIT(NVIC_ST_CTRL_R,BIT_2);
								 
				 NVIC_ST_RELOAD_R=4000-1;
	
	
				break;			
		
		case F_CPU:  
				 SET_BIT(NVIC_ST_CTRL_R,BIT_2);
								
				 NVIC_ST_RELOAD_R=16000-1;
	
				 break;			
	}

	
	switch(ptr_configure->Interrupt)
	{
		
		case INTERRUPT_DISABLED:  
						 RESET_BIT(NVIC_ST_CTRL_R,BIT_1);
                                                 break;			
		
		case INTERRUPT_ENABLED:  
						 SET_BIT(NVIC_ST_CTRL_R,BIT_1);
                                                 break;			
	}

	
}


void SYSTICK_delay(const uint32_t _miliSeconds)
{

	
	NVIC_ST_CTRL_R &=~0x00000001;
	
	NVIC_ST_CURRENT_R=0;
	
	NVIC_ST_CTRL_R|=0x00000001;

 	while(milliseconds <= _miliSeconds);

	NVIC_ST_CTRL_R &=~0x00000001;

	milliseconds=0;

	
}




