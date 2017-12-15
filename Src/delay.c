#include "delay.h"
#define u8  uint8_t  
#define u16 uint16_t 
#define u32 uint32_t 

			   
    								   
void delay_us(uint32_t nus){     
	uint32_t ticks;     
	uint32_t told,tnow,tcnt=0;     
	uint32_t reload=SysTick->LOAD;	
	ticks=nus*72;
	tcnt=0;     
	told=SysTick->VAL;  
	while(1){         
		tnow=SysTick->VAL;         
		if(tnow!=told){             
			if(tnow<told)
				tcnt+=told-tnow;           
			else 
				tcnt+=reload-tnow+told;             
			told=tnow;             
			if(tcnt>=ticks)break;			        
			}       
	};  
} 

void delay_ms(u16 nms)
{	 		  	  
	uint32_t ticks;     
	uint32_t told,tnow,tcnt=0;     
	uint32_t reload=SysTick->LOAD;	
	ticks=nms*72000;
	tcnt=0;     
	told=SysTick->VAL;
	while(1){         
		tnow=SysTick->VAL;         
		if(tnow!=told){             
			if(tnow<told)
				tcnt+=told-tnow;        
			else 
				tcnt+=reload-tnow+told;             
			told=tnow;             
			if(tcnt>=ticks)break;		
			}       
	};  	    
} 


