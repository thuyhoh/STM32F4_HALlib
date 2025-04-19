/*
 * msp.c
 *
 *  Created on: Oct 6, 2024
 *      Author: Asus
 */
#include "stm32f4xx_hal.h"

void HAL_MspInit(void)
{
	// set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	// enable system exception
	SCB->SHCSR |= (0x7 << 16);

	// set pr
	HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef GPIOInit;
	 if(huart->Instance == USART2)
	 {
		  // enable clock
		  __HAL_RCC_USART2_CLK_ENABLE();
		  __HAL_RCC_GPIOA_CLK_ENABLE();
		  // Configure pin
		  GPIOInit.Pin = GPIO_PIN_2;
		  GPIOInit.Mode = GPIO_MODE_AF_PP;
		  GPIOInit.Pull = GPIO_PULLUP;
		  GPIOInit.Speed = GPIO_SPEED_FREQ_LOW;
		  GPIOInit.Alternate = GPIO_AF7_USART2;
		  HAL_GPIO_Init(GPIOA, &GPIOInit); // -> USART2 Tx

		  GPIOInit.Pin = GPIO_PIN_3;
		  HAL_GPIO_Init(GPIOA, &GPIOInit); // -> USART2 Rx

		  // enable interrupt
		  HAL_NVIC_EnableIRQ(USART2_IRQn);
		  HAL_NVIC_SetPriority(USART2_IRQn, 15, 0);

	  }
}
