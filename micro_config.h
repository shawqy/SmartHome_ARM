/*
 * 		Module:  Micro Config
 *
 *		File Name: micro_config.h
 *
 *		Disc: --------
 *
 * 	    Created on: ------
 *
 *      Author: Samir Mossad Ibrahim
 */


#ifndef MICRO_CONFIG_H
#define MICRO_CONFIG_H

#include "tm4c123gh6pm.h"

#define UNLOCK_32_BIT_VALUE 0X4C4F434B

#define GPIO_PORT_A_APB_BASE_ADDRESSE		(0x40004000)
#define GPIO_PORT_B_APB_BASE_ADDRESSE		(0x40005000)
#define GPIO_PORT_C_APB_BASE_ADDRESSE		(0x40006000)
#define GPIO_PORT_D_APB_BASE_ADDRESSE		(0x40007000)
#define GPIO_PORT_E_APB_BASE_ADDRESSE		(0x40024000)
#define GPIO_PORT_F_APB_BASE_ADDRESSE		(0x40025000)



#define GPIO_PORT_DIRECTION_R_OFFSET    (0x00000400) 
#define GPIO_PORT_DEN_R_OFFSET          (0x0000051C)
#define GPIO_PORT_AFSEL_R_OFFSET        (0x00000420)
#define GPIO_PORT_AMSEL_R_OFFSET        (0x00000528)
#define GPIO_PORT_LOCK_R_OFFSET         (0x00000520)
#define GPIO_PORT_CR_R_OFFSET  			(0x00000524)
#define GPIO_PORT_PUR_R_OFFSET 			(0x00000510)
#define GPIO_PORT_PDR_R_OFFSET 			(0x00000514)
#define GPIO_PORT_DATA_R_OFFSET         (0x00000000)




#endif
