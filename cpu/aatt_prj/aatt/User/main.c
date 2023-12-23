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

#include "../brd/aatt_brd.h"

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
const uint8_t tbl_db_rel[MAX_DB+1]={0,R1DB,R2DB,R1DB|R2DB,R4DB,R1DB|R4DB
                        ,R2DB|R4DB, R1DB|R2DB|R4DB,R8DB , R1DB|R8DB, R2DB|R8DB
                        ,R1DB|R2DB|R8DB,R4DB|R8DB,R1DB|R4DB|R8DB,R2DB|R4DB|R8DB,R1DB|R2DB|R4DB|R8DB
                        ,R16DB,R1DB|R16DB,R2DB|R16DB,R1DB|R2DB|R16DB,R20_0DB
                        ,R1DB|R20_0DB,R2DB|R20_0DB,R1DB|R2DB|R20_0DB,R4DB|R20_0DB,R1DB|R4DB|R20_0DB    ///21...25
                        ,R2DB|R4DB|R20_0DB,R1DB|R2DB|R4DB|R20_0DB,R8DB|R20_0DB,R1DB|R8DB|R20_0DB,R2DB|R8DB|R20_0DB ///26...30
                        ,R1DB|R2DB|R8DB|R20_0DB,R4DB|R8DB|R20_0DB,R1DB|R4DB|R8DB|R20_0DB,R2DB|R4DB|R8DB|R20_0DB,R1DB|R2DB|R4DB|R8DB|R20_0DB ///31...35
                        ,R16DB|R20_0DB,R1DB|R16DB|R20_0DB,R2DB|R16DB|R20_0DB,R1DB|R2DB|R16DB|R20_0DB,R20_1DB|R20_0DB  ///36...40
                        ,R1DB|R20_1DB|R20_0DB,R2DB|R20_1DB|R20_0DB,R1DB|R2DB|R20_1DB|R20_0DB,R4DB|R20_1DB|R20_0DB,R1DB|R4DB|R20_1DB|R20_0DB ///41...45
                        ,R2DB|R4DB|R20_1DB|R20_0DB,R1DB|R2DB|R4DB|R20_1DB|R20_0DB,R8DB|R20_1DB|R20_0DB,R1DB|R8DB|R20_1DB|R20_0DB,R2DB|R8DB|R20_1DB|R20_0DB ///46...50
               ,R1DB|R2DB|R8DB|R20_1DB|R20_0DB,R4DB|R8DB|R20_1DB|R20_0DB,R1DB|R4DB|R8DB|R20_1DB|R20_0DB,R2DB|R4DB|R8DB|R20_1DB|R20_0DB,R1DB|R2DB|R4DB|R8DB|R20_1DB|R20_0DB///51...55
               ,R16DB|R20_1DB|R20_0DB,R1DB|R16DB|R20_1DB|R20_0DB,R2DB|R16DB|R20_1DB|R20_0DB,R1DB|R2DB|R16DB|R20_1DB|R20_0DB ,R20_2DB|R20_1DB|R20_0DB ///56...60
               ,R1DB|R20_2DB|R20_1DB|R20_0DB,R2DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R2DB|R20_2DB|R20_1DB|R20_0DB ///61...63
               ,R4DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R4DB|R20_2DB|R20_1DB|R20_0DB,R2DB|R4DB|R20_2DB|R20_1DB|R20_0DB ///64...66
               ,R1DB|R2DB|R4DB|R20_2DB|R20_1DB|R20_0DB,R8DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R8DB|R20_2DB|R20_1DB|R20_0DB///67...69
               ,R2DB|R8DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R2DB|R8DB|R20_2DB|R20_1DB|R20_0DB ///70,71
               ,R4DB|R8DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R4DB|R8DB|R20_2DB|R20_1DB|R20_0DB ///72,73
               ,R2DB|R4DB|R8DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R2DB|R4DB|R8DB|R20_2DB|R20_1DB|R20_0DB  ///74,75
               ,R16DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R16DB|R20_2DB|R20_1DB|R20_0DB    /// 75,77
               ,R2DB|R16DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R2DB|R16DB|R20_2DB|R20_1DB|R20_0DB ///78,79
               ,R4DB|R16DB|R20_2DB|R20_1DB|R20_0DB ,R1DB|R4DB|R16DB|R20_2DB|R20_1DB|R20_0DB ///80,81
               ,R2DB|R4DB|R16DB|R20_2DB|R20_1DB|R20_0DB ,R1DB|R2DB|R4DB|R16DB|R20_2DB|R20_1DB|R20_0DB ///82,83
               ,R8DB|R16DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R8DB|R16DB|R20_2DB|R20_1DB|R20_0DB  ///84,85
               ,R2DB|R8DB|R16DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R2DB|R8DB|R16DB|R20_2DB|R20_1DB|R20_0DB  ///86,87
               ,R4DB|R8DB|R16DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R4DB|R8DB|R16DB|R20_2DB|R20_1DB|R20_0DB  //88,89
               ,R2DB|R4DB|R8DB|R16DB|R20_2DB|R20_1DB|R20_0DB,R1DB|R2DB|R4DB|R8DB|R16DB|R20_2DB|R20_1DB|R20_0DB ///90,91
};

void set_rele_db(uint8_t t_db)
{
 if(t_db > MAX_DB)
     t_db=MAX_DB;
uint8_t t_rel=tbl_db_rel[t_db];
set_reles(t_rel);
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
////uint8_t t_rel =0;
uint8_t t_db =0;
uint8_t ii =0;

 uint8_t in_buf[LEN_BUF] ;
 uint8_t out_buf[LEN_BUF] ;
 uint8_t cur_cnt=0;
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
#if 0
    for(;;)
    {
        set_reles(tst);
 ////    tst++;
     tst^=0xff;
     Delay_Ms(500);
    }
#endif

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
}
