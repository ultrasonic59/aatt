
#include "baloo_emul_line_brd.h"

uint8_t cur_stat=0;

///======= gpio ============================================
void gpio_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE );
   ///============= OUT0 ==================================
    GPIO_InitStructure.GPIO_Pin = OUT0_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT0_GPIO, &GPIO_InitStructure);
///    GPIO_ResetBits(OUT0_GPIO, OUT0_PIN);
    ///============= OUT1 ==================================
    GPIO_InitStructure.GPIO_Pin = OUT1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT1_GPIO, &GPIO_InitStructure);
     ///============= OUT2 ==================================
    GPIO_InitStructure.GPIO_Pin = OUT2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT2_GPIO, &GPIO_InitStructure);
      ///============= OUT3 ==================================
    GPIO_InitStructure.GPIO_Pin = OUT3_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT3_GPIO, &GPIO_InitStructure);
       ///============= OUT4 ==================================
    GPIO_InitStructure.GPIO_Pin = OUT4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT4_GPIO, &GPIO_InitStructure);
     ///============= OUT5 ==================================
    GPIO_InitStructure.GPIO_Pin = OUT5_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(OUT5_GPIO, &GPIO_InitStructure);
    ///============= OUT6 ==================================
   GPIO_InitStructure.GPIO_Pin = OUT6_PIN;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(OUT6_GPIO, &GPIO_InitStructure);
    ///=============IN0==================================
    GPIO_InitStructure.GPIO_Pin = IN0_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 ///   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
    GPIO_Init(IN0_GPIO, &GPIO_InitStructure);
    ///=============IN1==================================
    GPIO_InitStructure.GPIO_Pin = IN1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 ///   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
    GPIO_Init(IN1_GPIO, &GPIO_InitStructure);
    ///=============IN2==================================
    GPIO_InitStructure.GPIO_Pin = IN2_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 ///   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
    GPIO_Init(IN2_GPIO, &GPIO_InitStructure);
    ///=============IN3==================================
    GPIO_InitStructure.GPIO_Pin = IN3_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 ///   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
    GPIO_Init(IN3_GPIO, &GPIO_InitStructure);
    ///=============IN4==================================
    GPIO_InitStructure.GPIO_Pin = IN4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 ///   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
    GPIO_Init(IN4_GPIO, &GPIO_InitStructure);
    ///=============IN5==================================
    GPIO_InitStructure.GPIO_Pin = IN5_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 ///   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;///GPIO_Speed_50MHz;
    GPIO_Init(IN5_GPIO, &GPIO_InitStructure);

}

void board_init(void)
{
gpio_init();
}
////=============OUT0 ==================================
void put_out0(uint8_t on_off)
{
 if((on_off&0x1)==0)
     GPIO_WriteBit(OUT0_GPIO,OUT0_PIN,Bit_SET);
 else
     GPIO_WriteBit(OUT0_GPIO,OUT0_PIN, Bit_RESET);
}
////=============OUT1 ==================================
void put_out1(uint8_t on_off)
{
if((on_off&0x1)==0)
     GPIO_WriteBit(OUT1_GPIO,OUT1_PIN,Bit_SET);
 else
     GPIO_WriteBit(OUT1_GPIO,OUT1_PIN, Bit_RESET);
}
////=============OUT2 ==================================
void put_out2(uint8_t on_off)
{
if((on_off&0x1)==0)
     GPIO_WriteBit(OUT2_GPIO,OUT2_PIN,Bit_SET);
 else
     GPIO_WriteBit(OUT2_GPIO,OUT2_PIN, Bit_RESET);
}
////=============OUT3 ==================================
void put_out3(uint8_t on_off)
{
if((on_off&0x1)==0)
     GPIO_WriteBit(OUT3_GPIO,OUT3_PIN,Bit_SET);
 else
     GPIO_WriteBit(OUT3_GPIO,OUT3_PIN, Bit_RESET);
}
////=============OUT4 ==================================
void put_out4(uint8_t on_off)
{
if((on_off&0x1)==0)
     GPIO_WriteBit(OUT4_GPIO,OUT4_PIN,Bit_SET);
 else
     GPIO_WriteBit(OUT4_GPIO,OUT4_PIN, Bit_RESET);
}
////=============OUT5 ==================================
void put_out5(uint8_t on_off)
{
if((on_off&0x1)==0)
     GPIO_WriteBit(OUT5_GPIO,OUT5_PIN,Bit_SET);
 else
     GPIO_WriteBit(OUT5_GPIO,OUT5_PIN, Bit_RESET);
}
////=============OUT6 ==================================
void put_out6(uint8_t on_off)
{
if((on_off&0x1)==0)
     GPIO_WriteBit(OUT6_GPIO,OUT6_PIN,Bit_SET);
 else
     GPIO_WriteBit(OUT6_GPIO,OUT6_PIN, Bit_RESET);
}
///=====================================================
uint8_t get_inp(void)
{
uint8_t rez=0;
if (GPIO_ReadInputDataBit(IN0_GPIO, IN0_PIN) == Bit_RESET)
  rez |= (0x01 << 0);
if (GPIO_ReadInputDataBit(IN1_GPIO, IN1_PIN) == Bit_RESET)
  rez |= (0x01 << 1);
if (GPIO_ReadInputDataBit(IN2_GPIO, IN2_PIN) == Bit_RESET)
  rez |= (0x01 << 2);
if (GPIO_ReadInputDataBit(IN3_GPIO, IN3_PIN) == Bit_RESET)
  rez |= (0x01 << 3);
if (GPIO_ReadInputDataBit(IN4_GPIO, IN4_PIN) == Bit_RESET)
  rez |= (0x01 << 4);
if (GPIO_ReadInputDataBit(IN5_GPIO, IN5_PIN) == Bit_RESET)
  rez |= (0x01 << 5);
///rez=0x12;
return rez;
}

void put_out_n(uint8_t ttst)
{
    printf("\r\n put_out_n:[%x]\r\n", ttst);

    put_out0(ttst);
    put_out1(ttst>>1);
   put_out2(ttst>>2);
    put_out3(ttst>>3);
   put_out4(ttst>>4);
   put_out5(ttst>>5);
   put_out6(ttst>>6);
}
void set_out_n(uint8_t ttst)
{
    printf("\r\n set_out_n:[%x]\r\n", ttst);
  if(ttst&0x1)
     put_out0(1);
  ttst>>=1;
  if(ttst&0x1)
     put_out1(1);
  ttst>>=1;
  if(ttst&0x1)
     put_out2(1);
  ttst>>=1;
  if(ttst&0x1)
     put_out3(1);
  ttst>>=1;
  if(ttst&0x1)
     put_out4(1);
  ttst>>=1;
  if(ttst&0x1)
     put_out5(1);
  ttst>>=1;
  if(ttst&0x1)
     put_out6(1);

}
void clr_out_n(uint8_t ttst)
{
  printf("\r\n clr_out_n:[%x]\r\n", ttst);
  if(ttst&0x1)
    put_out0(0);
  ttst>>=1;
  if(ttst&0x1)
     put_out1(0);
  ttst>>=1;
  if(ttst&0x1)
     put_out2(0);
  ttst>>=1;
  if(ttst&0x1)
     put_out3(0);
  ttst>>=1;
  if(ttst&0x1)
     put_out4(0);
  ttst>>=1;
  if(ttst&0x1)
     put_out5(0);
  ttst>>=1;
  if(ttst&0x1)
     put_out6(0);

}
