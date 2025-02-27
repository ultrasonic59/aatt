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
                               ,BIT_A|BIT_B|BIT_C|BIT_D|BIT_F|BIT_G  //
 };

void set_dig(uint8_t t_dig)
{
 if(t_dig > NUM_DIG)
     t_dig=NUM_DIG;
uint8_t t_symb=tbl_7s[t_dig];
set_caths(t_symb);
}
static uint8_t cur_cnt=0;

void show_val()
{
if(cur_cnt&0x1)
   {
    set_anods(0x1);
    set_caths(cur_val>>4);
   }
else
    {
    set_anods(0x0);
    set_caths(cur_val&0xf);
    }
cur_cnt++;
}
///====================================================================
/* some bit definitions for systick regs */
#define SYSTICK_SR_CNTIF (1<<0)
#define SYSTICK_CTLR_STE (1<<0)
#define SYSTICK_CTLR_STIE (1<<1)
#define SYSTICK_CTLR_STCLK (1<<2)
#define SYSTICK_CTLR_STRE (1<<3)
#define SYSTICK_CTLR_SWIE (1<<31)

volatile uint32_t systick_cnt;
#if 0
/*
 * Start up the SysTick IRQ
 */
void systick_init(void)
{
    /* disable default SysTick behavior */
    SysTick->CTLR = 0;

    /* enable the SysTick IRQ */
    NVIC_EnableIRQ(SysTicK_IRQn);

    /* Set the tick interval to 1ms for normal op */
    SysTick->CMP = (FUNCONF_SYSTEM_CORE_CLOCK/1000)-1;

    /* Start at zero */
    SysTick->CNT = 0;
    systick_cnt = 0;

    /* Enable SysTick counter, IRQ, HCLK/1 */
    SysTick->CTLR = SYSTICK_CTLR_STE | SYSTICK_CTLR_STIE |
                    SYSTICK_CTLR_STCLK;
}
#endif
#if 0
/*
 * SysTick ISR just counts ticks
 * note - the __attribute__((interrupt)) syntax is crucial!
 */
void SysTick_Handler(void) __attribute__((interrupt));
void SysTick_Handler(void)
{
    // move the compare further ahead in time.
    // as a warning, if more than this length of time
    // passes before triggering, you may miss your
    // interrupt.
    SysTick->CMP += (FUNCONF_SYSTEM_CORE_CLOCK/1000);

    /* clear IRQ */
    SysTick->SR = 0;

    /* update counter */
    systick_cnt++;
}
#endif
/*********************************************************************
 * @fn      TIM1_OutCompare_Init
 *
 * @brief   Initializes TIM1 output compare.
 *
 * @param   arr - the period value.
 *          psc - the prescaler value.
 *          ccp - the pulse value.
 *
 * @return  none
 */
void TIM1_PWMOut_Init(u16 arr, u16 psc, u16 ccp)
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    TIM_OCInitTypeDef TIM_OCInitStructure={0};
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure={0};

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD | RCC_APB2Periph_TIM1, ENABLE );

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( GPIOD, &GPIO_InitStructure );

    TIM_TimeBaseInitStructure.TIM_Period = arr;
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit( TIM1, &TIM_TimeBaseInitStructure);

#if (PWM_MODE == PWM_MODE1)
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;

#elif (PWM_MODE == PWM_MODE2)
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;

#endif

    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = ccp;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init( TIM1, &TIM_OCInitStructure );

    TIM_CtrlPWMOutputs(TIM1, ENABLE );
    TIM_OC1PreloadConfig( TIM1, TIM_OCPreload_Disable );
    TIM_ARRPreloadConfig( TIM1, ENABLE );
    TIM_Cmd( TIM1, ENABLE );
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

    I2C_DMACmd( I2C1, ENABLE );

    I2C_Cmd( I2C1, ENABLE );

#if (I2C_MODE == HOST_MODE)
    I2C_AcknowledgeConfig( I2C1, ENABLE );

#endif
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
    IIC_Init( 80000, RXAdderss );

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
#if 0
void I2C1_ER_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      I2C1_ER_IRQHandler
 *
 * @brief   This function IIC PEC error exception.
 *
 * @return  none
 */
void I2C1_ER_IRQHandler(void )
{
    if( I2C_GetITStatus( I2C1, I2C_IT_PECERR ) != RESET )
    {
        printf( "PECEER\r\n" );
        I2C_ClearITPendingBit( I2C1, I2C_IT_PECERR );
    }
}

#endif

///==================================================================================
#if 0
/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
    SystemCoreClockUpdate();
    Delay_Init();
#if (SDI_PRINT == SDI_PR_OPEN)
    SDI_Printf_Enable();
#else
    USART_Printf_Init(115200);
#endif
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );

    NVIC_EnableIRQ(SysTicK_IRQn);
    SysTick->SR &= ~(1 << 0);
    SysTick->CMP = SystemCoreClock-1;
    SysTick->CNT = 0;
    SysTick->CTLR = 0xF;

    while(1);
}

void SysTick_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));

/*********************************************************************
 * @fn      ADC1_IRQHandler
 *
 * @brief   ADC1_2 Interrupt Service Function.
 *
 * @return  none
 */
void SysTick_Handler(void)
{
    printf("Systick\r\n");
    SysTick->SR = 0;
}
#endif
///===================================================================
