/***************************** (C) COPYRIGHT ************************************
* File Name          : led.h
* Author             : �Ƿ�
* Version            : V1.0
* Date               : 12/03/2015
* Description        : LED����
* Note               : ��Ȩ����  �Ͻ�����
********************************************************************************/
#ifndef __LED_H_
#define __LED_H_

#include "stm32f7xx.h"
#include "stm32_types.h"
#include "stm32f7xx_hal.h"

/*******************************************************************************
* Function Name  : LED_Init
* Description    : LED��ʼ��
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void LED_Init(void);

/*******************************************************************************
* Function Name  : LED_Flash
* Description    : LED��˸
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void LED_Flash(void);


#endif
