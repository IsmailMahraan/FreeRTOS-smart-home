/*
 * HKPD_Program.c
 *
 *  Created on: Oct 14, 2022
 *      Author: medo
 */


#include"HKPD_Interface.h"
#include"HKPD_Private.h"
#include "../../FreeRTOS_Stack/FreeRTOS.h"

void HKPD_Init()
{
	/*Set Columns Pins Direction Output*/
	MDIO_SetPinDirection(HKPD_COLUMN_0_PIN,HKPD_COLUMN_PORT,PIN_OUTPUT);
	MDIO_SetPinDirection(HKPD_COLUMN_1_PIN,HKPD_COLUMN_PORT,PIN_OUTPUT);
	MDIO_SetPinDirection(HKPD_COLUMN_2_PIN,HKPD_COLUMN_PORT,PIN_OUTPUT);
	MDIO_SetPinDirection(HKPD_COLUMN_3_PIN,HKPD_COLUMN_PORT,PIN_OUTPUT);

	/*Set Row Pins Direction Input*/
	MDIO_SetPinDirection(HKPD_ROW_0_PIN,HKPD_ROW_PORT,PIN_INPUT);
	MDIO_SetPinDirection(HKPD_ROW_1_PIN,HKPD_ROW_PORT,PIN_INPUT);
	MDIO_SetPinDirection(HKPD_ROW_2_PIN,HKPD_ROW_PORT,PIN_INPUT);
	MDIO_SetPinDirection(HKPD_ROW_3_PIN,HKPD_ROW_PORT,PIN_INPUT);

	/*Activate Pull up Resistor */
	MDIO_SetPinValue(HKPD_ROW_0_PIN,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(HKPD_ROW_1_PIN,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(HKPD_ROW_2_PIN,HKPD_ROW_PORT,PIN_HIGH);
	MDIO_SetPinValue(HKPD_ROW_3_PIN,HKPD_ROW_PORT,PIN_HIGH);

	/*Deactivate Columns */
	MDIO_SetPinValue(HKPD_COLUMN_0_PIN,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(HKPD_COLUMN_1_PIN,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(HKPD_COLUMN_2_PIN,HKPD_COLUMN_PORT,PIN_HIGH);
	MDIO_SetPinValue(HKPD_COLUMN_3_PIN,HKPD_COLUMN_PORT,PIN_HIGH);

}


u8 HKPD_GetPressedButton()
{
	u8 Loc_u8ColumnCounter=0;
	u8 Loc_u8RowCounter=0;

	u8 Loc_u8ReturnValue=HKPD_NOT_PRESSED;

	u8 Loc_u8PinState=0;

	for (Loc_u8ColumnCounter=HKPD_COL_START;Loc_u8ColumnCounter<HKPD_COL_END;Loc_u8ColumnCounter++)
	{
		/*Activate the column*/
		MDIO_SetPinValue(Loc_u8ColumnCounter,HKPD_COLUMN_PORT,PIN_LOW);


		for(Loc_u8RowCounter=HKPD_ROW_START;Loc_u8RowCounter<HKPD_ROW_END;Loc_u8RowCounter++)
		{
			MDIO_ReadPin(Loc_u8RowCounter,HKPD_ROW_PORT,&Loc_u8PinState);

			if(Loc_u8PinState==0)
			{
				// Retrieve the Key Value
				Loc_u8ReturnValue=HKPD_SwitchValues[Loc_u8ColumnCounter-HKPD_COL_START][Loc_u8RowCounter-HKPD_ROW_START];

				while(Loc_u8PinState==0)
				{
					MDIO_ReadPin(Loc_u8RowCounter,HKPD_ROW_PORT,&Loc_u8PinState);
				}

			}
			else
			{
				//Do Nothing
			}
		}

		//Deactivate Column
		MDIO_SetPinValue(Loc_u8ColumnCounter,HKPD_COLUMN_PORT,PIN_HIGH);
	}
	return Loc_u8ReturnValue;
}
