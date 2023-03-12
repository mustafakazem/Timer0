/*
 * Timer0_int.h
 *
 * Created: 3/12/2023 4:54:05 AM
 *  Author: sata
 */ 


#ifndef TIMER0_INT_H_
#define TIMER0_INT_H_



/****************************************************************/
/*********************** STD LIB DIRECTIVES *********************/
/****************************************************************/

#include "std_types.h"
#include "bit_math.h"

/****************************************************************/
/*********************** Component DIRECTIVES *******************/
/****************************************************************/

#include "dio.h"
#include "TIMER2_priv.h"
#include "TIMER2_config.h"

/*******************************************************************/
/* Description   : File Guard to protect the file from include     
                   more than one time.                           */
/****************************************************************/

#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H

/****************************************************************/
/* Description    : This function used for TIMER0 INIT         	*/ 
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_Init(void);

/****************************************************************/
/* Description    : This function used for Pre-loading         	*/
/*                        in TCNT0                              */
/*																*/
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val);

/****************************************************************/
/* Description    : This function used for entering         	*/
/*                     the value in OCR0 REG.                   */
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val);

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_EnableOVInt(void);

/****************************************************************/
/* Description    : This function used for disable interrupt   	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_DisableOVInt(void);

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_EnableCTCInt(void);

/****************************************************************/
/* Description    : This function used for disable interrupt  	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_DisableCTCInt(void);

/****************************************************************/
/* Description    : The call back func. for timer 0         	*/ 
/*						for the overflow mode       			*/
/*					Inputs : void (*Copy_ptr) (void)  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) ) ;

/****************************************************************/
/* Description    : The call back func. for timer 0         	*/ 
/*							for CTC mode    					*/
/*					Inputs : void (*Copy_ptr) (void)   			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) ;


#endif /* TIMER0_INT_H_ */