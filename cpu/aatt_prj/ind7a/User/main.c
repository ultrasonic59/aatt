/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2022/08/08
 * Description        : Main program body.
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*
 *@Note
 *Multiprocessor communication mode routine:
 *Master:USART1_Tx(PD5)\USART1_Rx(PD6).
 *This routine demonstrates that USART1 receives the data sent by CH341 and inverts
 *it and sends it (baud rate 115200).
 *
 *Hardware connection:PD5 -- Rx
 *                     PD6 -- Tx
 *
 */

#include <string.h>
#include <stdlib.h>
#include "debug.h"

#include "../brd/ind7a_brd.h"

////https://www.youtube.com/watch?v=PtW0C0qOq-o

/* Global define */
/* I2C Mode Definition */
#define HOST_MODE   0
#define SLAVE_MODE   1

/* I2C Communication Mode Selection */
//#define I2C_MODE   HOST_MODE
#define I2C_MODE   SLAVE_MODE

#define RXAdderss   0x02

/* Global Variable */
vu8 cur_val=0;

/*********************************************************************
 * @fn      USARTx_CFG
 *
 * @brief   Initializes the USART2 & USART3 peripheral.
 *
 * @return  none
 */
void USARTx_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);

    /* USART1 TX-->D.5   RX-->D.6 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

    USART_Init(USART1, &USART_InitStructure);
    USART_Cmd(USART1, ENABLE);
}
///===================================================
const uint8_t tbl_7s[NUM_DIG]={BIT_A|BIT_B|BIT_C|BIT_D|BIT_E|BIT_F   ///0
                               ,BIT_B|BIT_C   ///1
                               ,BIT_A|BIT_B|BIT_D|BIT_E|BIT_G///2
                               ,BIT_A|BIT_B|BIT_C|BIT_D|BIT_G  ///3
                               ,BIT_B|BIT_C|BIT_G|BIT_F ///4
                               ,BIT_A|BIT_C|BIT_D|BIT_F|BIT_G  ///5
                               ,BIT_A|BIT_C|BIT_D|BIT_E|BIT_F|BIT_G ///6
                               ,BIT_A|BIT_B|BIT_C///7
                               ,BIT_A|BIT_B|BIT_C|BIT_D|BIT_E|BIT_F|BIT_G//8
                               ,BIT_A|BIT_B|BIT_C|BIT_D|BIT_F|BIT_G  //9
                               ,BIT_A|BIT_B|BIT_C|BIT_E|BIT_F|BIT_G//A
                               ,BIT_C|BIT_D|BIT_E|BIT_F|BIT_G//B
                               ,BIT_A|BIT_D|BIT_E|BIT_F//C
                               ,BIT_B|BIT_C|BIT_D|BIT_E|BIT_G//d
                               ,BIT_A|BIT_D|BIT_E|BIT_F|BIT_G//E
                               ,BIT_A|BIT_E|BIT_F|BIT_G//f

 };

void set_dig(uint8_t t_dig)
{
 if(t_dig > NUM_DIG)
     t_dig=NUM_DIG;
uint8_t t_symb=tbl_7s[t_dig];
set_caths(t_symb);
}
///static uint8_t cur_cnt=0;

void show_val(uint8_t val, uint8_t num_dig)
{
if(num_dig&0x1)
   {
    set_anods(0x0);
 ///   set_dig(val);
   }
else
    {
    set_anods(0x1);
///    set_dig(val);
    }
set_dig(val);

}
///====================================================================
void TIM1_Init(u16 per, u16 psc)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure={0};
    NVIC_InitTypeDef NVIC_InitStructure={0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_TIM1, ENABLE );

    TIM_TimeBaseInitStructure.TIM_Period = per;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit( TIM1, &TIM_TimeBaseInitStructure);
    TIM_ClearITPendingBit( TIM1, TIM_IT_Update);
    TIM_ITConfig( TIM1, TIM_IT_Update, ENABLE);
    TIM_ARRPreloadConfig( TIM1, ENABLE);

 ///   TIM_Cmd( TIM1, ENABLE );
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitStructure);
    TIM_Cmd( TIM1, ENABLE );
}
///volatile uint8_t v_tst =0;
static uint8_t cur_cnt_dig=0;

void TIM1_UP_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast"))); /* Interrupt handler function */
void TIM1_UP_IRQHandler(void)
{
    if (TIM_GetFlagStatus(TIM1, TIM_FLAG_Update) != RESET)
    {
        TIM_ClearITPendingBit(TIM1, TIM_IT_Update);
        if(cur_cnt_dig==0)
        {
            show_val(cur_val&0xf,0);
        }
        else {
            {
             show_val((cur_val>>4)&0xf,1);
             }
        }
      cur_cnt_dig++;
      cur_cnt_dig&=0x1;
     }
}

