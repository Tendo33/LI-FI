
#include "Timerx.h"

u8  TIM5CH1_CAPTURE_STA = 0;	//¨¦tat de la capture d'entr¨¦e		    				
u32	TIM5CH1_CAPTURE_VAL=0;	//valeur de la capture d'entr¨¦e

u8  TIM3_CountTime_STA = 0;	//Statut de l'horloge
u8 counts = 0;   //Nombre de d¨¦passements de d¨¦lais
#define TIM3_ARR 0xFFFF 
#define TIM3_PSC 7199  //Fr¨¦quence de comptage 10Khz, 100us pour un compte


_TIMER_ISR Timer_ISR;
TIM_HandleTypeDef Tim3_Handle; 


/*******************************************************************************
* Function Name  : Timer3_4_Init
* Description    : 
* Input          : None
* Output         : None
* Return         : None
* Note		
				   TIM3CLK = 2 * PCLK1  
				   PCLK1 = HCLK / 4 
				   => TIM3CLK = HCLK / 2 = SystemCoreClock /2
				   To get TIM3 counter clock at 10 KHz, the Prescaler is computed as following:
				   Prescaler = (TIM3CLK / TIM3 counter clock) - 1
				   Prescaler = ((SystemCoreClock /2) /10 KHz) - 1
*******************************************************************************/

void TIM3_CountTime_Init() //Nombre maximal d'unit¨¦s : 65536
{
  
	__HAL_RCC_TIM3_CLK_ENABLE(); //Validation de l'horloge
	
	//Initialisation du timer TIM3
	Tim3_Handle.Init.Period = TIM3_ARR; 	
	Tim3_Handle.Init.Prescaler = TIM3_PSC; 
	Tim3_Handle.Init.ClockDivision = 0; //TDTS = Tck_tim
	Tim3_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;  
	HAL_TIM_Base_Init(&Tim3_Handle);        
	HAL_TIM_Base_Start_IT(&Tim3_Handle);    
	
 
	//Configuration des interruptions NVIC
		HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
					 
}
void TIM3_IRQHandler(void)   //Interruption TIM3
{
	HAL_TIM_IRQHandler(&Tim3_Handle);
	
		if((TIM3_CountTime_STA)==1) 
		{
			counts++;
		}
	
}
//D¨¦marrer le compteur
void startCountRunningTime()
{
	__HAL_RCC_TIM3_CLK_ENABLE();
	
	TIM3_CountTime_STA = 1;
}

u32 getRunningTime()
{
	u32 times_us;
	times_us = ((counts*65536)+TIM3->CNT)*100;
	TIM3_CountTime_STA = 0;
	TIM3->CNT = 0;
	counts = 0;
	__HAL_RCC_TIM3_CLK_DISABLE();
	return times_us;
}
//Calcul du temps de haut niveau
uint32_t getHighVolTime(void)
{
	uint32_t time_us = 0;
  time_us  = TIM5CH1_CAPTURE_STA&0X3F; //Nombre de d¨¦bordements de la minuterie
	if(time_us) time_us *= 65536;    //Temps total de d¨¦bordement
	time_us += TIM5CH1_CAPTURE_VAL;//Obtenez le temps total de haut niveau
	TIM5CH1_CAPTURE_STA = 0;//Tourner sur la capture suivante
	return time_us; 
}

#define TIM5_ARR 0xFFFF //max 65536us
#define TIM5_PSC 71  

	GPIO_InitTypeDef   GPIO_InitStruct;
	TIM_HandleTypeDef  Tim5_Handle; 
	TIM_IC_InitTypeDef   sICConfig;
    

