#include "74hc595.h"
#include "delay.h"

typedef unsigned char uchar;
typedef unsigned int uint;

unsigned char pastcmd[2] = {0x00, 0x00};

unsigned char _all_off[2] = {0x00, 0x00};
unsigned char _all_on[2]  = {0xff, 0xff};
unsigned char _in_on[2]   = {0x0f, 0x01};
unsigned char _out_on[2]  = {0xf0, 0xfe};

unsigned char _pin1 = 0x01;
unsigned char _pin2 = 0x02;
unsigned char _pin3 = 0x04;
unsigned char _pin4 = 0x08;
unsigned char _pin5 = 0x10;
unsigned char _pin6 = 0x20;
unsigned char _pin7 = 0x40;
unsigned char _pin8 = 0x80;

/*	GPIOA ---> NO.1
 *	all output is low  
 *	clear all register
 */
void Init_74HC595_1(void){
	
	HAL_GPIO_WritePin(GPIOA, CLR1_Pin|Pulse1_Pin|Latch1_Pin|OE1_Pin |Data1_Pin, 
	GPIO_PIN_RESET);
	delay_ms(100);
	CLR1_Pin_H;
}

/*	GPIOB ---> NO.2
 *	all output is low  
 *	clear all register
 */
void Init_74HC595_2(void){
	
	HAL_GPIO_WritePin(GPIOB, CLR2_Pin|Pulse2_Pin|Latch2_Pin|OE2_Pin|Data2_Pin, 
	GPIO_PIN_RESET);
	delay_ms(100);
	CLR2_Pin_H;
}

/*	Send sth. ---> NO.1's shift register
 *	control chip's NO.11 pin (SHCP)  
 */
void SendtoNO1(unsigned char byte){
	
	char i;
	for(i=8; i>0; i--){
		if(((byte>>(i-1))&0x01)==0x01){	
			Data1_Pin_H;
		}
		else if(((byte>>(i-1))&0x01)==0x00){					
			Data1_Pin_L;
		}
		else;
		Pulse1_Pin_H;
		delay_us(1);
		Pulse1_Pin_L;
		delay_us(1);
	}
	Output4NO1();
}
	

/*	Send sth. ---> NO.2's shift register
 *	control chip's NO.11 pin (SHCP)  
 */	
void SendtoNO2(unsigned char byte){
	
	char i;
	for(i=8; i>0; i--){
		if(((byte>>(i-1))&0x01)==0x01){	
			Data2_Pin_H;
		}
		else if(((byte>>(i-1))&0x01)==0x00){					
			Data2_Pin_L;
		}
		else;
		Pulse2_Pin_H;
		delay_us(1);
		Pulse2_Pin_L;
		delay_us(1);
	}
	Output4NO2();
}

/*	Output Qxs. ---> NO.1's latch register
 *	control chip's NO.12 pin (STCP)  
 */
void Output4NO1(void){
	
	Latch1_Pin_L;
	delay_us(1);
	Latch1_Pin_H;
	delay_us(1);
	Latch1_Pin_L;
}
	
/*	Output Qxs. ---> NO.2's latch register
 *	control chip's NO.12 pin (STCP)  
 */	
void Output4NO2(void){
	
	Latch2_Pin_L;
	delay_us(1);
	Latch2_Pin_H;
	delay_us(1);
	Latch2_Pin_L;
}	

void Pastcommand(const unsigned char value1,const unsigned char value2, char i){
	if(i==0){
		pastcmd[0] = value1;
		pastcmd[1] = value2;
	}
	else{
		pastcmd[0] = pastcmd[0]| value1;
		pastcmd[1] = pastcmd[1]| value2;
	}
}
