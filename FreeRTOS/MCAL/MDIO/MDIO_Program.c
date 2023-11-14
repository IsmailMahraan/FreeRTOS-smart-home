/*
 * MDIO_Program.c
 *
 *  Created on: Sep 24, 2022
 *      Author: medo
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"MDIO_Interface.h"
#include"MDIO_Private.h"

void MDIO_SetPortDirection(u8 Copy_u8PortNumber, u8 Copy_u8PortDirection)
{
	if((Copy_u8PortDirection==PORT_OUTPUT)||(Copy_u8PortDirection==PORT_INPUT))
	{
		/*Valid Port Direction given */
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			DDRA=Copy_u8PortDirection;
			break;
		case MDIO_PORTB:
			DDRB=Copy_u8PortDirection;
			break;
		case MDIO_PORTC:
			DDRC=Copy_u8PortDirection;
			break;
		case MDIO_PORTD:
			DDRD=Copy_u8PortDirection;
			break;
		default:
			/*Wrong Port Number Passed*/
			break;
		}
	}
	else
	{
		/*Invalid Port Direction given */
	}
}



void MDIO_SetPinDirection(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber, u8 Copy_u8PinDirection)
{
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRA,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRA,Copy_u8PinNumber);
			}
			else
			{
				//Invalid Pin Direction
			}
			break;
		case MDIO_PORTB:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRB,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRB,Copy_u8PinNumber);
			}
			else
			{
				//Invalid Pin Direction
			}
			break;
		case MDIO_PORTC:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRC,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRC,Copy_u8PinNumber);
			}
			else
			{
				//Invalid Pin Direction
			}
			break;
		case MDIO_PORTD:
			if(Copy_u8PinDirection==PIN_OUTPUT)
			{
				SET_BIT(DDRD,Copy_u8PinNumber);
			}
			else if(Copy_u8PinDirection==PIN_INPUT)
			{
				CLR_BIT(DDRD,Copy_u8PinNumber);
			}
			else
			{
				//Invalid Pin Direction
			}
			break;
		default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin Number*/
	}
}


void MDIO_SetPortValue(u8 Copy_u8PortNumber, u8 Copy_u8PortValue)
{
	if((Copy_u8PortValue==PORT_HIGH)||(Copy_u8PortValue==PORT_LOW))
	{
		/*Valid Port Direction given */
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			PORTA=Copy_u8PortValue;
			break;
		case MDIO_PORTB:
			PORTB=Copy_u8PortValue;
			break;
		case MDIO_PORTC:
			PORTC=Copy_u8PortValue;
			break;
		case MDIO_PORTD:
			PORTD=Copy_u8PortValue;
			break;
		default:
			/*Wrong Port Number Passed*/
			break;
		}
	}
	else
	{
		/*Invalid Port Value given */
	}
}

void MDIO_SetPinValue(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber, u8 Copy_u8PinValue)
{
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			if(Copy_u8PinValue==PIN_HIGH)
			{
				SET_BIT(PORTA,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==PIN_LOW)
			{
				CLR_BIT(PORTA,Copy_u8PinNumber);
			}
			else
			{
				//Invalid Pin Value
			}
			break;
		case MDIO_PORTB:
			if(Copy_u8PinValue==PIN_HIGH)
			{
				SET_BIT(PORTB,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==PIN_INPUT)
			{
				CLR_BIT(PORTB,Copy_u8PinNumber);
			}
			else
			{
				//Invalid Pin Value
			}
			break;
		case MDIO_PORTC:
			if(Copy_u8PinValue==PIN_OUTPUT)
			{
				SET_BIT(PORTC,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==PIN_INPUT)
			{
				CLR_BIT(PORTC,Copy_u8PinNumber);
			}
			else
			{
				//Invalid Pin Value
			}
			break;
		case MDIO_PORTD:
			if(Copy_u8PinValue==PIN_OUTPUT)
			{
				SET_BIT(PORTD,Copy_u8PinNumber);
			}
			else if(Copy_u8PinValue==PIN_INPUT)
			{
				CLR_BIT(PORTD,Copy_u8PinNumber);
			}
			else
			{
				//Invalid Pin Value
			}
			break;
		default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin Number*/
	}
}

void MDIO_ReadPort(u8 Copy_u8PortNumber, u8 * P_u8PortReading)
{
	if(P_u8PortReading!=NULL)
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			*P_u8PortReading=PINA;
			break;
		case MDIO_PORTB:
			*P_u8PortReading=PINB;
			break;
		case MDIO_PORTC:
			*P_u8PortReading=PINC;
			break;
		case MDIO_PORTD:
			*P_u8PortReading=PIND;
			break;
		default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		//Null Pointer
	}
}


void MDIO_ReadPin(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber, u8 * P_u8PortReading)
{
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			*P_u8PortReading=GET_BIT(PINA,Copy_u8PinNumber);
			break;
		case MDIO_PORTB:
			*P_u8PortReading=GET_BIT(PINB,Copy_u8PinNumber);
			break;
		case MDIO_PORTC:
			*P_u8PortReading=GET_BIT(PINC,Copy_u8PinNumber);
			break;
		case MDIO_PORTD:
			*P_u8PortReading=GET_BIT(PIND,Copy_u8PinNumber);
			break;
		default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin Number*/
	}
}

void MDIO_TogglePin(u8 Copy_u8PinNumber,u8 Copy_u8PortNumber)
{
	if((Copy_u8PinNumber>=0)&&(Copy_u8PinNumber<8))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			TOGGLE_BIT(PORTA,Copy_u8PinNumber);
			break;
		case MDIO_PORTB:
			TOGGLE_BIT(PORTB,Copy_u8PinNumber);
			break;
		case MDIO_PORTC:
			TOGGLE_BIT(PORTC,Copy_u8PinNumber);
			break;
		case MDIO_PORTD:
			TOGGLE_BIT(PORTD,Copy_u8PinNumber);
			break;
		default:
			/*Wrong Port Chosen*/
			break;
		}
	}
	else
	{
		/*Wrong Pin Number*/
	}
}


void MDIO_SetNibbleValue(u8 Copy_u8PinStart, u8 Copy_u8PortNumber, u8 Copy_u8Value)
{
	u8 Loc_u8Value=Copy_u8Value;

	//Handling of the Value
	Loc_u8Value=((Loc_u8Value&(0x0F))<<Copy_u8PinStart);

	if((Copy_u8PinStart<=4)&&(Copy_u8PinStart>=0))
	{
		switch(Copy_u8PortNumber)
		{
		case MDIO_PORTA:
			//Mask Port A
			PORTA&=(~(0x0F<<Copy_u8PinStart));
			PORTA|=Loc_u8Value;

			break;
		case MDIO_PORTB:
			PORTB&=(~((0x0F)<<Copy_u8PinStart));
			PORTB|=Loc_u8Value;

			break;
		case MDIO_PORTC:
			PORTC&=(~((0x0F)<<Copy_u8PinStart));
			PORTC|=Loc_u8Value;

			break;
		case MDIO_PORTD:
			PORTD&=(~((0x0F)<<Copy_u8PinStart));
			PORTD|=Loc_u8Value;

			break;
		default:
			//Wrong Port Passed
			break;
		}
	}
	else
	{
		//Do Nothing

	}
}
