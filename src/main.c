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
DECLARACIONES:
------------------------------------------------------------------------------*/
//Tiempo de interrupcion por Systick - 50mseg:
#define TimeINT_Systick 0.05

//Ticks del despachador de tareas:
#define Ticks_RefreshTIM1	 10

//Definicion de Pins de PE9 como OSC1 del TIM1:
#define TIM1_OC1_Port	GPIOE
#define TIM1_OC1		GPIO_Pin_9

//Base de tiempo y ciclo de trabajo del TIM1:
#define TimeBase 	200000	//200kHz
#define DutyCycle	50		//DT 50%

/*------------------------------------------------------------------------------
DECLARACION DE FUNCIONES LOCALES:
------------------------------------------------------------------------------*/
void REFRESH_TIM1(void);

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

//Variables del despachador de tareas (TS):
uint32_t RefreshTIM1 = 0;

//Variable para cambiar la frecuencia de operacion del TIM1:
uint32_t Freq = 0;

int main(void)
{
/*------------------------------------------------------------------------------
CONFIGURACION DEL MICRO:
------------------------------------------------------------------------------*/
	SystemInit();

	//[1]Inicializacion de interrupcion por tiempo cada 50 mseg:
	INIT_SYSTICK(TimeINT_Systick);

	//Inicialización de PE9 como OSC1 del TIM1:
	INIT_TIM1(TIM1_OC1_Port, TIM1_OC1);

/*------------------------------------------------------------------------------
BUCLE PRINCIPAL:
------------------------------------------------------------------------------*/
    while(1)
    {
    	if(RefreshTIM1 == Ticks_RefreshTIM1)
    		REFRESH_TIM1();
    }
}

/*------------------------------------------------------------------------------
INTERRUPCIONES:
------------------------------------------------------------------------------*/
//Interrupcion por tiempo - Systick cada 50mseg:
void SysTick_Handler()
{
	RefreshTIM1++;
}

/*------------------------------------------------------------------------------
TAREAS:
------------------------------------------------------------------------------*/
void REFRESH_TIM1(void)
{
	RefreshTIM1 = 0;
	Freq = 100;
	SET_TIM1(TIM1_OC1, TimeBase, Freq, DutyCycle);
}
