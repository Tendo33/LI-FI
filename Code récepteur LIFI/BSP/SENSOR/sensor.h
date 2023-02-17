#ifndef __SENSOR_H
#define __SENSOR_H
#include "MyIncludes.h"


#define LDR (GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)==1)

void LdrConfigInit(void); //初始化光敏模块引脚和接收参数
uint16_t receiveData(void); //接收一份数据
uint8_t ifStartSignal(void); //判断是否为起始信号
void configRecvParameter(uint32_t p1,uint32_t p2,uint32_t p3,uint32_t p4,uint32_t p5);//配置接收相关参数
void lookUpCurrentParameter(void); //查看当前接收参数

#endif
