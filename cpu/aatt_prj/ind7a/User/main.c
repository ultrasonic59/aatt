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


/* Global Variable */
vu8 val;

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
                               ,BIT_A|BIT_B|BIT_C|BIT_D|BIT_F|BIT_G  //
 };

void set_dig(uint8_t t_dig)
{
 if(t_dig > NUM_DIG)
     t_dig=NUM_DIG;
uint8_t t_symb=tbl_7s[t_dig];
set_caths(t_symb);
}

///===================================================
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
uint8_t tst =0;
///uint8_t t_db =0;
///uint8_t ii =0;

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
#if 1
    for(;;)
    {
        set_caths(tst&0xf);
     tst++;
 ///    tst^=0xff;
     Delay_Ms(500);
    }
#endif
#if 0
    while(1)
    {
        while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET)
        {
            /* waiting for receiving finish */
        }
        val = (USART_ReceiveData(USART1));
        in_buf[cur_cnt]=val;
        if(cur_cnt<LEN_BUF)
            cur_cnt++;
        if(val=='\r')
            {
            in_buf[cur_cnt-1]='\0';
            t_db=atoi(in_buf);
            set_rele_db(t_db);
            itoa(t_db+1,out_buf,16);
 ////           sprintf(out_buf,"%x\r\n",t_db);
            for(ii=0;ii< strlen(out_buf) ;ii++)
                {
                USART_SendData(USART1, out_buf[ii]);
                while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
                    {
                 /* waiting for sending finish */
                    }
                }
            cur_cnt=0;
            }

    }
#endif
}
