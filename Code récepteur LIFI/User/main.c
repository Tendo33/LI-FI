#include "MyIncludes.h"
#define  dataLen 12000

uint16_t dataCurrentPos=0;
uint16_t dataBuf[dataLen];
int main(void)
{	
	uint16_t recvWorkCounts=0;
	uint8_t j=0,startRecvFlag=0;
	uint16_t i=0,recvData,dataInfo[3]; //dataInfo_Utilis¨¦ pour v¨¦rifier les donn¨¦es de d¨¦but et de fin d'une r¨¦ception de donn¨¦es.
	uint16_t errorCounts=0; //Utilis¨¦ pour enregistrer le nombre de donn¨¦es recues en erreur.
	uint32_t recvTime_us;  //Permet d'enregistrer le temps pass¨¦ ¨¤ la r¨¦ception
	

	TIM3_CountTime_Init(); //Utilis¨¦ pour chronom¨¦trer la r¨¦ception des donn¨¦es
	  
	LdrConfigInit();//Initialisation des broches et de la fonction de capture d'entr¨¦e du capteur photosensible

	

	while(1)
	{
		recvData = receiveData();  //En attente de r¨¦ception d'une donn¨¦e
		
		if((!startRecvFlag) && recvData)  //Recevez d'abord les donn¨¦es de d¨¦but et de fin, puis la longueur totale.
		{
			dataInfo[j] = recvData;
			j++;
			if(j==3)
			{
				j = 0; //Si end + 1 - start = length, pr¨ºt ¨¤ Recevoir des donn¨¦es.
				if((dataInfo[1]+1-dataInfo[0]) == dataInfo[2]) startRecvFlag = 1; 
				else printf("Cette r¨¦ception a ¨¦chou¨¦ ! Veuillez renvoyer les donn¨¦es !\r\n");
			}
		}
		
		if(startRecvFlag) //Commencer ¨¤ recevoir des donn¨¦es
		{
			printf("receiving...\r\n");
			startRecvFlag = 0;
			startCountRunningTime(); //D¨¦marrer l'horloge
			for(i=dataInfo[0];i<(dataInfo[1]+1);i++) //R¨¦ception cyclique des donn¨¦es
			{
				recvData = receiveData();  
				if(recvData==i) dataBuf[dataCurrentPos++] = recvData;
				else 
				{
					if(recvData!=0) 
					{
						dataCurrentPos = recvData-i;
						dataBuf[dataCurrentPos++] = recvData;
						i = recvData;
					}
				}					
			}
			recvTime_us = getRunningTime(); //Terminez la r¨¦ception, puis chronom¨¦trez-la et obtenez l'heure.

			
			printf("R¨¦ception termin¨¦e ! Donn¨¦es en cours de v¨¦rification¡­¡­\r\n");  //Donn¨¦es d'inspection
			dataCurrentPos=0;
			for(i=dataInfo[0];i<(dataInfo[1]+1);i++)
			{
				if(dataBuf[dataCurrentPos]!=i) 
				{
					errorCounts++;
					printf("¡¾err¡¿ ");
				}
				else printf("%d ",dataBuf[dataCurrentPos]);
				dataCurrentPos++;
			}
			recvWorkCounts++;
			
			errorCounts = 0;
			recvData = 0;
			dataCurrentPos=0;
			memset(dataBuf,0,sizeof(dataBuf));
			printf("En attente de r¨¦ception de donn¨¦es¡­¡­\r\n");
		}
	}
}




