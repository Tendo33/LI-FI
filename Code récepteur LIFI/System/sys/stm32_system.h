/***************************** (C) COPYRIGHT ************************************
* File Name          : stm32_system.h
* Author             : 非凡
* Version            : V1.0
* Date               : 12/02/2015
* Description        : STM32F7时钟配置驱动程序头文件
* Note               : 版权所有  严禁盗版
********************************************************************************/
#ifndef __STM_SYSTEM_H_
#define __STM_SYSTEM_H_

#include "stm32f7xx.h"
#include "stm32_types.h"
#include "stm32f7xx_hal.h"

#define FOSC  25     //MCU时钟晶振25MHz

/*******************************************************************************
* Function Name  : SystemClock_Config
* Description    : STM32F7时钟配置
* Input          : Fosc: 输入晶振频率,单位MHz
* Output         : None
* Return         : None
* Note			 : Fvco=Fs*(plln/pllm),VCO时钟频率
				   Fsys=Fvco/pllp, MCU系统时钟频率,这里为216MHz
				   Fusb=Fvco/pllq, USB,SDIO,RNG时钟频率,必须为48MHz
				   PLLN:主PLL倍频系数(PLL倍频),取值范围:192~432
				   PLLM:主PLL和音频PLL分频系数(PLL之前的分频),取值范围:2~63
				   PLLP:系统时钟的主PLL分频系数(PLL之后的分频),取值范围:2,4,6,8.(仅限这4个值)
				   PLLQ:USB/SDIO/随机数产生器等的主PLL分频系数(PLL之后的分频),取值范围:2~15
				   Fs:晶振输入(4-26MHz)(HSE)
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
* Description    : STM32F7的L1-Cache使能
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void CPU_CACHE_Enable(void);

/*******************************************************************************
* Function Name  : NVIC_Config
* Description    : NVIC中断配置
* Input          : IRQn:中断号
				   PriorityGroup：优先级分组
				   priority：优先级
* Output         : None
* Return         : None
* Note			 : 调用函数定义在core_cm7.h中, 注意所有中断的优先级分组是一样的
				   优先级分组时针对所有的中断的,此函数是针对外设中断的，不包括
				   系统中断,SysTick
*******************************************************************************/
void NVIC_Config(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t priority);

//系统软复位   
void Sys_Soft_Reset(void);

/*******************************************************************************
* Function Name  : System_Init
* Description    : 系统初始化
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/
void System_Init(void);


#endif /* __LPC_SYSTEM_H_ */
