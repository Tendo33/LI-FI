#include "sensor.h"

#include "Timerx.h"

#define DATABIT 14

extern u8  TIM5CH1_CAPTURE_STA;

uint32_t startSignal_time;
uint32_t data_0_time;
uint32_t data_1_time;
uint32_t upperAddValue;
uint32_t lowerDecValue;

uint32_t start_upperBound,start_lowerBound;
uint32_t data_0_upperBound,data_1_upperBound,data_0_lowerBound,data_1_lowerBound;  

void LdrConfigInit()
{
	TIM5_Cap_Init(); 
	startSignal_time = 600; 
	data_0_time = 800; 
	data_1_time = 1000; 
	upperAddValue = 100; 
	lowerDecValue = 100;
	
	start_upperBound  = startSignal_time+upperAddValue;
	start_lowerBound  = startSignal_time-lowerDecValue;
	data_0_upperBound = data_0_time+upperAddValue;
	data_0_lowerBound = data_0_time-lowerDecValue;
	data_1_upperBound = data_1_time+upperAddValue;
	data_1_lowerBound = data_1_time-lowerDecValue;
}

uint16_t receiveData()
{
	uint32_t highVolTime = 0;
	short int dataBit = DATABIT;
	uint8_t dataFlag = 0;
	uint16_t data = 0;
	while(1)
	{
		if(TIM5CH1_CAPTURE_STA&0X80) //Capture r¨¦ussie du signal de d¨¦part
		{
			highVolTime = getHighVolTime();
			if((highVolTime<=start_upperBound) && (highVolTime>=start_lowerBound)) //Signal de premier d¨¦marrage correct
			{
				while(1)
				{
					if(TIM5CH1_CAPTURE_STA&0X80) 
					{
						highVolTime = getHighVolTime();
						if((highVolTime>=data_0_lowerBound) && (highVolTime<=data_0_upperBound))
						{
							data &= ~(1<<(dataBit-1));
							dataBit--;
							if(dataBit==0)
							{
								dataFlag = 1;break;
							}
						}
						else if((highVolTime>=data_1_lowerBound) && (highVolTime<=data_1_upperBound))
						{
							data |= (1<<(dataBit-1));
							dataBit--;
							if(dataBit==0)
							{
								dataFlag = 1;break;
							}
						}
						else {printf("dataError:highVolTime:%d\r\n",highVolTime);break;}
					}
				}
				break;
			}
			else printf("startError:highVolTime:%d\r\n",highVolTime);
		}
	}
	if(dataFlag) return data;
	else return 0;
}

//pour configurer les param¨¨tres li¨¦s ¨¤ la r¨¦ception.
void configRecvParameter(uint32_t p1,uint32_t p2,uint32_t p3,uint32_t p4,uint32_t p5)
{
		startSignal_time = p1; 
		data_0_time = p2;  
	  data_1_time = p3;  
		upperAddValue = p4;  
		lowerDecValue = p5; 
	
		start_upperBound  = startSignal_time+upperAddValue;
		start_lowerBound  = startSignal_time-lowerDecValue;
		data_0_upperBound = data_0_time+upperAddValue;
		data_0_lowerBound = data_0_time-lowerDecValue;
		data_1_upperBound = data_1_time+upperAddValue;
		data_1_lowerBound = data_1_time-lowerDecValue;
}

void lookUpCurrentParameter() //Visualiser les param¨¨tres de lancement actuels
{
	printf("HoldTime:     start: %d  0 signal: %d  1 signal: %d\r\nWaitTime:    upper: %d  lower: %d\r\n", \
				startSignal_time,data_0_time,data_1_time, \
				upperAddValue,lowerDecValue);
}
