#include "usartidle.h"

USARTx_IDLE usart1_idle;
char TX_FLAG=0;

void UsartIDLE_Init(UART_HandleTypeDef * huart,
										DMA_HandleTypeDef * hdma_usart_rx, 
										DMA_HandleTypeDef * hdma_usart_tx){
  usart1_idle.huart = huart;
  usart1_idle.hdma_usart_rx = hdma_usart_rx;
  usart1_idle.hdma_usart_tx = hdma_usart_tx;
//	__HAL_UART_ENABLE_IT(huart, UART_IT_RXNE);	
//	__HAL_UART_ENABLE_IT(huart, UART_IT_PE);									
  __HAL_UART_ENABLE_IT(huart, UART_IT_IDLE);
  HAL_UART_Receive_DMA(huart, usart1_idle.rxbuf,
								sizeof(usart1_idle.rxbuf) / sizeof(usart1_idle.rxbuf[0])
								);
}



void USARTx_IDLEtoRX(void) {
	
  uint32_t tmp1 = 0, tmp2 = 0;
	//	空闲中断标志位是否置位
  tmp1 = __HAL_UART_GET_FLAG(usart1_idle.huart, UART_FLAG_IDLE);
  //	检查空闲中断源，中断是否置位
	tmp2 = __HAL_UART_GET_IT_SOURCE(usart1_idle.huart, UART_IT_IDLE);
	//	都被置位，表示空闲发生了
  if ((tmp1 != RESET) && (tmp2 != RESET)) {
		//	清除标志位先
    __HAL_UART_CLEAR_IDLEFLAG(usart1_idle.huart); 
		// 挂起 the DMA transfer（使能了DMA的情况）
    HAL_DMA_Abort(usart1_idle.hdma_usart_rx);
		//	检查有没有发送处理，有就等待，没有就ready
    if (usart1_idle.huart->gState == HAL_UART_STATE_BUSY_TX_RX) {
      usart1_idle.huart->gState = HAL_UART_STATE_BUSY_TX;
    } 
    if(usart1_idle.huart->RxState == HAL_UART_STATE_BUSY_RX) {
      usart1_idle.huart->RxState = HAL_UART_STATE_READY;
    }
		TX_FLAG = 1;
  }
	//	重新使能DMA接收
	//	读取数据，读数据的同时清空了接收中断标志;
  HAL_UART_Receive_DMA(usart1_idle.huart,usart1_idle.rxbuf,4);
}



