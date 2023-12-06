/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usb_device.h"
#include "usbd_hid.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
I2C_HandleTypeDef hi2c2;

USART_HandleTypeDef husart1;
//USBD_HandleTypeDef hUsbDeviceFS;

/* USER CODE BEGIN PV */
// Keyboard Layout
// ____ ____ ____ ____   ____ ____ ____ ____
//|    |    |    |    | |    |    |    |    |
//|  1 |  2 | 3  |  4 | |  5 |  6 |  7 | 8  |
// ---- ---- ---- ----   ---- ---- ---- ----

//-- Delete following section
#define keyBind1 0x1E
#define keyBind2 0x1F
#define keyBind3 0x20
#define keyBind4 0x21

#define keyBind5 34
#define keyBind6 35
#define keyBind7 36
#define keyBind8 37

//int keyBindArry[8]={0x1E, 0x1F, 0x20, 0x21, 34, 35, 36, 37};
//--end

#define HID_DELAY 10

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_Init(void);
static void MX_I2C2_Init(void);
//int * Button_Read();
//int sumButton_Read();

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
	/* USER CODE BEGIN 1 */

	//Alt keycodes here
	//
	//The arrays USB HID Keycodes for numpad keys
	//Alt codes send 4 in a row for any special character
	//MinAUm is meant to encode an 'a' with umlaut
	//the alt code that encodes that is {0,2,2,8} with numpad characters
	//the HID table lists keypad codes on page 55
	//https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
	//keypad 0: 98, keypad 2: 90, keypad 8, 96
	static int MinAUm[4] = { 98, 90, 90, 96 }; //
	static int MinOUm[4] = { 98, 90, 92, 94 };
	static int MinUUm[4] = { 98, 90, 93, 90 };
	static int SharfS[4] = { 98, 90, 90, 91 };

	static int MajAUm[4] = { 98, 89, 97, 94 };
	static int MajOUm[4] = { 98, 90, 89, 92 };
	static int MajUUm[4] = { 98, 90, 90, 98 };
	static int EuroSg[4] = { 98, 89, 90, 96 };

	//WTF is this magic number array
	//This seems to be a faild attempt to write the characters as tho they were
	//normal keys

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */
	//HID Mouse

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_USART1_Init();
	MX_I2C2_Init();
	MX_USB_DEVICE_Init();
	/* USER CODE BEGIN 2 */
	//HAL_GPIO_WritePin(GPIOA, STATUS_D1_Pin, GPIO_PIN_RESET);
	extern USBD_HandleTypeDef hUsbDeviceFS;

	volatile int keyBufferCur[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }; //Creating a buffer and previous iter buffer for press and release
			 int keyBufferPrev[8] = { 0, 0, 0, 0, 0, 0, 0, 0 }; //size is due to number of keys


	void AltCodeSend(int KP[4]) {
		uint8_t hidWriteBuffer[8] = { 1, 4, 0, 0, 0, 0, 0, 0 }; // This is the key write buffer
		uint8_t hidRelBuffer[8] = { 1, 0, 0, 0, 0, 0, 0, 0 };// This is the key release buffer
		uint8_t hidAltBuffer[8] = { 1, 4, 0, 0, 0, 0, 0, 0 };// This is a buffer to send just alt

		// To send an alt code, four keypad hid codes with alt modifier are
		// sent, interleaved with 4 HID writes with just the alt modifier
		for (int j = 0; j < 4; j++) {
			// Fill, and Send the key press buffer, then wait
			hidWriteBuffer[3] = KP[j];
			USBD_HID_SendReport(&hUsbDeviceFS, hidWriteBuffer, 8);
			HAL_Delay(HID_DELAY);

			USBD_HID_SendReport(&hUsbDeviceFS, hidAltBuffer, 8);
			HAL_Delay(HID_DELAY);
		}
		USBD_HID_SendReport(&hUsbDeviceFS, hidRelBuffer, 8);
		// Send Release
	}

	HAL_GPIO_WritePin(GPIOA, STATUS_D1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOA, D2_Pin, GPIO_PIN_RESET);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */
