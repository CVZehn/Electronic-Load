/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
#include "stm32f1xx_hal.h"
#include "stm32f1xx_ll_dac.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_ll_tim.h"
#include "stm32f1xx.h"
#include "stm32f1xx_ll_system.h"
#include "stm32f1xx_ll_gpio.h"
#include "stm32f1xx_ll_exti.h"
#include "stm32f1xx_ll_bus.h"
#include "stm32f1xx_ll_cortex.h"
#include "stm32f1xx_ll_rcc.h"
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx_ll_pwr.h"
#include "stm32f1xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#define first_keynum    0
#define second_keynum   1
#define Third_keynum    2

#define first_keynum    0
#define second_keynum   1
#define Third_keynum    2

#define Single_Key1    1
#define Single_Key2    2
#define Single_Key3    3
#define Single_Key4    4
#define Single_Key5    5
#define Single_Key6    6


#define Long_Key1    11
#define Long_Key2    22
#define Long_Key3    33
#define Long_Key4    44
#define Long_Key5    55
#define Long_Key6    66
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */


/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY2_Pin LL_GPIO_PIN_1
#define KEY2_GPIO_Port GPIOC
#define KEY1_Pin LL_GPIO_PIN_2
#define KEY1_GPIO_Port GPIOC
#define MODESEL_Pin LL_GPIO_PIN_5
#define MODESEL_GPIO_Port GPIOC
#define LED1_Pin LL_GPIO_PIN_1
#define LED1_GPIO_Port GPIOB
#define LED2_Pin LL_GPIO_PIN_2
#define LED2_GPIO_Port GPIOB
#define LCD_RESET_Pin LL_GPIO_PIN_12
#define LCD_RESET_GPIO_Port GPIOB
#define FS2_Pin LL_GPIO_PIN_7
#define FS2_GPIO_Port GPIOC
#define FS1_Pin LL_GPIO_PIN_8
#define FS1_GPIO_Port GPIOC
#define DS18B20_Pin LL_GPIO_PIN_9
#define DS18B20_GPIO_Port GPIOC
#define KEY6_Pin LL_GPIO_PIN_11
#define KEY6_GPIO_Port GPIOC
#define KEY5_Pin LL_GPIO_PIN_12
#define KEY5_GPIO_Port GPIOC
#define KEY4_Pin LL_GPIO_PIN_0
#define KEY4_GPIO_Port GPIOE
#define KEY3_Pin LL_GPIO_PIN_1
#define KEY3_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
