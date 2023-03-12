/*
 * Timer0_prog.c
 *
 * Created: 3/12/2023 4:51:44 AM
 *  Author: sata
 */ 
#include "Timer0_int.h"

/****************************************************************/
/*********************** Function Implementation  ***************/
/****************************************************************/

/****************************************************************/
/* Description    : This function used for TIMER0 INIT         	*/
/*																*/
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_Init(void)
{
	/********************************/
	/*       Mode Selection        */
	/******************************/
	#if(TIMER0_MODE == TIMER0_NORMAL)
	CLEAR_BIT(TCCR0 , WGM00);
	CLEAR_BIT(TCCR0 , WGM01);
	
	#elif(TIMER0_MODE == TIMER0_CTC)
	CLEAR_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);
	
	#elif(TIMER0_MODE == TIMER0_FAST_PWM )
	SET_BIT(TCCR0 , WGM00);
	SET_BIT(TCCR0 , WGM01);
	
	#elif(TIMER0_MODE == TIMER0_PHASE_PWM )
	SET_BIT(TCCR0 , WGM00);
	CLEAR_BIT(TCCR0 , WGM01);
	
	#endif
	
	/*************************************/
	/*       Prescaler Selection        */
	/***********************************/
	
	#if(TIMER0_PRESCALER == TIMER0_DIV_BY_1)
	SET_BIT(TCCR0 , CS00);
	CLEAR_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
	
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_8)
	CLEAR_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_64 )
	SET_BIT(TCCR0 , CS00);
	SET_BIT(TCCR0 , CS01);
	CLEAR_BIT(TCCR0 , CS02);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_256 )
	CLEAR_BIT(TCCR0 , CS00);
	CLEAR_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS02);
	#elif(TIMER0_PRESCALER == TIMER0_DIV_BY_1024 )
	SET_BIT(TCCR0 , CS00);
	CLEAR_BIT(TCCR0 , CS01);
	SET_BIT(TCCR0 , CS02);
	
	#endif
	
	/*************************************************/
	/*           Select  Compare Match              */
	/*                 Output Mode                 */
	/**********************************************/
	
	#if(TIMER0_COM_EVENT == TIMER0_NO_ACTION)
	CLEAR_BIT(TCCR0 , COM00);
	CLEAR_BIT(TCCR0 , COM01);
	#elif(TIMER0_COM_EVENT == TIMER0_TOGGLE)
	SET_BIT(TCCR0 , COM00)
	CLEAR_BIT(TCCR0 , COM01);
	#elif(TIMER0_COM_EVENT == TIMER0_CLEAR )
	CLEAR_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);
	#elif(TIMER0_COM_EVENT == TIMER0_SET )
	SET_BIT(TCCR0 , COM00);
	SET_BIT(TCCR0 , COM01);

	
	#endif

	/*************************************/
	/*       Disable Interrupt          */
	/***********************************/
	
	CLEAR_BIT(TIMSK , TOIE0);
	CLEAR_BIT(TIMSK , OCIE0);
	
	/*************************************/
	/*          Clear Flags             */
	/***********************************/
	
	SET_BIT(TIFR , TOIE0);
	SET_BIT(TIFR , OCIE0);
	
	/*************************************/
	/*       Clear TCNT0 & OCR0 REG     */
	/***********************************/
	
	TCNT0 = 0 ;
	OCR0 = 0 ;
	
}

/****************************************************************/
/* Description    : This function used for Pre-loading         	*/
/*                        in TCNT0                              */
/*																*/
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_SetTimerReg(u8 Copy_uint8Val)
{
	TCNT0 = Copy_uint8Val ;
}

/****************************************************************/
/* Description    : This function used for entering         	*/
/*                     the value in OCR0 REG.                   */
/*					Inputs : Copy_uint8Val					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_SetCompareVal(u8 Copy_uint8Val)
{
	OCR0 = Copy_uint8Val ;
}

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , TOIE0);
}

/****************************************************************/
/* Description    : This function used for disable interrupt   	*/
/*                        the overflow mode                     */
/*																*/
/*					Inputs : void       					  	*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , TOIE0);
}

/****************************************************************/
/* Description    : This function used for enable interrupt    	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , OCIE0);
}

/****************************************************************/
/* Description    : This function used for disable interrupt  	*/
/*                          the CTC mode                        */
/*					Inputs : void					  			*/
/*					Return : void		 					    */
/****************************************************************/

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , OCIE0);
}

/********************************************************************/
/*               CALL BACK FUNC & VECTOR TABLE ID                  */
/******************************************************************/

/******************* OVERFLOW MODE ************************/

void (*TIMER0_OV_CallBack) (void) ;

void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_OV_CallBack = Copy_ptr ;
}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}

/*********************** CTC MODE ************************/

void (*TIMER0_CTC_CallBack) (void) ;
void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}
void __vector_10(void) __attribute__((signal , used));
void __vector_10(void)
{
	
	TIMER0_CTC_CallBack();
}
