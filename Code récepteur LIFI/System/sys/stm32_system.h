/***************************** (C) COPYRIGHT ************************************
* File Name          : stm32_system.h
* Author             : �Ƿ�
* Version            : V1.0
* Date               : 12/02/2015
* Description        : STM32F7ʱ��������������ͷ�ļ�
* Note               : ��Ȩ����  �Ͻ�����
********************************************************************************/
#ifndef __STM_SYSTEM_H_
#define __STM_SYSTEM_H_

#include "stm32f7xx.h"
#include "stm32_types.h"
#include "stm32f7xx_hal.h"

#define FOSC  25     //MCUʱ�Ӿ���25MHz

/*******************************************************************************
* Function Name  : SystemClock_Config
* Description    : STM32F7ʱ������
* Input          : Fosc: ���뾧��Ƶ��,��λMHz
* Output         : None
* Return         : None
* Note			 : Fvco=Fs*(plln/pllm),VCOʱ��Ƶ��
				   Fsys=Fvco/pllp, MCUϵͳʱ��Ƶ��,����Ϊ216MHz
				   Fusb=Fvco/pllq, USB,SDIO,RNGʱ��Ƶ��,����Ϊ48MHz
				   PLLN:��PLL��Ƶϵ��(PLL��Ƶ),ȡֵ��Χ:192~432
				   PLLM:��PLL����ƵPLL��Ƶϵ��(PLL֮ǰ�ķ�Ƶ),ȡֵ��Χ:2~63
				   PLLP:ϵͳʱ�ӵ���PLL��Ƶϵ��(PLL֮��ķ�Ƶ),ȡֵ��Χ:2,4,6,8.(������4��ֵ)
				   PLLQ:USB/SDIO/������������ȵ���PLL��Ƶϵ��(PLL֮��ķ�Ƶ),ȡֵ��Χ:2~15
				   Fs:��������(4-26MHz)(HSE)
*******************************************************************************/
void SystemClock_Init(u8 Fosc);

/*******************************************************************************
* Function Name  : MPU_Config
* Description    : Configure the MPU attributes as Write Through for SRAM1/2
* Input          : None
* Output         : None
* Return         : None
* Note			 : The Base Address is 0x20010000 since this memory interface is the AXI.
         	       The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
*******************************************************************************/
void MPU_Config(void);

/*******************************************************************************
* Function Name  : CPU_CACHE_Enable
* Description    : STM32F7��L1-Cacheʹ��
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void CPU_CACHE_Enable(void);

/*******************************************************************************
* Function Name  : NVIC_Config
* Description    : NVIC�ж�����
* Input          : IRQn:�жϺ�
				   PriorityGroup�����ȼ�����
				   priority�����ȼ�
* Output         : None
* Return         : None
* Note			 : ���ú���������core_cm7.h��, ע�������жϵ����ȼ�������һ����
				   ���ȼ�����ʱ������е��жϵ�,�˺�������������жϵģ�������
				   ϵͳ�ж�,SysTick
*******************************************************************************/
void NVIC_Config(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t priority);

//ϵͳ��λ   
void Sys_Soft_Reset(void);

/*******************************************************************************
* Function Name  : System_Init
* Description    : ϵͳ��ʼ��
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void System_Init(void);


#endif /* __LPC_SYSTEM_H_ */
