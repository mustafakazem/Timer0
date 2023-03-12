/*
 * Timer0_priv.h
 *
 * Created: 3/12/2023 4:55:25 AM
 *  Author: sata
 */ 


#ifndef TIMER0_PRIV_H_
#define TIMER0_PRIV_H_


#define TIMSK	 (*(volatile u8 * )0x59)
#define OCIE0    1
#define TOIE0    0

/*********************************************/
/*           Address of OCR0 register       */
/*******************************************/

#define OCR0 	 (*(volatile u8 * )0x5C)

/**********************************************/
/*           Address of TCCR0 register       */
/*               and its bits               */
/*******************************************/

#define TCCR0	 (*(volatile u8 * )0x53)
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/*********************************************/
/*           Address of TCNT0 register      */
/*******************************************/

#define TCNT0	 (*(volatile u8 * )0x52)

/**********************************************/
/*           Address of TIFR register        */
/*               and its bits               */
/*******************************************/

#define TIFR	 (*(volatile u8 * )0x58)
#define OCF0     1
#define TOV0     0

/*************************************************/
/*           MACROS TO SELECT MODE              */
/***********************************************/

#define TIMER0_NORMAL 		1
#define TIMER0_CTC 			2
#define TIMER0_FAST_PWM 	3
#define TIMER0_PHASE_PWM 	4

/*************************************************/
/*           MACROS TO SELECT PRESCALER         */
/***********************************************/

#define TIMER0_DIV_BY_1			1
#define TIMER0_DIV_BY_8			5
#define TIMER0_DIV_BY_64		8
#define TIMER0_DIV_BY_256		10
#define TIMER0_DIV_BY_1024		15

/*************************************************/
/*           MACROS TO SELECT  Compare-         */
/*                Match Output Mode            */
/**********************************************/

#define TIMER0_NO_ACTION	100
#define TIMER0_TOGGLE		12
#define TIMER0_SET			20
#define TIMER0_CLEAR		25



#endif /* TIMER0_PRIV_H_ */