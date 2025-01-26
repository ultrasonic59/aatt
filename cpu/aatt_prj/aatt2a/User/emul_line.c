#include <stdint.h>
#include  "emul_line.h"
#include <ch32x035_usbfs_device.h>

__attribute__ ((aligned(4))) uint8_t  USB_Rx_Buf[ DEF_RX_BUF_LEN ];
__attribute__ ((aligned(4))) uint8_t  USB_Tx_Buf[ DEF_TX_BUF_LEN ];

////volatile uint16_t Tx_PackLen[ DEF_UARTx_TX_BUF_NUM_MAX ];                    /* The current packet length */
volatile uint16_t USB_Rx_PackLen[ DEF_RX_BUF_NUM_MAX ];                    /*  */
volatile uint16_t USB_Rx_LoadNum;                                                /*  */
volatile uint16_t USB_Rx_DealNum;                                                /* */
volatile uint16_t USB_Rx_RemainNum;                                              /*  */
uint8_t  USB_Down_StopFlag;
uint8_t  usb_rx_b[ MAX_RX_BUF_LEN ];
uint8_t usb_rx_len=0;
uint8_t  usb_tx_b[ MAX_TX_BUF_LEN ];

uint8_t RCC_Configuration( void )
{
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_USART2, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE );
    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_DMA1, ENABLE );
    return 0;
}

int send_to_usb(uint16_t offs,uint8_t len){
if( len )
    {
////    printf("\r\n send_to_usb[%x]\r\n",len);
        NVIC_DisableIRQ( USBFS_IRQn );
///        Uart.USB_Up_IngFlag = 0x01;
///        Uart.USB_Up_TimeOut = 0x00;
        USBFS_Endp_DataUp( DEF_UEP3, &USB_Tx_Buf[ offs ], len, DEF_UEP_CPY_LOAD );
        /* Calculate the variables of interest */
 ///       Uart.Rx_RemainLen -= packlen;
  ///      Uart.Rx_DealPtr += packlen;
#if 0
        if( Uart.Rx_DealPtr >= DEF_UARTx_RX_BUF_LEN )
        {
            Uart.Rx_DealPtr = 0x00;
        }

        /* Start 0-length packet timeout timer */
        if( packlen == DEF_USBD_FS_PACK_SIZE )
        {
            Uart.USB_Up_Pack0_Flag = 0x01;
        }
#endif
        NVIC_EnableIRQ( USBFS_IRQn );
    }
}
uint16_t check_usb_data_rdy()
{
return usb_rx_len;
}
/////Uart.Tx_CurPackLen = USB_Rx_PackLen[ USB_Rx_DealNum ];
 /////Uart.Tx_CurPackPtr = ( USB_Rx_DealNum * DEF_USB_FS_PACK_LEN );

void init_cdc_usb(void)
{
    uint16_t i;
USB_Rx_LoadNum = 0x00;
USB_Rx_DealNum = 0x00;
USB_Rx_RemainNum = 0x00;
for( i = 0; i < DEF_RX_BUF_NUM_MAX; i++ )
{
    USB_Rx_PackLen[ i ] = 0x00;
}
}
/*  */
