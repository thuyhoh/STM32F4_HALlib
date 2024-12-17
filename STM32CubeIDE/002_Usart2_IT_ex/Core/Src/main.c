/*
 * main.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Asus
 */

#include "stm32f4xx_hal.h"
#include "main.h"
#include "string.h"
#include "stdint.h"

void SystemClockConfig(void);
void Uart2_Init(void);
void Error_Handler(void);
#define TRUE 1
#define FALSE 0

UART_HandleTypeDef huart2;
uint8_t *user_char = "The application is run \n";
uint8_t *rxBuffer;
uint8_t receiveData;
uint16_t count = 0;
uint8_t receiptionState =FALSE;
int main(void)
{
	HAL_Init();
	SystemClockConfig();
	Uart2_Init();
	uint16_t lenData =  strlen((char*)user_char);
	if(HAL_UART_Transmit(&huart2, user_char,lenData, HAL_MAX_DELAY) != HAL_OK)
	{
		Error_Handler();
	}
	while(receiptionState != TRUE)
		HAL_UART_Receive_IT(&huart2, &receiveData, 1);
	while(1)
	{

	}
//	return 0;
}

void SystemClockConfig(void)
{

}

void Uart2_Init(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;
	if(HAL_UART_Init(&huart2) != HAL_OK)
	{
		// error
		Error_Handler();
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(receiveData == '\r')
  {
	  rxBuffer[count++] = '\r';
	  receiptionState = TRUE;
	  HAL_UART_Transmit(&huart2, user_char, sizeof(user_char), HAL_MAX_DELAY);
  }else
  {
	  rxBuffer[count++] = receiveData;
  }
}

void Error_Handler(void)
{
	while(1);
}


