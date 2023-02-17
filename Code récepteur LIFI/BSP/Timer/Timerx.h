/***************************** (C) COPYRIGHT ************************************
* File Name          : Timerx.h
* Author             : �Ƿ�
* Version            : V1.0
* Date               : 12/03/2015
* Description        : ͨ�ö�ʱ����������ͷ�ļ�
* Note               : ��Ȩ����  �Ͻ�����
********************************************************************************/
#ifndef __TIMERX_H_
#define __TIMERX_H_

#include "stm32f7xx.h"
#include "stm32_types.h"
#include "stm32f7xx_hal.h"  

typedef struct 
{ 
    void (*T1_Handle)(void);  //��ʱ��1�ж������еĺ���
	void (*T2_Handle)(void);  //��ʱ��2�ж������еĺ���
	void (*T3_Handle)(void);  //��ʱ��3�ж������еĺ���
	void (*T4_Handle)(void);  //��ʱ��4�ж������еĺ���
	void (*T5_Handle)(void);  //��ʱ��5�ж������еĺ���
	void (*T6_Handle)(void);  //��ʱ��6�ж������еĺ���
	void (*T7_Handle)(void);  //��ʱ��7�ж������еĺ���
	void (*T8_Handle)(void);  //��ʱ��8�ж������еĺ���
	void (*T9_Handle)(void);  //��ʱ��9�ж������еĺ���
	void (*T10_Handle)(void);  //��ʱ��10�ж������еĺ���
	void (*T11_Handle)(void);  //��ʱ��11�ж������еĺ���
	void (*T12_Handle)(void);  //��ʱ��12�ж������еĺ���
	void (*T13_Handle)(void);  //��ʱ��13�ж������еĺ���
	void (*T14_Handle)(void);  //��ʱ��14�ж������еĺ���
}_TIMER_ISR;

void Timer3_4_Init(uint8_t timer_num, uint32_t ms, void (*ISR)(void));

void TIM5_Cap_Init(void);
uint32_t getHighVolTime(void); //��ȡ�ߵ�ƽ����ʱ��

void TIM3_CountTime_Init(void);
void startCountRunningTime(void); //��ʼ��ʱ
u32 getRunningTime(void); //��ȡ��ʱʱ��



#endif /* __TIMERX_H_ */


