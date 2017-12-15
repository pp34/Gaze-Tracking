#ifndef __led_H
#define __led_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"

/* USER CODE BEGIN Includes */
#define Led1_Off  HAL_GPIO_WritePin(Circle_In_GPIO_Port, Circle_In_Pin, GPIO_PIN_SET);
#define Led1_On HAL_GPIO_WritePin(Circle_In_GPIO_Port, Circle_In_Pin, GPIO_PIN_RESET);
	 
#define Led2_Off  HAL_GPIO_WritePin(Circle_Out_GPIO_Port, Circle_Out_Pin, GPIO_PIN_SET);
#define Led2_On HAL_GPIO_WritePin(Circle_Out_GPIO_Port, Circle_Out_Pin, GPIO_PIN_RESET);	

void Led_Init(void);	 
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */



/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */
