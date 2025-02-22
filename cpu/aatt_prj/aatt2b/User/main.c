/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.0.0
 * Date               : 2023/12/26
 * Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
 *GPIO routine:
 *PA0 push-pull output.
 *
 ***Only PA0--PA15 and PC16--PC17 support input pull-down.
 */

#include <ch32x035_usbfs_device.h>
#include "debug.h"

#include "aatt2_brd.h"

__attribute__ ((aligned(4))) uint8_t  USB_Rx_Buf[ DEF_RX_BUF_LEN ];
__attribute__ ((aligned(4))) uint8_t  USB_Tx_Buf[ DEF_TX_BUF_LEN ];

volatile uint16_t USB_Rx_PackLen[ DEF_RX_BUF_NUM_MAX ];                    /*  */
volatile uint16_t USB_Rx_LoadNum;                                                /*  */
volatile uint16_t USB_Rx_DealNum;                                                /* */
volatile uint16_t USB_Rx_RemainNum;                                              /*  */
uint8_t  USB_Down_StopFlag;
uint8_t  usb_rx_b[ MAX_RX_BUF_LEN ];
uint8_t usb_rx_len=0;
uint8_t  usb_tx_b[ MAX_TX_BUF_LEN ];


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


/*********************************************************************
 * @fn      GPIO_Toggle_INIT
 *
 * @brief   Initializes GPIOA.0
 *
 * @return  none
 */
void GPIO_Toggle_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void)
{
 ///=======================================================
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf("ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    RCC_Configuration( );

    /* Usb Init */
    USBFS_RCC_Init( );
    USBFS_Device_Init( ENABLE , PWR_VDD_SupplyVoltage());

    init_cdc_usb();
    board_init();
    NVIC_EnableIRQ( USBFS_IRQn );
///    put_out_n(0x0);
    printf("\r\n start loop\r\n");
#if 0
    while(1)
    {
        t_len=check_usb_data_rdy();
        if(t_len){
            t_len=parse_cmd(usb_rx_b,t_len,usb_tx_b);
            if(t_len){

           for(ii=0;ii<t_len;ii++){
               USB_Tx_Buf[ii]= usb_tx_b[ii];
           }
               send_to_usb(0,t_len);

        }
        usb_rx_len=0;
        }
        else
        Delay_Ms(100);
    }
#endif

    ///====================================================
    u8 i = 0;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    printf("GPIO Toggle TEST\r\n");
    GPIO_Toggle_INIT();

    while(1)
    {
        Delay_Ms(500);
        GPIO_WriteBit(GPIOA, GPIO_Pin_0, (i == 0) ? (i = Bit_SET) : (i = Bit_RESET));
    }
}
