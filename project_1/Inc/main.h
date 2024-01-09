/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
#define LENGTH 100
struct LED_Dsp_State{
    uint8_t flag1_LED_state_dsp;
    uint8_t flag2_beep_state;
};

extern struct LED_Dsp_State main_LED_dsp_state;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern uint8_t RxBuffer[LENGTH];
extern uint8_t RecCount;
extern uint8_t  RxFlag;
extern uint32_t TIM_counter;
extern uint8_t Key_Num4;
extern uint16_t LED_array[];
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED3_Pin GPIO_PIN_2
#define LED3_GPIO_Port GPIOE
#define LED4_Pin GPIO_PIN_3
#define LED4_GPIO_Port GPIOE
#define LED5_Pin GPIO_PIN_4
#define LED5_GPIO_Port GPIOE
#define LED6_Pin GPIO_PIN_5
#define LED6_GPIO_Port GPIOE
#define LED7_Pin GPIO_PIN_6
#define LED7_GPIO_Port GPIOE
#define Key1_Pin GPIO_PIN_0
#define Key1_GPIO_Port GPIOC
#define Key1_EXTI_IRQn EXTI0_IRQn
#define Key2_Pin GPIO_PIN_1
#define Key2_GPIO_Port GPIOC
#define Key2_EXTI_IRQn EXTI1_IRQn
#define Key3_Pin GPIO_PIN_2
#define Key3_GPIO_Port GPIOC
#define Key3_EXTI_IRQn EXTI2_IRQn
#define Key4_Pin GPIO_PIN_3
#define Key4_GPIO_Port GPIOC
#define Key4_EXTI_IRQn EXTI3_IRQn
#define LED8_Pin GPIO_PIN_7
#define LED8_GPIO_Port GPIOE
#define LED1_Pin GPIO_PIN_0
#define LED1_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_1
#define LED2_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
