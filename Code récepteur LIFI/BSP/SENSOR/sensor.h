#ifndef __SENSOR_H
#define __SENSOR_H
#include "MyIncludes.h"


#define LDR (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==1)

void LdrConfigInit(void); //��ʼ������ģ�����źͽ��ղ���
uint16_t receiveData(void); //����һ������
uint8_t ifStartSignal(void); //�ж��Ƿ�Ϊ��ʼ�ź�
void configRecvParameter(uint32_t p1,uint32_t p2,uint32_t p3,uint32_t p4,uint32_t p5);//���ý�����ز���
void lookUpCurrentParameter(void); //�鿴��ǰ���ղ���

#endif
