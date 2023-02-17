/***************************** (C) COPYRIGHT ************************************
* File Name          : Timerx.h
* Author             : 非凡
* Version            : V1.0
* Date               : 12/03/2015
* Description        : 通用定时器驱动程序头文件
* Note               : 版权所有  严禁盗版
********************************************************************************/
#ifndef __TIMERX_H_
#define __TIMERX_H_

#include "stm32f7xx.h"
#include "stm32_types.h"
#include "stm32f7xx_hal.h"  

typedef struct 
{ 
    void (*T1_Handle)(void);  //定时器1中断中运行的函数
	void (*T2_Handle)(void);  //定时器2中断中运行的函数
	void (*T3_Handle)(void);  //定时器3中断中运行的函数
	void (*T4_Handle)(void);  //定时器4中断中运行的函数
	void (*T5_Handle)(void);  //定时器5中断中运行的函数
	void (*T6_Handle)(void);  //定时器6中断中运行的函数
	void (*T7_Handle)(void);  //定时器7中断中运行的函数
	void (*T8_Handle)(void);  //定时器8中断中运行的函数
	void (*T9_Handle)(void);  //定时器9中断中运行的函数
	void (*T10_Handle)(void);  //定时器10中断中运行的函数
	void (*T11_Handle)(void);  //定时器11中断中运行的函数
	void (*T12_Handle)(void);  //定时器12中断中运行的函数
	void (*T13_Handle)(void);  //定时器13中断中运行的函数
	void (*T14_Handle)(void);  //定时器14中断中运行的函数
}_TIMER_ISR;

void Timer3_4_Init(uint8_t timer_num, uint32_t ms, void (*ISR)(void));

void TIM5_Cap_Init(void);
uint32_t getHighVolTime(void); //获取高电平持续时间

void TIM3_CountTime_Init(void);
void startCountRunningTime(void); //开始计时
u32 getRunningTime(void); //获取计时时间



#endif /* __TIMERX_H_ */


