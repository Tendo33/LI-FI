
#include "delay.h"

/*******************************************************************************
* Function Name  : delay_us
* Description    : ΢����ʱ��������ʱnus
* Input          : nus:΢����ʱ�ĸ���
* Output         : None
* Return         : None
* Note			 : 216MHz��us��ʱ����
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
* Description    : ������ʱ��������ʱnms
* Input          : nms:������ʱ�ĸ���
* Output         : None
* Return         : None
* Note			 : 216MHz��ms��ʱ����
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
* Description    : ns����ʱ����
* Input          : None
* Output         : None
* Return         : None
* Note			 : 216MHz��ns��ʱ����
*******************************************************************************/
void delay_ns(void)
{
    u8 j; 
	for(j = 0; j < 2; j++);	
}

