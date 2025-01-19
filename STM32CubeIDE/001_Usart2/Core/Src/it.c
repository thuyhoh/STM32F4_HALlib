/*
 * it.c
 *
 *  Created on: Oct 12, 2024
 *      Author: Asus
 */

#include "it.h"
#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart2;

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(void)
{
	HAL_UART_IRQHandler(&huart2);
}

