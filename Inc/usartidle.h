/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __usartidle_H
#define __usartidle_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"
#include "usart.h"
#include "connect.h"
/* USER CODE BEGIN Private defines */
typedef struct {
	UART_HandleTypeDef * huart;
	DMA_HandleTypeDef * hdma_usart_rx;
	DMA_HandleTypeDef * hdma_usart_tx;
	uint8_t rxbuf[4];
}USARTx_IDLE;

extern USARTx_IDLE usart1_idle;
extern char TX_FLAG;

void UsartIDLE_Init(UART_HandleTypeDef * huart,
										DMA_HandleTypeDef * hdma_usart_rx, 
										DMA_HandleTypeDef * hdma_usart_tx);
void USARTx_IDLEtoRX(void);
/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif 
