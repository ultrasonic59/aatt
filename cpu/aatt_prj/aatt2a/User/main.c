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
 *Example routine to emulate a simulate USB-CDC Device, USE USART2(PA2/PA3);
 *Please note: This code uses the default serial port 1 for debugging,
 *if you need to modify the debugging serial port, please do not use USART2
*/

#include <ch32x035_usbfs_device.h>
#include "debug.h"
///#include "emul_line.h"
///#include "emul_line_pc_cmd.h"
#include "aatt2_brd.h"

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
int main(void)
{
uint16_t t_len=0;
////uint16_t t_offs=0;
uint16_t ii=0;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    USART_Printf_Init(115200);
    printf("SystemClk:%d\r\n", SystemCoreClock);
    printf("ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
    RCC_Configuration( );

    /* Tim3 init */
/////    TIM3_Init( );

    /* Usart1 init */
 ////   UART2_Init( 1, DEF_UARTx_BAUDRATE, DEF_UARTx_STOPBIT, DEF_UARTx_PARITY );

    /* Usb Init */
    USBFS_RCC_Init( );
    USBFS_Device_Init( ENABLE , PWR_VDD_SupplyVoltage());

    init_cdc_usb();
    board_init();
    NVIC_EnableIRQ( USBFS_IRQn );
    put_out_n(0x0);
    printf("\r\n start loop\r\n");

    while(1)
    {

        t_len=check_usb_data_rdy();
        if(t_len){
        ////    printf("\r\n t_len:[%x]\r\n", t_len);
        ///    for(ii=0;ii<t_len;ii++){
        ////        printf("[%x:%x]\r\n", ii,usb_rx_b[ii]);
        ////    }
            t_len=parse_cmd(usb_rx_b,t_len,usb_tx_b);
            if(t_len){
           ////     printf("\r\n t_len1:[%x]\r\n", t_len);

           for(ii=0;ii<t_len;ii++){
               USB_Tx_Buf[ii]= usb_tx_b[ii];
           }
               send_to_usb(0,t_len);

       ////    for(ii=0;ii<t_len;ii++){
       ////         printf("[%x:%x]\r\n", ii,usb_tx_b[ii]);
       ////     }
 ///       send_to_usb(0,t_len);
        }
        usb_rx_len=0;
        }
        else
 ///       USB_Tx_Buf[0]=0x34;
  ///      USB_Tx_Buf[1]=0x35;
 ///       send_to_usb(0,t_len);
   ////     UART2_DataRx_Deal( );
   ////     UART2_DataTx_Deal( );
        Delay_Ms(100);
    }
}
