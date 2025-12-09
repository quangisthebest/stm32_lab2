/*
 * display7seg.c
 *
 *  Created on: Dec 9, 2025
 *      Author: ACER
 */

#include "display7seg.h"
#include "main.h"

const uint8_t segCode[10] = {
  0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F  // 9
};

void display7SEG(int num)
{
  if(num > 9) num = 0;
  uint8_t data = segCode[num];

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, (data&0x01)?GPIO_PIN_RESET:GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, (data&0x02)?GPIO_PIN_RESET:GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, (data&0x04)?GPIO_PIN_RESET:GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, (data&0x08)?GPIO_PIN_RESET:GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, (data&0x10)?GPIO_PIN_RESET:GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, (data&0x20)?GPIO_PIN_RESET:GPIO_PIN_SET);
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, (data&0x40)?GPIO_PIN_RESET:GPIO_PIN_SET);
}