///====================================================================
/*********************************************************************
 * @fn      IIC_Init
 *
 * @brief   Initializes the IIC peripheral.
 *
 * @return  none
 */
void IIC_Init(u32 bound, u16 address)
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    I2C_InitTypeDef I2C_InitTSturcture={0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_I2C1, ENABLE );

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOC, &GPIO_InitStructure );

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOC, &GPIO_InitStructure );

    I2C_InitTSturcture.I2C_ClockSpeed = bound;
    I2C_InitTSturcture.I2C_Mode = I2C_Mode_I2C;
    I2C_InitTSturcture.I2C_DutyCycle = I2C_DutyCycle_16_9;
    I2C_InitTSturcture.I2C_OwnAddress1 = address;
    I2C_InitTSturcture.I2C_Ack = I2C_Ack_Enable;
    I2C_InitTSturcture.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init( I2C1, &I2C_InitTSturcture );
}

///===================================================
uint8_t bin_to_bcd(uint8_t idat)
{
uint8_t rez=0;
rez=(idat/10);
rez<<=4 ;
rez+=(idat%10);

    return rez;
}
/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
#define LEN_BUF 32
int main(void)
{
///uint8_t tst =0;
///uint8_t t_db =0;
uint16_t rdat =0;

///uint8_t in_buf[LEN_BUF] ;
/// uint8_t out_buf[LEN_BUF] ;
 ////uint8_t cur_cnt=0;
 ////   uint8_t tst=0;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SystemCoreClockUpdate();
    Delay_Init();
#if (SDI_PRINT == SDI_PR_OPEN)
    SDI_Printf_Enable();
#else
    USART_Printf_Init(115200);
#endif
    printf("SystemClk:%d\r\n",SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );

    USARTx_CFG();
    init_gpio();
    TIM1_Init(TIMER_PER, TIMER_PRE);
    IIC_Init( 100000, RXAdderss ); // 100Kbps
    I2C1->CTLR1 |= 0x0080; // CTLR1_NOSTRETCH_Set - Disable clock stretching
    I2C1->CTLR1 |= 0x0400; // CTLR1_ACK_Set - Enable ACK following each byte received - This also stops the clock stretching for each character received.

 ///   set_anod1(0);
 ///   set_anod2(0);
 ///   show_val(0,0);
#if 0
    for(;;)
    {
 ///   show_val(tst,0);

 ////       set_anod1(tst&0x1);
  ///      set_caths(tst&0xf);
     tst++;
  ///   if(tst>9)
  ///       tst=0;
 ///    tst&=0xf;
     cur_val=tst;
 ///    tst^=0xff;
     Delay_Ms(500);
    }
#endif
 while(1)
    {
     if(I2C_GetFlagStatus(I2C1, I2C_FLAG_RXNE))
     {
         rdat= I2C_ReadRegister(I2C1, I2C_Register_DATAR);
         cur_val= bin_to_bcd(rdat);
         printf( "rdat:%02x:%02x\r\n",rdat ,cur_val);
      }
    }
}
///===================================================================
