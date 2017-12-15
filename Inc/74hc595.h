#ifndef __74hc595_H
#define __74hc595_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"

/* USER CODE BEGIN Includes */
#define CLR1_Pin_H HAL_GPIO_WritePin(CLR1_GPIO_Port, CLR1_Pin, GPIO_PIN_SET);
#define CLR1_Pin_L HAL_GPIO_WritePin(CLR1_GPIO_Port, CLR1_Pin, GPIO_PIN_RESET);
	 
#define Pulse1_Pin_H HAL_GPIO_WritePin(Pulse1_GPIO_Port, Pulse1_Pin, GPIO_PIN_SET);
#define Pulse1_Pin_L HAL_GPIO_WritePin(Pulse1_GPIO_Port, Pulse1_Pin, GPIO_PIN_RESET);	 
	 
#define Latch1_Pin_H HAL_GPIO_WritePin(Latch1_GPIO_Port, Latch1_Pin, GPIO_PIN_SET);
#define Latch1_Pin_L HAL_GPIO_WritePin(Latch1_GPIO_Port, Latch1_Pin, GPIO_PIN_RESET);	 
	 
#define OE1_Pin_H HAL_GPIO_WritePin(OE1_GPIO_Port, OE1_Pin, GPIO_PIN_SET);
#define OE1_Pin_L HAL_GPIO_WritePin(OE1_GPIO_Port, OE1_Pin, GPIO_PIN_RESET);

#define Data1_Pin_H HAL_GPIO_WritePin(Data1_GPIO_Port, Data1_Pin, GPIO_PIN_SET);
#define Data1_Pin_L HAL_GPIO_WritePin(Data1_GPIO_Port, Data1_Pin, GPIO_PIN_RESET);

#define CLR2_Pin_H HAL_GPIO_WritePin(CLR2_GPIO_Port, CLR2_Pin, GPIO_PIN_SET);
#define CLR2_Pin_L HAL_GPIO_WritePin(CLR2_GPIO_Port, CLR2_Pin, GPIO_PIN_RESET);
	 
#define Pulse2_Pin_H HAL_GPIO_WritePin(Pulse2_GPIO_Port, Pulse2_Pin, GPIO_PIN_SET);
#define Pulse2_Pin_L HAL_GPIO_WritePin(Pulse2_GPIO_Port, Pulse2_Pin, GPIO_PIN_RESET);	 
	 
#define Latch2_Pin_H HAL_GPIO_WritePin(Latch2_GPIO_Port, Latch2_Pin, GPIO_PIN_SET);
#define Latch2_Pin_L HAL_GPIO_WritePin(Latch2_GPIO_Port, Latch2_Pin, GPIO_PIN_RESET);	 
	 
#define OE2_Pin_H HAL_GPIO_WritePin(OE2_GPIO_Port, OE2_Pin, GPIO_PIN_SET);
#define OE2_Pin_L HAL_GPIO_WritePin(OE2_GPIO_Port, OE2_Pin, GPIO_PIN_RESET);

#define Data2_Pin_H HAL_GPIO_WritePin(Data2_GPIO_Port, Data2_Pin, GPIO_PIN_SET);
#define Data2_Pin_L HAL_GPIO_WritePin(Data2_GPIO_Port, Data2_Pin, GPIO_PIN_RESET);

extern unsigned char _pin1;
extern unsigned char _pin2;
extern unsigned char _pin3;
extern unsigned char _pin4;
extern unsigned char _pin5;
extern unsigned char _pin6;
extern unsigned char _pin7;
extern unsigned char _pin8;

extern unsigned char _all_off[2];
extern unsigned char _all_on[2];
extern unsigned char _in_on[2];
extern unsigned char _out_on[2];
extern unsigned char pastcmd[2];
void Init_74HC595_1(void);
void Init_74HC595_2(void);	

void SendtoNO1(unsigned char byte);
void SendtoNO2(unsigned char byte);
void Output4NO1(void);
void Output4NO2(void);
void Pastcommand(const unsigned char value1,const unsigned char value2, char i);
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */



/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */
