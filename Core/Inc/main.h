/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define IU_Pin GPIO_PIN_0
#define IU_GPIO_Port GPIOC
#define IV_Pin GPIO_PIN_1
#define IV_GPIO_Port GPIOC
#define IU2_Pin GPIO_PIN_2
#define IU2_GPIO_Port GPIOC
#define IV2_Pin GPIO_PIN_3
#define IV2_GPIO_Port GPIOC
#define VCC_MOTOR_Pin GPIO_PIN_3
#define VCC_MOTOR_GPIO_Port GPIOA
#define CH1N_Pin GPIO_PIN_8
#define CH1N_GPIO_Port GPIOE
#define CH1_Pin GPIO_PIN_9
#define CH1_GPIO_Port GPIOE
#define CH2N_Pin GPIO_PIN_10
#define CH2N_GPIO_Port GPIOE
#define CH2_Pin GPIO_PIN_11
#define CH2_GPIO_Port GPIOE
#define CH3N_Pin GPIO_PIN_12
#define CH3N_GPIO_Port GPIOE
#define CH3_Pin GPIO_PIN_13
#define CH3_GPIO_Port GPIOE
#define LED_Pin GPIO_PIN_14
#define LED_GPIO_Port GPIOE
#define U3TX_Pin GPIO_PIN_8
#define U3TX_GPIO_Port GPIOD
#define U3RX_Pin GPIO_PIN_9
#define U3RX_GPIO_Port GPIOD
#define U1TX_Pin GPIO_PIN_9
#define U1TX_GPIO_Port GPIOA
#define U1RX_Pin GPIO_PIN_10
#define U1RX_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