void TIM5_Cap_Init()
{	 
	//Configuration de la capture de l'entr¨¦e du canal 1 de l'horloge 5 
	//pour la lecture du temps de niveau haut.



	__HAL_RCC_TIM5_CLK_ENABLE();;
	
	__GPIOA_CLK_ENABLE(); 
	
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT ;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
	HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);
	
	
	// Initialise le timer 5 TIM5
	Tim5_Handle.Instance = TIM5; 	
	Tim5_Handle.Init.Period = TIM5_ARR; 
	Tim5_Handle.Init.Prescaler = TIM5_PSC; 	 
	Tim5_Handle.Init.ClockDivision = 0;  //TDTS = Tck_tim
	Tim5_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;  
	Tim5_Handle.Init.RepetitionCounter = 0;
	HAL_TIM_Base_Init(&Tim5_Handle);                    
	HAL_TIM_Base_Start_IT(&Tim5_Handle);          
  

	

	sICConfig.ICPolarity  = TIM_ICPOLARITY_RISING;       //Capture du front montant
	sICConfig.ICSelection = TIM_ICSELECTION_DIRECTTI;   
	sICConfig.ICPrescaler = TIM_ICPSC_DIV1;             
	sICConfig.ICFilter    = 0x00;                       
	HAL_TIM_IC_ConfigChannel(&Tim5_Handle, &sICConfig, TIM_CHANNEL_1);
	// D¨¦marrer la capture d'entr¨¦e
	HAL_TIM_IC_Start_IT(&Tim5_Handle, TIM_CHANNEL_1);
	__HAL_TIM_ENABLE_IT(&Tim5_Handle,TIM_IT_UPDATE);
	
	HAL_NVIC_SetPriority(TIM5_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(TIM5_IRQn);
	
}
 


/*******************************************************************************
* Function Name  : TIM5_IRQHandler
* Description    : TIMER5
* Input          : None
* Output         : None
* Return         : None
* Note			 : None
*******************************************************************************/



//Fonction de service d'interruption du Timer 5
void TIM5_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&Tim5_Handle);
}
 


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	
	if((TIM5CH1_CAPTURE_STA&0X80)==0)//Pas encore captur¨¦ avec succ¨¨s
	{
			if(TIM5CH1_CAPTURE_STA&0X40)//Un niveau ¨¦lev¨¦ a ¨¦t¨¦ saisi
			{ 
				if((TIM5CH1_CAPTURE_STA&0X3F)==0X3F)//Le niveau ¨¦lev¨¦ est trop long
				{
					TIM5CH1_CAPTURE_STA|=0X80;		//L'¨¦tiquette a ¨¦t¨¦ captur¨¦e avec succ¨¨s une fois
					TIM5CH1_CAPTURE_VAL=0XFFFFFFFF;
				}else TIM5CH1_CAPTURE_STA++;
			}	 
	}		
}



void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)//Ex¨¦cut¨¦ lorsque l'interruption de capture se produit
{
	if((TIM5CH1_CAPTURE_STA&0X80)==0)//Pas encore captur¨¦ avec succ¨¨s
	{
		if(TIM5CH1_CAPTURE_STA&0X40)		//captur¨¦ sur un bord descendant		
			{	  			
				TIM5CH1_CAPTURE_STA|=0X80;		
                TIM5CH1_CAPTURE_VAL=HAL_TIM_ReadCapturedValue(&Tim5_Handle,TIM_CHANNEL_1);
                TIM_RESET_CAPTUREPOLARITY(&Tim5_Handle,TIM_CHANNEL_1);  
                TIM_SET_CAPTUREPOLARITY(&Tim5_Handle,TIM_CHANNEL_1,TIM_ICPOLARITY_RISING);
			}else  								
			{
				TIM5CH1_CAPTURE_STA=0;			//Vider le site
				TIM5CH1_CAPTURE_VAL=0;
				TIM5CH1_CAPTURE_STA|=0X40;		
				__HAL_TIM_DISABLE(&Tim5_Handle);       
				__HAL_TIM_SET_COUNTER(&Tim5_Handle,0);
				TIM_RESET_CAPTUREPOLARITY(&Tim5_Handle,TIM_CHANNEL_1);  
				TIM_SET_CAPTUREPOLARITY(&Tim5_Handle,TIM_CHANNEL_1,TIM_ICPOLARITY_FALLING);
				__HAL_TIM_ENABLE(&Tim5_Handle);
			}		    
	}	
}
