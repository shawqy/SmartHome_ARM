/*
 * 		Module: Standard - Types.
 *
 *		File Name: std_types.h
 *
 *		Disc: standard types
 *
 * 	    Created on: -------
 *
 *      Author: Samir Mossad Ibrahim
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_




#ifndef FALSE
#define FALSE 	(0u)
#endif

#ifndef TRUE
#define TRUE 	(1u)
#endif

#ifndef HIGH
#define HIGH  	(1u)
#endif


#ifndef LOW
#define LOW  	(0u)
#endif


#define NULL_PTR (void*)(0)


typedef unsigned char bool;


typedef unsigned char 	uint8_t;
typedef unsigned char 	uint8;
typedef signed char 	suint8_t;
typedef unsigned short 	uint16_t;
typedef signed short 	suint16_t;
typedef unsigned long 	uint32_t;
typedef signed long 	suint32_t;
typedef  float 			float32_t;
typedef  double 		float64_t;






#endif /* STD_TYPES_H_ */
