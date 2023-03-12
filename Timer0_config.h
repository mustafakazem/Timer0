/*
 * Timer0_config.h
 *
 * Created: 3/12/2023 4:53:16 AM
 *  Author: sata
 */ 


#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_


/*************************************************/
/*           MACROS TO SELECT MODE              */
/***********************************************/

/*Range
TIMER0_NORMAL
TIMER0_CTC
TIMER0_FAST_PWM
TIMER0_PHASE_PWM
*/

#define TIMER0_MODE 		TIMER0_FAST_PWM

/*************************************************/
/*           MACROS TO SELECT PRESCALER         */
/***********************************************/

/*Range
TIMER0_DIV_BY_1
TIMER0_DIV_BY_8
TIMER0_DIV_BY_64
TIMER0_DIV_BY_256
TIMER0_DIV_BY_1024
*/

#define TIMER0_PRESCALER  	TIMER0_DIV_BY_1024

/*************************************************/
/*           MACROS TO SELECT  Compare-         */
/*                Match Output Mode            */
/**********************************************/

/*Range
TIMER0_NO_ACTION
TIMER0_TOGGLE
TIMER0_SET
TIMER0_CLEAR
*/

#define TIMER0_COM_EVENT   TIMER0_CLEAR



#endif /* TIMER0_CONFIG_H_ */