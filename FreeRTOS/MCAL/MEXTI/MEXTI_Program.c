/*
 * MEXTI_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: medo
 */

/*
 * Set Sense Control
 * Enable PIE
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"MEXTI_Config.h"


void MEXTI0_Init()
{
#if MEXTI_SENSE_CONTROL_STATE==MEXTI_LOW_LEVEL

	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif MEXTI_SENSE_CONTROL_STATE==MEXTI_ANY_LOGICAL_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);

#elif MEXTI_SENSE_CONTROL_STATE==MEXTI_RISING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);

#elif MEXTI_SENSE_CONTROL_STATE==MEXTI_FALLING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#endif

	/*Enable Interrupt on INT0 ==> PIE of Interrupt zero*/
	SET_BIT(GICR,6);
}

void MEXTI1_Init()
{

}

void MEXTI2_Init()
{

}