//	  HAL_GPIO_WritePin(GPIOA, D2_Pin, GPIO_PIN_SET);
//	  HAL_GPIO_TogglePin(GPIOA, STATUS_D1_Pin);
		int Key_Val2[8] = { (HAL_GPIO_ReadPin(Switch1_GPIO_Port, Switch1_Pin)),
				(HAL_GPIO_ReadPin(Switch2_GPIO_Port, Switch2_Pin)),
				(HAL_GPIO_ReadPin(Switch3_GPIO_Port, Switch3_Pin)),
				(HAL_GPIO_ReadPin(Switch4_GPIO_Port, Switch4_Pin)),
				(HAL_GPIO_ReadPin(Switch5_GPIO_Port, Switch5_Pin)),
				(HAL_GPIO_ReadPin(Switch6_GPIO_Port, Switch6_Pin)),
				(HAL_GPIO_ReadPin(Switch7_GPIO_Port, Switch7_Pin)),
				(HAL_GPIO_ReadPin(Switch8_GPIO_Port, Switch8_Pin)) };

		static int PrevPresSum = 0;
		static int CurrPresSum = 0;
		for (int j = 0; j < 8; j++) {
			CurrPresSum += keyBufferCur[j] = (1 ^ Key_Val2[j]); //HAL reads active low, like a maniac. This is my method for flipping the bit from HAL, packing a buffer and summing it. Yuck.
			PrevPresSum += (keyBufferCur[j] != keyBufferPrev[j]); //This checks for a press to release transition between loops
		}

		//Event Press or release, or more accurately, a state change
		if (CurrPresSum != 0 || PrevPresSum != 0) {

			//Checks the current and previous buffer, if there's a new press
			//send an alt code
			if (keyBufferCur[0] == 1 && keyBufferPrev[0] == 0) {
				AltCodeSend(MinAUm);
			}
			if (keyBufferCur[1] == 1 && keyBufferPrev[1] == 0) {
				AltCodeSend(MinOUm);
			}
			if (keyBufferCur[2] == 1 && keyBufferPrev[2] == 0) {
				AltCodeSend(MinUUm);
			}
			if (keyBufferCur[3] == 1 && keyBufferPrev[3] == 0) {
				AltCodeSend(SharfS);
			}
			if (keyBufferCur[4] == 1 && keyBufferPrev[4] == 0) {
				AltCodeSend(MajAUm);
			}
			if (keyBufferCur[5] == 1 && keyBufferPrev[5] == 0) {
				AltCodeSend(MajOUm);
			}
			if (keyBufferCur[6] == 1 && keyBufferPrev[6] == 0) {
				AltCodeSend(MajUUm);
			}
			if (keyBufferCur[7] == 1 && keyBufferPrev[7] == 0) {
				AltCodeSend(EuroSg);
			}





			//Clean up
			//Set 'Prev' array to Current
			PrevPresSum = CurrPresSum;
			CurrPresSum = 0;
			for (int v = 0; v < 8; v++) {
				(keyBufferPrev[v] = keyBufferCur[v]);
			}

			HAL_Delay(20);



			/* USER CODE BEGIN 3 */




		/* USER CODE END 3 */
		}
	}
}

	/**
	 * @brief System Clock Configuration
	 * @retval None
	 */
	void SystemClock_Config(void) {
		RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
		RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };
		RCC_PeriphCLKInitTypeDef PeriphClkInit = { 0 };

		/**Initializes the CPU, AHB and APB busses clocks
		 */
		RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
		RCC_OscInitStruct.HSEState = RCC_HSE_ON;
		RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
		RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
		RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
		RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
		if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
			Error_Handler();
		}
		/**Initializes the CPU, AHB and APB busses clocks
		 */
		RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
				| RCC_CLOCKTYPE_PCLK1;
		RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
		RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
		RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

		if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1)
				!= HAL_OK) {
			Error_Handler();
		}
		PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB
				| RCC_PERIPHCLK_USART1;
		PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
		PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;

		if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK) {
			Error_Handler();
		}
	}

	/**
	 * @brief I2C2 Initialization Function
	 * @param None
	 * @retval None
	 */
	static void MX_I2C2_Init(void) {

		/* USER CODE BEGIN I2C2_Init 0 */

		/* USER CODE END I2C2_Init 0 */

		/* USER CODE BEGIN I2C2_Init 1 */

		/* USER CODE END I2C2_Init 1 */
		hi2c2.Instance = I2C2;
		hi2c2.Init.Timing = 0x20303E5D;
		hi2c2.Init.OwnAddress1 = 0;
		hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
		hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
		hi2c2.Init.OwnAddress2 = 0;
		hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
		hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
		hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
		if (HAL_I2C_Init(&hi2c2) != HAL_OK) {
			Error_Handler();
		}
		/**Configure Analogue filter
		 */
		if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE)
				!= HAL_OK) {
			Error_Handler();
		}
		/**Configure Digital filter
		 */
		if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK) {
			Error_Handler();
		}
		/* USER CODE BEGIN I2C2_Init 2 */

		/* USER CODE END I2C2_Init 2 */

	}

	/**
	 * @brief USART1 Initialization Function
	 * @param None
	 * @retval None
	 */
	static void MX_USART1_Init(void) {

		/* USER CODE BEGIN USART1_Init 0 */

		/* USER CODE END USART1_Init 0 */

		/* USER CODE BEGIN USART1_Init 1 */

		/* USER CODE END USART1_Init 1 */
		husart1.Instance = USART1;
		husart1.Init.BaudRate = 38400;
		husart1.Init.WordLength = USART_WORDLENGTH_8B;
		husart1.Init.StopBits = USART_STOPBITS_1;
		husart1.Init.Parity = USART_PARITY_NONE;
		husart1.Init.Mode = USART_MODE_TX_RX;
		husart1.Init.CLKPolarity = USART_POLARITY_LOW;
		husart1.Init.CLKPhase = USART_PHASE_1EDGE;
		husart1.Init.CLKLastBit = USART_LASTBIT_DISABLE;
		if (HAL_USART_Init(&husart1) != HAL_OK) {
			Error_Handler();
		}
		/* USER CODE BEGIN USART1_Init 2 */

		/* USER CODE END USART1_Init 2 */

	}

	/**
	 * @brief GPIO Initialization Function
	 * @param None
	 * @retval None
	 */
	static void MX_GPIO_Init(void) {
		GPIO_InitTypeDef GPIO_InitStruct = { 0 };

		/* GPIO Ports Clock Enable */
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOF_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();

		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(GPIOC, LED7_Pin | LED8_Pin | GPIO4_Pin,
				GPIO_PIN_RESET);

		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(GPIOA, STATUS_D1_Pin | D2_Pin, GPIO_PIN_SET);

		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(GPIOA, GPIO1_Pin | GPIO2_Pin | GPIO3_Pin,
				GPIO_PIN_RESET);

		/*Configure GPIO pin Output Level */
		HAL_GPIO_WritePin(GPIOB,
				LED3_Pin | LED4_Pin | LED5_Pin | LED6_Pin | LED1_Pin | LED2_Pin,
				GPIO_PIN_SET);

		/*Configure GPIO pins : LED7_Pin LED8_Pin GPIO4_Pin */
		GPIO_InitStruct.Pin = LED7_Pin | LED8_Pin | GPIO4_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

		/*Configure GPIO pins : STATUS_D1_Pin D2_Pin */
		GPIO_InitStruct.Pin = STATUS_D1_Pin | D2_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_PULLDOWN;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		/*Configure GPIO pins : RevisionBit0_Pin RevisionBit1_Pin RevisionBit2_Pin RevisionBit3_Pin */
		GPIO_InitStruct.Pin = RevisionBit0_Pin | RevisionBit1_Pin
				| RevisionBit2_Pin | RevisionBit3_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		/*Configure GPIO pins : GPIO1_Pin GPIO2_Pin GPIO3_Pin */
		GPIO_InitStruct.Pin = GPIO1_Pin | GPIO2_Pin | GPIO3_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

		/*Configure GPIO pins : Switch1_Pin Switch2_Pin Switch3_Pin Switch4_Pin
		 Switch5_Pin Switch6_Pin Switch7_Pin Switch8_Pin */
		GPIO_InitStruct.Pin = Switch1_Pin | Switch2_Pin | Switch3_Pin
				| Switch4_Pin | Switch5_Pin | Switch6_Pin | Switch7_Pin
				| Switch8_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

		/*Configure GPIO pins : LED3_Pin LED4_Pin LED5_Pin LED6_Pin
		 LED1_Pin LED2_Pin */
		GPIO_InitStruct.Pin = LED3_Pin | LED4_Pin | LED5_Pin | LED6_Pin
				| LED1_Pin | LED2_Pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	}


	/* USER CODE BEGIN 4 */

	/* USER CODE END 4 */

	/**
	 * @brief  This function is executed in case of error occurrence.
	 * @retval None
	 */
	void Error_Handler(void) {
		/* USER CODE BEGIN Error_Handler_Debug */
		/* User can add his own implementation to report the HAL error return state */

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
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

	/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
