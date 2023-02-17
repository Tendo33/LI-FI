#include "sensor.h"
#include "delay.h"
//#include "usart.h"

#define DATABIT 14

uint32_t startSignalHold_time=600; //Dur¨¦e du signal de d¨¦marrage haut
uint32_t start_Wait_time=300;  //Dur¨¦e du signal initial bas
uint32_t data_0_Hold_time=800; // Dur¨¦e du signal 0  haut
uint32_t data_0_Wait_time=300;// Dur¨¦e du signal 0  bas
uint32_t data_1_Hold_time=1000;// Dur¨¦e du signal 1 haut
uint32_t data_1_Wait_time=300;//Dur¨¦e du signal 1 bas

timeParameter T = {0,0,0,0,0,0}; //Pour les sections retard¨¦es

void Flash(void)
{	
	HAL_GPIO_TogglePin(GPIOI,GPIO_PIN_2);
	delay_ms(200000000);
}



//Envoyer une donn¨¦e(Binaire)
void emitData(uint16_t data)
{
	u8 j;
	u16 tmp;
	emitStartSignal();
	for(j=DATABIT;j>0;j--) //Repr¨¦sentation des donn¨¦es jusqu'¨¤ 65535
	{
		tmp = (data)&(1<<(j-1)); //Envoyer du haut vers le bas
		if(tmp) {emitData_1();}
		else {emitData_0();}
	}
}

//Configurer les param¨¨tres d'envoi
void configEmitParameter(u32 p1,u32 p2,u32 p3,u32 p4,u32 p5,u32 p6)
{
	startSignalHold_time = p1;
	data_0_Hold_time = p2;
	data_1_Hold_time = p3;
	start_Wait_time = p4;
	data_0_Wait_time = p5; 
	data_1_Wait_time = p6; 
}

//Transmettre un signal de d¨¦part avant de transmettre une donn¨¦e
void emitStartSignal()
{
	LED1 ; 
	emitProcessDelay_us(startSignalHold_time);
	LED0 ; 
	emitProcessDelay_us(start_Wait_time);
	
}


//Transmettre 1 signal
void emitData_1()
{
	LED1 ; 
	emitProcessDelay_us(data_1_Hold_time);
	LED0 ; 
	emitProcessDelay_us(data_1_Wait_time);
}


//Transmettre 0 signal
void emitData_0()
{
	LED1 ; 
	emitProcessDelay_us(data_0_Hold_time);
	LED0 ; 
	emitProcessDelay_us(data_0_Wait_time);
}


//Envoyer le signal de fin
void emitEndSignal()
{
	LED1 ; 
	emitProcessDelay_us(data_0_Hold_time);
	emitProcessDelay_us(data_0_Hold_time);
}

void lookUpCurrentParameter() // visualiser les param¨¨tres de lancement actuels
{
	printf("HoldTime:     start: %d  signal 0: %d  signal 1: %d\r\nWaitTime:    start: %d  signal 0 : %d  signal 1 : %d\r\n",\
				startSignalHold_time,data_0_Hold_time,data_1_Hold_time,start_Wait_time,data_0_Wait_time,data_1_Wait_time);
}

//Le nombre d'us entrants est pris en charge jusqu'¨¤ un d¨¦lai maximum de 10s ¨¤ la fois, c'est-¨¤-dire 10000000us.
void emitProcessDelay_us(uint32_t time) 
{
	uint8_t i;
	if(time<=23000) delay_us(time); //D¨¦lai direct de quelques millisecondes
	else if(time>23000 && time<1000000) //Conversion en millisecondes
	{
		T._ms = time/1000.0;
		T._1ms = (int)T._ms; //Nombre de 1ms
		T._us = (T._ms-T._1ms)*1000; //Valeur en millisecondes
		delay_ms(T._1ms);
		if(T._us) delay_us(T._us);
	}
	else if(time >= 1000000) //Plus de 1s
	{
		T._s = time/1000000.0; 
		T._1s = (int)T._s; //Valeur en millisecondes
		T._ms = (T._s-T._1s)*1000; //La valeur de ms est certainement inf¨¦rieure ¨¤ 1000
		for(i=0;i<T._1s;i++) delay_ms(1000);
		if(T._ms) delay_ms(T._ms);
	}
}
