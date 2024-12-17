/*
 * it.c
 *
 *  Created on: Oct 12, 2024
 *      Author: Asus
 */

#include "it.h"
#include "stm32f4xx_hal.h"



void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}
