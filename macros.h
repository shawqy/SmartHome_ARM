/*
 * 		Module:  Macros.
 *
 *		File Name: macros.h
 *
 *		Disc: commonly used macros
 *
 * 	    Created on: ------
 *
 *      Author: Samir Mossad Ibrahim
 */

#ifndef MACROS_H_
#define MACROS_H_



/*Check if specific bit is set in any register*/
#define BIT_IS_SET(REG,BIT_NUM) ((REG)&(1<<BIT_NUM))


/*Check if specific bit is clear in any register*/
#define BIT_IS_CLEAR(REG,BIT_NUM) (!((REG)&(1<<BIT_NUM)))


/*Set a certain bit inside a any register*/
#define SET_BIT(REG,BIT_NUM) ((REG)=(REG)|(1<<BIT_NUM))


/*Reset a certain bit inside a any register*/
#define RESET_BIT(REG,BIT_NUM) ((REG)=(REG)&(~(1<<BIT_NUM)))


/*Toggle a certain bit inside a any register*/
#define TOGGLE_BIT(REG,BIT_NUM) ((REG)=(REG)^(1<<BIT_NUM))



/*Rotate right the register with specific no of rotates*/
#define ROTATE_RIGHT(REG,BIT_NUM) ((REG>>BIT_NUM)|(REG>>((sizeof(REG)*8)-BIT_NUM)))



/*Rotate left the register with specific no of rotates*/
#define ROTATE_LEFT(REG,BIT_NUM) ((REG<<BIT_NUM)|(REG<<>((sizeof(REG)*8)-BIT_NUM)))





#endif /* MACROS_H_ */
