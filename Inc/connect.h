/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __connect_H
#define __connect_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"
#include "usart.h"
#include "usartidle.h"
#include "kmp.h"
#include "74hc595.h"
#include "led.h"
/* USER CODE BEGIN Private defines */
#define CMDLEN 2	

extern uint8_t pp[2];
extern uint8_t command[2];	 
	 
extern char CMD_FLAG;

extern uint8_t _A1[CMDLEN];
extern uint8_t _A2[CMDLEN];
extern uint8_t _A3[CMDLEN];
extern uint8_t _A4[CMDLEN];
	 
extern uint8_t _B1[CMDLEN];
extern uint8_t _B2[CMDLEN];
extern uint8_t _B3[CMDLEN];
extern uint8_t _B4[CMDLEN];
extern uint8_t _B5[CMDLEN];
extern uint8_t _B6[CMDLEN];
extern uint8_t _B7[CMDLEN];
extern uint8_t _B8[CMDLEN];	 	 
/* USER CODE BEGIN Prototypes */
void Ack(const uint8_t ppstr[], const uint8_t cmdstr[]);
void data_transfer(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif 
