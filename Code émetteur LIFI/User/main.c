#include "Myincludes.h"
#include "delay.h"
#include "sensor.h"


#define RECV_LENGTH	100		//Longueur du tampon de r¨¦ception
#define SEND_LENGTH	100	  	//Longueur du tampon d'envoi

u8 test_txbuf[100];
u8 test_rxbuf[100];
u8 tx_index = 0;
u8 send_len;                  //Longueur d'envoi
u8 recv_len;                  //Longueur de r¨¦ception
u8 recv_timeout = 0;              //timeout
u8 recv_complete = 0;             //R¨¦ception termin¨¦e

//Transmission de donn¨¦es en continu
void emitSeriesData(uint16_t start,uint16_t end)
{
	uint16_t i;
	uint16_t len=end+1;
	
	if((start>0) && (end>start))
	{
		
		emitData(start); 
		emitData(end); 
		emitData((end+1-start)); //Envoyez d'abord l'information de ce bloc de donn¨¦es
		delay_ms(10);
		
		for(i=start;i<len;i++) 
		{
			emitData(i); //D¨¦but de l'envoi cyclique, en commen?ant par le bit de donn¨¦es de d¨¦part.
			
		}
		LED1;//Fin de l'envoi par d¨¦faut LED est lumineux
		
	}
}


int main(void)
{	
	System_Init();
	  
	LED_Init();//Initialisation des broches de la source lumineuse
	
	LED1;  //Source lumineuse par d¨¦faut allum¨¦e avant le lancement
	
	
	while(1)
	{
		
		emitSeriesData(1,100);//Signaux transmis
		
	}
}
