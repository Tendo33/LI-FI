
#include "delay.h"

/*******************************************************************************
* Function Name  : delay_us
* Description    : 
* Input          : 
* Output         : None
* Return         : None
* Note			 : 
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
* Description    : 
* Input          : 
* Output         : None
* Return         : None
* Note			 : 
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
* Description    : 
* Input          : None
* Output         : None
* Return         : None

*******************************************************************************/
void delay_ns(void)
{
    u8 j; 
	for(j = 0; j < 2; j++);	
}

