/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2019 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
#include "stm32f0xx_hal.h"

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
#define LED7_Pin GPIO_PIN_13
#define LED7_GPIO_Port GPIOC
#define LED8_Pin GPIO_PIN_14
#define LED8_GPIO_Port GPIOC
#define GPIO4_Pin GPIO_PIN_15
#define GPIO4_GPIO_Port GPIOC
#define STATUS_D1_Pin GPIO_PIN_0
#define STATUS_D1_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_1
#define D2_GPIO_Port GPIOA
#define RevisionBit0_Pin GPIO_PIN_2
#define RevisionBit0_GPIO_Port GPIOA
#define RevisionBit1_Pin GPIO_PIN_3
#define RevisionBit1_GPIO_Port GPIOA
#define RevisionBit2_Pin GPIO_PIN_4
#define RevisionBit2_GPIO_Port GPIOA
#define RevisionBit3_Pin GPIO_PIN_5
#define RevisionBit3_GPIO_Port GPIOA
#define GPIO1_Pin GPIO_PIN_6
#define GPIO1_GPIO_Port GPIOA
#define GPIO2_Pin GPIO_PIN_7
#define GPIO2_GPIO_Port GPIOA
#define Switch1_Pin GPIO_PIN_0
#define Switch1_GPIO_Port GPIOB
#define Switch2_Pin GPIO_PIN_1
#define Switch2_GPIO_Port GPIOB
#define Switch3_Pin GPIO_PIN_2
#define Switch3_GPIO_Port GPIOB
#define LED3_Pin GPIO_PIN_12
#define LED3_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_13
#define LED4_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_14
#define LED5_GPIO_Port GPIOB
#define LED6_Pin GPIO_PIN_15
#define LED6_GPIO_Port GPIOB
#define GPIO3_Pin GPIO_PIN_15
#define GPIO3_GPIO_Port GPIOA
#define Switch4_Pin GPIO_PIN_3
#define Switch4_GPIO_Port GPIOB
#define Switch5_Pin GPIO_PIN_4
#define Switch5_GPIO_Port GPIOB
#define Switch6_Pin GPIO_PIN_5
#define Switch6_GPIO_Port GPIOB
#define Switch7_Pin GPIO_PIN_6
#define Switch7_GPIO_Port GPIOB
#define Switch8_Pin GPIO_PIN_7
#define Switch8_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_8
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_9
#define LED2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
