/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "drv_st7789.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
struct Commands main_cmd;
uint8_t RxBuffer[LENGTH];
uint8_t RecCount = 0;
uint32_t TIM_counter = 0;
uint8_t Key_Num4 = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  LCD_Init();
    LCD_Fill(0,0,240,320,WHITE);
//    LCD_ShowChar(175,80,':',BLACK,WHITE,24,0);
    __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
    HAL_UART_Receive_DMA(&huart1, (uint8_t *) RxBuffer, LENGTH);
    HAL_TIM_Base_Start_IT(&htim3);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 5000);
//    HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//      LCD_ShowIntNum(185,80,main_cmd.T_scd/10,1,BLACK,WHITE,24);
//      LCD_ShowIntNum(200,80,main_cmd.T_scd%10,1,BLACK,WHITE,24);
//      LCD_ShowIntNum(165,80,main_cmd.T_min%10,1,BLACK,WHITE,24);
//      LCD_ShowIntNum(150,80,main_cmd.T_min/10,1,BLACK,WHITE,24);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
      switch (main_cmd.Key_Num) {
          case 1:
              if(main_cmd.print_1_){
                  __HAL_TIM_CLEAR_FLAG(&htim3, TIM3_IRQn);
                  HAL_TIM_Base_Stop_IT(&htim3);
//                  HAL_TIM_Base_Stop(&htim3);
                  println("请输入设定小时时间：");
                  main_cmd.print_1_ = 0;
              }
              break;

          case 2:
              if(main_cmd.print_1_){
                  __HAL_TIM_CLEAR_FLAG(&htim3, TIM3_IRQn);
                  HAL_TIM_Base_Stop_IT(&htim3);
//                  HAL_TIM_Base_Stop(&htim3);
                  println("请输入设定分钟时间：");
                  main_cmd.print_1_ = 0;
              }
              break;

          case 3:
              if(main_cmd.print_1_){
                  __HAL_TIM_CLEAR_FLAG(&htim3, TIM3_IRQn);
                  HAL_TIM_Base_Stop_IT(&htim3);
//                  HAL_TIM_Base_Stop(&htim3);
                  println("闹钟设定,请输入设定时间：(格式: hh-mm):");
                  main_cmd.print_1_ = 0;
              }
              alarm_compare();
              break;
          case 4:
              __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
              main_cmd.Key_Num = 0;
              break;
          default:
              main_cmd.print_1_ = 1;
              main_cmd.A_min = 99;
              main_cmd.A_hor = 99;
              break;
      }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void alarm_compare(){
    if(main_cmd.T_min == main_cmd.A_min && main_cmd.T_hor == main_cmd.A_hor){
        HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
        main_cmd.Key_Num = 0;
    }
}

void LCD_Show_Time(char* String){
    LCD_ShowString(80,80,String,BLACK,WHITE,24,0);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
