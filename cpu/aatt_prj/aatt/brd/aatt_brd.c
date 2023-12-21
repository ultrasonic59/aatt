/*
 * aatt_brd.c
 *
 *  Created on: Dec 21, 2023
 *      Author: vagol
 */
#include "aatt_brd.h"

void init_gpio(void)
{
GPIO_InitTypeDef  GPIO_InitStructure = {0};
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
///=============rele1==================================
GPIO_InitStructure.GPIO_Pin = RELE1_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
PIO_Init(RELE1_GPIO, &GPIO_InitStructure);
///=============rele2==================================
GPIO_InitStructure.GPIO_Pin = RELE2_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
PIO_Init(RELE2_GPIO, &GPIO_InitStructure);
///=============rele3==================================
GPIO_InitStructure.GPIO_Pin = RELE3_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
PIO_Init(RELE3_GPIO, &GPIO_InitStructure);
///=============rele4==================================
GPIO_InitStructure.GPIO_Pin = RELE4_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
PIO_Init(RELE4_GPIO, &GPIO_InitStructure);
///=============rele5==================================
GPIO_InitStructure.GPIO_Pin = RELE5_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
PIO_Init(RELE5_GPIO, &GPIO_InitStructure);
///=============rele6==================================
GPIO_InitStructure.GPIO_Pin = RELE6_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
PIO_Init(RELE6_GPIO, &GPIO_InitStructure);
///=============rele7==================================
GPIO_InitStructure.GPIO_Pin = RELE1_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
PIO_Init(RELE7_GPIO, &GPIO_InitStructure);
///=============rele8==================================
GPIO_InitStructure.GPIO_Pin = RELE1_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
PIO_Init(RELE8_GPIO, &GPIO_InitStructure);
}
///=============== rele1 =======================================
void set_rele1(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE1_GPIO,RELE1_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE1_GPIO,RELE1_PIN, Bit_RESET);
}
///=============== rele2 =======================================
void set_rele1(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE2_GPIO,RELE2_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE2_GPIO,RELE2_PIN, Bit_RESET);
}
///=============== rele3 =======================================
void set_rele3(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE3_GPIO,RELE3_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE3_GPIO,RELE3_PIN, Bit_RESET);
}
///=============== rele4 =======================================
void set_rele4(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE4_GPIO,RELE4_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE4_GPIO,RELE4_PIN, Bit_RESET);
}
///=============== rele5 =======================================
void set_rele5(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE5_GPIO,RELE5_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE5_GPIO,RELE5_PIN, Bit_RESET);
}
///=============== rele6 =======================================
void set_rele6(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE6_GPIO,RELE6_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE6_GPIO,RELE6_PIN, Bit_RESET);
}
///=============== rele7 =======================================
void set_rele7(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE7_GPIO,RELE7_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE7_GPIO,RELE7_PIN, Bit_RESET);
}
///=============== rele8 =======================================
void set_rele8(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE8_GPIO,RELE8_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE8_GPIO,RELE8_PIN, Bit_RESET);
}
///===============reles=========================================
void set_reles(uint8_t i_on)
{
if(i_on&(0x1<<0))
    set_rele1(0x1);
else
    set_rele1(0x0);

if(i_on&(0x1<<1))
    set_rele2(0x1);
else
    set_rele2(0x0);

if(i_on&(0x1<<2))
    set_rele3(0x1);
else
    set_rele3(0x0);

if(i_on&(0x1<<3))
    set_rele4(0x1);
else
    set_rele4(0x0);

if(i_on&(0x1<<4))
    set_rele5(0x1);
else
    set_rele5(0x0);

if(i_on&(0x1<<5))
    set_rele6(0x1);
else
    set_rele6(0x0);

if(i_on&(0x1<<6))
    set_rele7(0x1);
else
    set_rele7(0x0);

if(i_on&(0x1<<7))
    set_rele8(0x1);
else
    set_rele8(0x0);

}


