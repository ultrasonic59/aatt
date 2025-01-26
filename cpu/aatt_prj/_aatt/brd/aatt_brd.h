/*
 * aatt_brd.h
 *
 *  Created on: Dec 21, 2023
 *      Author: vagol
 */

#ifndef _AATT_BRD_H_
#define _AATT_BRD_H_
#include "ch32v00x_conf.h"

///========================================
////=============rele1==================================
  #define RELE1_PIN          GPIO_Pin_1
  #define RELE1_GPIO         GPIOA
////=============rele2==================================
  #define RELE2_PIN          GPIO_Pin_1
  #define RELE2_GPIO         GPIOC
////=============rele3==================================
  #define RELE3_PIN          GPIO_Pin_2
  #define RELE3_GPIO         GPIOC
////=============rele4==================================
  #define RELE4_PIN          GPIO_Pin_3
  #define RELE4_GPIO         GPIOC
////=============rele5==================================
  #define RELE5_PIN          GPIO_Pin_4
  #define RELE5_GPIO         GPIOC
////=============rele6==================================
  #define RELE6_PIN          GPIO_Pin_6
  #define RELE6_GPIO         GPIOC
////=============rele7==================================
  #define RELE7_PIN          GPIO_Pin_7
  #define RELE7_GPIO         GPIOC
////=============rele8==================================
  #define RELE8_PIN          GPIO_Pin_4
  #define RELE8_GPIO         GPIOD
////====================================================

#define MAX_DB 91
#define R1DB (0x1<<7)
#define R2DB (0x1<<6)
#define R4DB (0x1<<5)
#define R8DB (0x1<<4)
#define R16DB (0x1<<3)
#define R20_0DB (0x1<<2)
#define R20_1DB (0x1<<1)
#define R20_2DB (0x1<<0)

///========================================
extern void init_gpio(void);
extern void set_reles(uint8_t i_dat);

#endif /* BRD_AATT_BRD_H_ */
