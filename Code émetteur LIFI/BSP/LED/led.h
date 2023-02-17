/***************************** (C) COPYRIGHT ************************************
* File Name          : led.h
* Author             : 非凡
* Version            : V1.0
* Date               : 12/03/2015
* Description        : LED驱动
* Note               : 版权所有  严禁盗版
********************************************************************************/
#ifndef __LED_H_
#define __LED_H_

#include "stm32f7xx.h"
#include "stm32_types.h"
#include "stm32f7xx_hal.h"

/*******************************************************************************
* Function Name  : LED_Init
* Description    : LED初始化
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void LED_Init(void);

/*******************************************************************************
* Function Name  : LED_Flash
* Description    : LED闪烁
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void LED_Flash(void);


#endif
