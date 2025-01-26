#ifndef __AA_TT2_BRD_H__
#define __AA_TT2__BRD_H__
#include <stdint.h>
#include "debug.h"
///=====================================================
////=============rele1==================================
  #define RELE1_PIN          GPIO_Pin_14
  #define RELE1_GPIO         GPIOC
////=============rele2==================================
  #define RELE2_PIN          GPIO_Pin_15
  #define RELE2_GPIO         GPIOC
////=============rele3==================================
  #define RELE3_PIN          GPIO_Pin_8
  #define RELE3_GPIO         GPIOA
////=============rele4==================================
  #define RELE4_PIN          GPIO_Pin_9
  #define RELE4_GPIO         GPIOA
////=============rele5==================================
  #define RELE5_PIN          GPIO_Pin_3
  #define RELE5_GPIO         GPIOA
////=============rele6==================================
  #define RELE6_PIN          GPIO_Pin_14
  #define RELE6_GPIO         GPIOA
////=============rele7==================================
  #define RELE7_PIN          GPIO_Pin_7
  #define RELE7_GPIO         GPIOA
////=============rele8==================================
  #define RELE8_PIN          GPIO_Pin_6
  #define RELE8_GPIO         GPIOA
////====================================================
#if 0
///============= OUT6 ==================================
  #define OUT6_PIN          GPIO_Pin_0
  #define OUT6_GPIO         GPIOB
  ////============= OUT5 ==================================
  #define OUT5_PIN          GPIO_Pin_1
  #define OUT5_GPIO         GPIOB
  ////============= OUT4 ==================================
  #define OUT4_PIN          GPIO_Pin_3
  #define OUT4_GPIO         GPIOB
  ////============= OUT3 ==================================
  #define OUT3_PIN          GPIO_Pin_11
  #define OUT3_GPIO         GPIOB
  ////============= OUT2 ==================================
  #define OUT2_PIN          GPIO_Pin_12
  #define OUT2_GPIO         GPIOB
  ////============= OUT1 ==================================
  #define OUT1_PIN          GPIO_Pin_14
  #define OUT1_GPIO         GPIOC
  ////============= OUT0 ==================================
  #define OUT0_PIN          GPIO_Pin_15
  #define OUT0_GPIO         GPIOC
///============= IN0 ==================================
  #define IN0_PIN          GPIO_Pin_0
  #define IN0_GPIO         GPIOA
///============= IN1 ==================================
  #define IN1_PIN          GPIO_Pin_1
  #define IN1_GPIO         GPIOA
///============= IN2 ==================================
  #define IN2_PIN          GPIO_Pin_4
  #define IN2_GPIO         GPIOA
///============= IN3 ==================================
  #define IN3_PIN          GPIO_Pin_5
  #define IN3_GPIO         GPIOA
///============= IN4 ==================================
  #define IN4_PIN          GPIO_Pin_6
  #define IN4_GPIO         GPIOA
///============= IN5 ==================================
  #define IN5_PIN          GPIO_Pin_7
  #define IN5_GPIO         GPIOA
///===================================================
#endif

#define MAX_DB 91
#define R1DB (0x1<<7)
#define R2DB (0x1<<6)
#define R4DB (0x1<<5)
#define R8DB (0x1<<4)
#define R16DB (0x1<<3)
#define R20_0DB (0x1<<2)
#define R20_1DB (0x1<<1)
#define R20_2DB (0x1<<0)

extern void gpio_init(void);
extern void board_init(void);
///===================================================


#endif /// __BALOO_EMUL_LINE_BRD_H__


