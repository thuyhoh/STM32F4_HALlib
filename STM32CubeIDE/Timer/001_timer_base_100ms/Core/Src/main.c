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
void TIM6_Init(void);
void Error_Handler(void);
void GPIO_Init(void);

TIM_HandleTypeDef htim6;

int main(void)
{
	HAL_Init();
	SystemClockConfig();

	GPIO_Init();
	TIM6_Init();
	HAL_TIM_Base_Start(&htim6);

	while(1)
	{
		while( !(htim6.Instance->SR & (1<<0)) )
		{
			htim6.Instance->SR &= ~(1<<0);
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
		}
	}
//	return 0;
}

void SystemClockConfig(void)
{

}

void GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_Init;
	__HAL_RCC_GPIOD_CLK_ENABLE();
	GPIO_Init.Pin = GPIO_PIN_15;
	GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull = GPIO_NOPULL;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &GPIO_Init);
}

void TIM6_Init(void)
{
	htim6.Instance = TIM6;
	htim6.Init.Period = 64000 - 1;
	htim6.Init.Prescaler = 24;
	htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
	if(HAL_TIM_Base_Init(&htim6) != HAL_OK)
	{
		Error_Handler();
	}
}

void Error_Handler(void)
{
	while(1);
}


