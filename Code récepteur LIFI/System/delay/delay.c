
#include "delay.h"

/*******************************************************************************
* Function Name  : delay_us
* Description    : 微秒延时函数，延时nus
* Input          : nus:微秒延时的个数
* Output         : None
* Return         : None
* Note			 : 216MHz下us延时函数
*******************************************************************************/
void delay_us(u32 nus)    
{ 
	u32 i,j; 
	for(i = 0; i < nus; i++)
	{ 
		for( j = 0; j < 110; j++);
	}
}

/*******************************************************************************
* Function Name  : delay_ms
* Description    : 毫秒延时函数，延时nms
* Input          : nms:毫秒延时的个数
* Output         : None
* Return         : None
* Note			 : 216MHz下ms延时函数
*******************************************************************************/
void delay_ms(u32 ms)    
{ 
	u32 i; 
	for(i = 0; i < ms; i++)
	{ 
		delay_us(1000);
	}
}

/*******************************************************************************
* Function Name  : delay_ns
* Description    : ns级延时函数
* Input          : None
* Output         : None
* Return         : None
* Note			 : 216MHz下ns延时函数
*******************************************************************************/
void delay_ns(void)
{
    u8 j; 
	for(j = 0; j < 2; j++);	
}

