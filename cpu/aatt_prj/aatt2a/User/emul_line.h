#ifndef _EMUL_LINE_H__
#define _EMUL_LINE_H__
#include "usb_desc.h"
///==============================================
#define DEF_TX_BUF_LEN       ( 4 * 512 )
#define DEF_RX_BUF_LEN       ( 2 * 512 )
#define DEF_USB_FS_PACK_LEN        DEF_USBD_FS_PACK_SIZE                        /* USB full speed mode packet size for serial x data */
#define DEF_RX_BUF_NUM_MAX   ( DEF_RX_BUF_LEN / DEF_USB_FS_PACK_LEN )
#define MAX_RX_BUF_LEN      64
#define MAX_TX_BUF_LEN      64
extern __attribute__ ((aligned(4))) uint8_t  USB_Rx_Buf[ DEF_RX_BUF_LEN ];
extern __attribute__ ((aligned(4))) uint8_t  USB_Tx_Buf[ DEF_TX_BUF_LEN ];

extern uint8_t RCC_Configuration( void );

extern volatile uint16_t USB_Rx_PackLen[ DEF_RX_BUF_NUM_MAX ];                    /*  */
extern volatile uint16_t USB_Rx_LoadNum;                                                /*  */
extern volatile uint16_t USB_Rx_DealNum;                                                /* */
extern volatile uint16_t USB_Rx_RemainNum;                                              /*  */
extern uint8_t  USB_Down_StopFlag;                                                  /*  */
extern int send_to_usb(uint16_t offs,uint8_t len);
extern uint16_t check_usb_data_rdy();
extern uint16_t get_usb_data_offs();
extern void init_cdc_usb(void);
extern uint8_t  usb_rx_b[];
extern uint8_t usb_rx_len;
extern uint8_t  usb_tx_b[];

///==============================================
#endif
