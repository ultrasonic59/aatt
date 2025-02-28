/*
 * aatt_brd.h
 *
 *  Created on: Dec 21, 2023
 *      Author: vagol
 */

#ifndef _IND7A_BRD_H_
#define _IND7A_BRD_H_
#include "ch32v00x_conf.h"

///========================================
////=============anod1==================================
  #define ANOD1_PIN          GPIO_Pin_7
  #define ANOD1_GPIO         GPIOC
////============= anod2 ==================================
  #define ANOD2_PIN          GPIO_Pin_1
  #define ANOD2_GPIO         GPIOA
////=============cathodS==================================
////=============cath_a==================================
  #define CAT_A_PIN          GPIO_Pin_2
  #define CAT_A_GPIO         GPIOA
////=============cath_b==================================
  #define CAT_B_PIN          GPIO_Pin_2
  #define CAT_B_GPIO         GPIOD
////=============cath_c==================================
  #define CAT_C_PIN          GPIO_Pin_3
  #define CAT_C_GPIO         GPIOC
////=============cath_d==================================
  #define CAT_D_PIN          GPIO_Pin_5
  #define CAT_D_GPIO         GPIOC
////=============cath_e==================================
  #define CAT_E_PIN          GPIO_Pin_4
  #define CAT_E_GPIO         GPIOC
////=============cath_f==================================
  #define CAT_F_PIN          GPIO_Pin_6
  #define CAT_F_GPIO         GPIOC
////=============cath_g==================================
  #define CAT_G_PIN          GPIO_Pin_0
  #define CAT_G_GPIO         GPIOD
////====================================================
///========================================
#define TIMER_PER 1000
#define TIMER_PRE 100

#define ON_ANOD 1
#define OFF_ANOD 0

#define NUM_DIG 16
#define BIT_A (0x1<<0)
#define BIT_B (0x1<<1)
#define BIT_C (0x1<<2)
#define BIT_D (0x1<<3)
#define BIT_E (0x1<<4)
#define BIT_F (0x1<<5)
#define BIT_G (0x1<<6)

extern void init_gpio(void);
extern void set_caths(uint8_t i_on);
extern void set_anods(uint8_t on_off);
extern void set_anod1(uint8_t on_off);
extern void set_anod2(uint8_t on_off);

#endif /* IND7A_BRD_H_ */
