/*
 * it.c
 *
 *  Created on: Oct 12, 2024
 *      Author: Asus
 */

#include "it.h"
#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef htim6;

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}

void TIM6_DAC_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&htim6);
}
