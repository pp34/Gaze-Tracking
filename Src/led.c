#include "led.h"
#include "delay.h"

void Led_Init(void){
	
	char i;
	Led1_Off;
	Led2_Off;
	for(i=0; i<3; i++){
		Led1_On;
		Led2_On;
		delay_ms(500);
		Led1_Off;
		Led2_Off;
		delay_ms(500);
	}
	Led1_Off;
	Led2_Off;
}

