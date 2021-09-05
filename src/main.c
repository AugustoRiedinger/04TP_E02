/****
  * @file    main.c
  * @author  G. Garcia & A. Riedinger.
  * @version 0.1
  * @date    04-09-21
  * @brief   Generacion de una senal por el TIM1 que varie de forma proporcional
  * 		 al voltaje medido por un ADC, manteniendo un DT del 50%.
  *
  *			 1 Vdc -> 100 Hz
  *			 2 Vdc -> 200 Hz
  *			 3 Vdc -> 300 Hz
  *			 [PC1] -> [PE9]

  * SALIDAS:
  	  *	LCD
  	  *	TIM1	PE9
  	  *	ADC1	PC1
  *
  * ENTRADAS:
  	  * TIM1	PE9
  ****/

/*------------------------------------------------------------------------------
LIBRERIAS:
------------------------------------------------------------------------------*/
#include "mi_libreria.h"

/*------------------------------------------------------------------------------
DEFINICIONES:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
DECLARACION DE FUNCIONES LOCALES:
------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
DECLARACION VARIABLES GLOBALES:
------------------------------------------------------------------------------*/
//Definicion de los pines del LCD:
LCD_2X16_t LCD_2X16[] = {
			// Name  , PORT ,   PIN      ,         CLOCK       ,   Init
			{ TLCD_RS, GPIOC, GPIO_Pin_10, RCC_AHB1Periph_GPIOC, Bit_RESET },
			{ TLCD_E,  GPIOC, GPIO_Pin_11, RCC_AHB1Periph_GPIOC, Bit_RESET },
			{ TLCD_D4, GPIOC, GPIO_Pin_12, RCC_AHB1Periph_GPIOC, Bit_RESET },
			{ TLCD_D5, GPIOD, GPIO_Pin_2,  RCC_AHB1Periph_GPIOD, Bit_RESET },
			{ TLCD_D6, GPIOF, GPIO_Pin_6,  RCC_AHB1Periph_GPIOF, Bit_RESET },
			{ TLCD_D7, GPIOF, GPIO_Pin_7,  RCC_AHB1Periph_GPIOF, Bit_RESET }, };



int main(void)
{
/*------------------------------------------------------------------------------
CONFIGURACION DEL MICRO:
------------------------------------------------------------------------------*/
	SystemInit();

/*------------------------------------------------------------------------------
BUCLE PRINCIPAL:
------------------------------------------------------------------------------*/
    while(1)
    {

    }
}

/*------------------------------------------------------------------------------
INTERRUPCIONES:
------------------------------------------------------------------------------*/


/*------------------------------------------------------------------------------
TAREAS:
------------------------------------------------------------------------------*/
