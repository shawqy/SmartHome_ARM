
#ifndef SYS_TICK_H
#define SYS_TICK_H

#include "micro_config.h"
#include "macros.h"
#include "std_types.h"

typedef enum systickclock
{

	F_CPU_4,F_CPU

}SysTick_clockSource;


typedef enum systickinterrupt
{

       INTERRUPT_DISABLED,INTERRUPT_ENABLED

}SysTick_interrupt;



typedef struct systickconfig
{
 
SysTick_clockSource    Clock;
SysTick_interrupt      Interrupt;	

}SysTick_Configure;




void SYSTICK_init(const SysTick_Configure *);



/*If you configured the systick to operate on the same clock of the cpu , you will only be able to 
  generate time delay ranging between 1ms ~ 1s 
*/
void SYSTICK_delay(const uint32_t);







#endif
