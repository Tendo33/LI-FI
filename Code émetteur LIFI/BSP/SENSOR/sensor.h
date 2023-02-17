#ifndef __SENSOR_H
#define __SENSOR_H
#include "stm32_system.h"

typedef struct
{
	float _s; 
	float _ms; 
	uint16_t _us; 
	uint8_t _1s; 
	uint16_t _1ms;
	uint16_t _1us;
}timeParameter;

#define LED1 HAL_GPIO_WritePin(GPIOI,GPIO_PIN_2,GPIO_PIN_SET);
#define LED0 HAL_GPIO_WritePin(GPIOI,GPIO_PIN_2,GPIO_PIN_RESET);

void LedConfigInit(void); 
void emitData(uint16_t data); 
void configEmitParameter(u32 p1,u32 p2,u32 p3,u32 p4,u32 p5,u32 p6); 
void emitProcessDelay_us(uint32_t time); 
void emitStartSignal(void); 
void emitEndSignal(void); 
void emitData_1(void); 
void emitData_0(void); 
void lookUpCurrentParameter(void);
void Flash(void);

#endif

