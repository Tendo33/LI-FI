
#include "led.h"
#include "delay.h"

/*******************************************************************************
* Function Name  : LED_Init
* Description    : None
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void LED_Init(void)
{    	 
	GPIO_InitTypeDef  GPIO_InitStruct;

	__GPIOI_CLK_ENABLE(); //Activation de l'horloge GPIOI

	//Param¨¨tres d'initialisation de GPIOI1
	GPIO_InitStruct.Pin = GPIO_PIN_2;              //Les LEDs correspondent aux ports IO
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;    
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;       //50MHz
	GPIO_InitStruct.Pull = GPIO_PULLUP;            
	HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);        

	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_2,GPIO_PIN_RESET);//GPIOI1 tir¨¦ vers le bas, lampe ¨¦teinte
}

/*******************************************************************************
* Function Name  : LED_Flash
* Description    : None
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void LED_Flash(void)
{	
	HAL_GPIO_TogglePin(GPIOI,GPIO_PIN_2);
	delay_ms(200);
}


