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

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
  // enable clock
	__HAL_RCC_TIM6_CLK_ENABLE();
  // enable interrupt for timer
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
  // set priority
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 15, 0);
}
