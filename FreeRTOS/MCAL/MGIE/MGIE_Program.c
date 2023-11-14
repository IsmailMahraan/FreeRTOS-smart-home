/*
 * MGIE_Program.c
 *
 *  Created on: Oct 21, 2022
 *      Author: medo
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"MGIE_Private.h"

/*Functions Prototypes*/
void MGIE_Enable(void)
{
	SET_BIT(SREG,7);
}

void MGIE_Disable(void)
{
	CLR_BIT(SREG,7);
}

