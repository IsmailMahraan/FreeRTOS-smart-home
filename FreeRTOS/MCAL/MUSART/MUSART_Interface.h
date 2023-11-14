/*
 * MUSART_Interface.h
 *
 *  Created on: Nov 25, 2022
 *      Author: medo
 */

#ifndef MCAL_MUSART_MUSART_INTERFACE_H_
#define MCAL_MUSART_MUSART_INTERFACE_H_

/*Functions Prototypes*/
void MUSART_Init();

void MUSART_SendChar(u8 TransmitValue);
u8 MUSART_ReceiveChar();


void MUSART_SendString(u8* P_TransmitString);
void MUSART_ReceiveString(u8* P_ReceiveString);



#endif /* MCAL_MUSART_MUSART_INTERFACE_H_ */
