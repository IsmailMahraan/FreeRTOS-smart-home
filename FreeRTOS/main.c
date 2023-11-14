
#include"LIB/STD_TYPES.h"
#include"LIB/BIT_MATH.h"
#include"MCAL/MDIO/MDIO_Interface.h"
#include"MCAL/MDIO/MDIO_Private.h"
#include"MCAL/MGIE/MGIE_Interface.h"
#include"MCAL/MTIMER/MTIMER_Interface.h"
#include"MCAL/MADC/MADC_Interface.h"
#include"HAL/HCLCD/HCLCD_Interface.h"
#include"HAL/HCLCD/HCLCD_Private.h"
#include"HAL/HKPD/HKPD_Interface.h"
#include"FreeRTOS_Stack/FreeRTOS.h"
#include"FreeRTOS_Stack/task.h"
#include"FreeRTOS_Stack/semphr.h"

/*Define Semaphor Variable */

xSemaphoreHandle LCD_Semphor;
u8 flag =0;
u32 temp=0;
u16 Reading=0;
u8 data[12]= "ADC READING:";
u8 keypressed='$';
/*Create 4 Tasks */

/*void LCD_Task(void)
{
	while(1)
	{
		HCLCD_WriteCommand4Bit(DISPALY_CLEAR_COMMAND);
					HCLCD_WriteString(data);
					HCLCD_SetCursorPosition(HCLCD_LINE_0,12);
					HCLCD_WriteNumber(temp);
					HCLCD_SetCursorPosition(HCLCD_LINE_1,14);
					HCLCD_WriteChar4Bit('C');
					HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
		if(pdPASS==xSemaphoreTake(LCD_Semphor,10))
		{

					xSemaphoreGive(LCD_Semphor);
		}


		Order the Scheduler to make the Task Periodicity by 150
		vTaskDelay(50);
	}
}
*/
void INIT(){
	while(1){
	xSemaphoreGive(LCD_Semphor);
	xSemaphoreTake(LCD_Semphor,portMAX_DELAY);
	HCLCD_Init4Bit();
	//HCLCD_WriteString(data);

	HKPD_Init();
	MADC_Init();
	HCLCD_WriteString("welcome home!");
	vTaskDelay(2000);
	xSemaphoreGive(LCD_Semphor);
	vTaskDelete(NULL);

	}

}
void KEYPAD_TASK(void)
{

	/*Define Variables or one time operations */
		xSemaphoreTake(LCD_Semphor,portMAX_DELAY);
		HCLCD_WriteCommand4Bit(DISPALY_CLEAR_COMMAND);
		HCLCD_WriteString("ENTER(1)FOR ADC!");
		xSemaphoreGive(LCD_Semphor);
	while(1)
	{
		/*Put your Periodic Action */

		keypressed = HKPD_GetPressedButton();

		if(keypressed!='$')
		{
//			if(pdPASS==xSemaphoreTake(LCD_Semphor,portMAX_DELAY))
//			{
//				if(keypressed=='1'){
//				flag =1;
//				}
//			else {
//				HCLCD_WriteCommand4Bit(DISPALY_CLEAR_COMMAND);
//				HCLCD_WriteString("Wrong Input!");
//
//			}
//
//			keypressed ='$';
//			xSemaphoreGive(LCD_Semphor);
//			}

					xSemaphoreTake(LCD_Semphor,portMAX_DELAY);
							if(keypressed=='1'){
							flag =1;
							keypressed ='$';

							}
						else {
							HCLCD_WriteCommand4Bit(DISPALY_CLEAR_COMMAND);
							vTaskDelay(5);
							HCLCD_WriteString("Wrong Input!");

						}
						xSemaphoreGive(LCD_Semphor);

		}
		/*Order the Scheduler to make the Task Periodicity by 150*/

		vTaskDelay(50);
	}
}
void ADC_TASK(void)
{

	/*Define Variables or one time operations */
	//xSemaphoreTake(LCD_Semphor,portMAX_DELAY);


	while(1)
	{

				if(pdPASS==xSemaphoreTake(LCD_Semphor,portMAX_DELAY))
				{
					if(flag==1){
							Reading = MADC_StartConversion(MADC_CHANNEL_0);
							temp =(u32)(Reading*500)/1023;
						HCLCD_WriteCommand4Bit(DISPALY_CLEAR_COMMAND);
						HCLCD_WriteString(data);
						HCLCD_SetCursorPosition(HCLCD_LINE_0,12);
						HCLCD_WriteNumber(temp);
						HCLCD_SetCursorPosition(HCLCD_LINE_1,14);
						HCLCD_WriteChar4Bit('C');
						HCLCD_SetCursorPosition(HCLCD_LINE_0,0);
					}
						xSemaphoreGive(LCD_Semphor);
				}
				/*Order the Scheduler to make the Task Periodicity by 50*/
				vTaskDelay(100);

}

}
int main ()
{

	/*define the Pins Direction */
	MDIO_SetPinDirection(PIN0,MDIO_PORTA,PIN_INPUT);
	/*Create Tasks */
	xTaskCreate(&INIT,NULL,200,NULL,9,NULL);
	xTaskCreate(&KEYPAD_TASK,NULL,200,NULL,5,NULL);
	xTaskCreate(&ADC_TASK,NULL,200,NULL,3,NULL);
	/*Create the Binary Semaphor*/
	vSemaphoreCreateBinary(LCD_Semphor);

	/*Call The Schedular */
	vTaskStartScheduler();


	return 0 ;
}
