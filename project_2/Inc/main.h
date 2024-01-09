/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
struct Commands{
    uint8_t Key_Num;
    uint8_t T_scd;
    uint8_t T_min;
    uint8_t T_hor;
    uint8_t print_1_;
    uint8_t enter_ag;
    uint8_t A_min;
    uint8_t A_hor;
};

extern struct Commands main_cmd;

#define LENGTH 100
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern uint8_t RxBuffer[LENGTH];
extern uint8_t RecCount;
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
void alarm_compare();
void LCD_Show_Time(char* String);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
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
#define RES_Pin GPIO_PIN_1
#define RES_GPIO_Port GPIOA
#define DC_Pin GPIO_PIN_2
#define DC_GPIO_Port GPIOA
#define CS_Pin GPIO_PIN_3
#define CS_GPIO_Port GPIOA
#define BL_Pin GPIO_PIN_4
#define BL_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
