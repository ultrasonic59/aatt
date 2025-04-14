#ifndef __BALOO_EMUL_LINE_BRD_H__
#define __BALOO_EMUL_LINE_BRD_H__

#include "debug.h"

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

extern void gpio_init(void);

extern void put_out_n(uint8_t idat);
extern void set_out_n(uint8_t idat);
extern void clr_out_n(uint8_t idat);
extern uint8_t get_inp(void);
extern void board_init(void);
///===================================================


#endif /// __BALOO_EMUL_LINE_BRD_H__


