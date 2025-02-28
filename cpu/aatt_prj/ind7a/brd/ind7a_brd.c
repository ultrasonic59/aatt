/*
 * ind7a_brd.c
 *
 *  Created on: Feb 27, 2025
 *      Author: vagol
 */
#include "ind7a_brd.h"

void init_gpio(void)
{
GPIO_InitTypeDef  GPIO_InitStructure = {0};
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
///=============anod1==================================
GPIO_InitStructure.GPIO_Pin = ANOD1_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(ANOD1_GPIO, &GPIO_InitStructure);
///=============anod2==================================
GPIO_InitStructure.GPIO_Pin = ANOD2_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(ANOD2_GPIO, &GPIO_InitStructure);
////=============cathodS==================================
///=============cath_a==================================
GPIO_InitStructure.GPIO_Pin = CAT_A_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(CAT_A_GPIO, &GPIO_InitStructure);
///=============cath_b==================================
GPIO_InitStructure.GPIO_Pin = CAT_B_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(CAT_B_GPIO, &GPIO_InitStructure);
///=============cath_c==================================
GPIO_InitStructure.GPIO_Pin = CAT_C_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(CAT_C_GPIO, &GPIO_InitStructure);
///=============cath_d==================================
GPIO_InitStructure.GPIO_Pin = CAT_D_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(CAT_D_GPIO, &GPIO_InitStructure);
///=============cath_e==================================
GPIO_InitStructure.GPIO_Pin = CAT_E_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(CAT_E_GPIO, &GPIO_InitStructure);
///=============cath_f==================================
GPIO_InitStructure.GPIO_Pin = CAT_F_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(CAT_F_GPIO, &GPIO_InitStructure);
///=============cath_g==================================
GPIO_InitStructure.GPIO_Pin = CAT_G_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
GPIO_Init(CAT_G_GPIO, &GPIO_InitStructure);
}
///=============== anod1 =======================================
void set_anod1(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(ANOD1_GPIO,ANOD1_PIN,Bit_SET);
 else
     GPIO_WriteBit(ANOD1_GPIO,ANOD1_PIN, Bit_RESET);
}
///=============== anod1 =======================================
void set_anod2(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(ANOD2_GPIO,ANOD2_PIN,Bit_SET);
 else
     GPIO_WriteBit(ANOD2_GPIO,ANOD2_PIN, Bit_RESET);
}
void set_anods(uint8_t on_off)
{
if(on_off&0x1)
{
   set_anod1(0x0);
   set_anod2(0x1);
}
else {
    set_anod2(0x0);
    set_anod1(0x1);
}
}
///=============== cath_a =======================================
void set_cath_a(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(CAT_A_GPIO,CAT_A_PIN,Bit_SET);
 else
     GPIO_WriteBit(CAT_A_GPIO,CAT_A_PIN, Bit_RESET);
}
///=============== cath_b =======================================
void set_cath_b(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(CAT_B_GPIO,CAT_B_PIN,Bit_SET);
 else
     GPIO_WriteBit(CAT_B_GPIO,CAT_B_PIN, Bit_RESET);
}
///=============== cath_c =======================================
void set_cath_c(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(CAT_C_GPIO,CAT_C_PIN,Bit_SET);
 else
     GPIO_WriteBit(CAT_C_GPIO,CAT_C_PIN, Bit_RESET);
}
///=============== cath_d =======================================
void set_cath_d(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(CAT_D_GPIO,CAT_D_PIN,Bit_SET);
 else
     GPIO_WriteBit(CAT_D_GPIO,CAT_D_PIN, Bit_RESET);
}
///=============== cath_e =======================================
void set_cath_e(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(CAT_E_GPIO,CAT_E_PIN,Bit_SET);
 else
     GPIO_WriteBit(CAT_E_GPIO,CAT_E_PIN, Bit_RESET);
}
///=============== cath_f =======================================
void set_cath_f(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(CAT_F_GPIO,CAT_F_PIN,Bit_SET);
 else
     GPIO_WriteBit(CAT_F_GPIO,CAT_F_PIN, Bit_RESET);
}
///=============== cath_g =======================================
void set_cath_g(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(CAT_G_GPIO,CAT_G_PIN,Bit_SET);
 else
     GPIO_WriteBit(CAT_G_GPIO,CAT_G_PIN, Bit_RESET);
}

///===============set_caths=========================================
void set_caths(uint8_t i_on)
{
if(i_on&(0x1<<0))
    set_cath_a(0x1);
else
    set_cath_a(0x0);

if(i_on&(0x1<<1))
    set_cath_b(0x1);
else
    set_cath_b(0x0);

if(i_on&(0x1<<2))
    set_cath_c(0x1);
else
    set_cath_c(0x0);

if(i_on&(0x1<<3))
    set_cath_d(0x1);
else
    set_cath_d(0x0);

if(i_on&(0x1<<4))
    set_cath_e(0x1);
else
    set_cath_e(0x0);

if(i_on&(0x1<<5))
    set_cath_f(0x1);
else
    set_cath_f(0x0);
if(i_on&(0x1<<6))
    set_cath_g(0x1);
else
    set_cath_g(0x0);

}


