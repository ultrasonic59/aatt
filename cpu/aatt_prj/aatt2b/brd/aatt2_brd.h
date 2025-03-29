#ifndef __AATT2_BRD_H__
#define __AATT2__BRD_H__
#include <stdint.h>
#include "debug.h"
#include "usb_desc.h"

///=====================================================
////=============rele1==================================
  #define RELE1_PIN          GPIO_Pin_14
  #define RELE1_GPIO         GPIOC
////=============rele2==================================
  #define RELE2_PIN          GPIO_Pin_15
  #define RELE2_GPIO         GPIOC
////=============rele3==================================
  #define RELE3_PIN          GPIO_Pin_8
  #define RELE3_GPIO         GPIOA
////=============rele4==================================
  #define RELE4_PIN          GPIO_Pin_9
  #define RELE4_GPIO         GPIOA
////=============rele5==================================
  #define RELE5_PIN          GPIO_Pin_3
  #define RELE5_GPIO         GPIOA
////=============rele6==================================
  #define RELE6_PIN          GPIO_Pin_4
  #define RELE6_GPIO         GPIOA
////=============rele7==================================
  #define RELE7_PIN          GPIO_Pin_5
  #define RELE7_GPIO         GPIOA
////=============rele8==================================
  #define RELE8_PIN          GPIO_Pin_6
  #define RELE8_GPIO         GPIOA
////============= uart_dbg_tx ==================================
  #define UART_DBG_TX_PIN          GPIO_Pin_15
  #define UART_DBG_TX_GPIO         GPIOA
////============= uart_dbg_rx ==================================
  #define UART_DBG_RX_PIN          GPIO_Pin_16
  #define UART_DBG_RX_GPIO         GPIOA
///================ i2c_scl ==============================
  #define I2C_SCL_PIN          GPIO_Pin_13
  #define I2C_SCL_GPIO         GPIOA
///================ i2c_sda ==============================
  #define I2C_SDA_PIN          GPIO_Pin_14
  #define I2C_SDA_GPIO         GPIOA

///=============kk0==================================
  #define KK0_PIN          GPIO_Pin_7
  #define KK0_GPIO         GPIOA
///=============kk1==================================
  #define KK1_PIN          GPIO_Pin_6
  #define KK1_GPIO         GPIOC
///=============kk2==================================
  #define KK2_PIN          GPIO_Pin_7
  #define KK2_GPIO         GPIOC
///=============kk3==================================
  #define KK3_PIN          GPIO_Pin_0
  #define KK3_GPIO         GPIOB
///=============kk4==================================
  #define KK4_PIN          GPIO_Pin_1
  #define KK4_GPIO         GPIOB
///=============kk5==================================
  #define KK5_PIN          GPIO_Pin_2
  #define KK5_GPIO         GPIOB
///=============kk6==================================
  #define KK6_PIN          GPIO_Pin_3
  #define KK6_GPIO         GPIOB
///=============kk7==================================
  #define KK7_PIN          GPIO_Pin_4
  #define KK7_GPIO         GPIOB
///=============kk8==================================
  #define KK8_PIN          GPIO_Pin_5
  #define KK8_GPIO         GPIOB
///=============kk9==================================
  #define KK9_PIN          GPIO_Pin_6
  #define KK9_GPIO         GPIOB
///=============kk10==================================
  #define KK10_PIN          GPIO_Pin_7
  #define KK10_GPIO         GPIOB
///=============kk11==================================
  #define KK11_PIN          GPIO_Pin_8
  #define KK11_GPIO         GPIOB
///=============kk12==================================
  #define KK12_PIN          GPIO_Pin_9
  #define KK12_GPIO         GPIOB
///=============kk13==================================
  #define KK13_PIN          GPIO_Pin_10
  #define KK13_GPIO         GPIOB
///=============kk14==================================
  #define KK14_PIN          GPIO_Pin_11
  #define KK14_GPIO         GPIOB
////====================================================


#if 0
///============= OUT6 ==================================
  #define OUT6_PIN          GPIO_Pin_0
  #define OUT6_GPIO         GPIOB
  ////============= OUT5 ==================================
  #define OUT5_PIN          GPIO_Pin_1
  #define OUT5_GPIO         GPIOB
  ////============= OUT4 ==================================
  #define OUT4_PIN          GPIO_Pin_3
  #define OUT4_GPIO         GPIOB
  ////============= OUT3 ==================================
  #define OUT3_PIN          GPIO_Pin_11
  #define OUT3_GPIO         GPIOB
  ////============= OUT2 ==================================
  #define OUT2_PIN          GPIO_Pin_12
  #define OUT2_GPIO         GPIOB
  ////============= OUT1 ==================================
  #define OUT1_PIN          GPIO_Pin_14
  #define OUT1_GPIO         GPIOC
  ////============= OUT0 ==================================
  #define OUT0_PIN          GPIO_Pin_15
  #define OUT0_GPIO         GPIOC
///============= IN0 ==================================
  #define IN0_PIN          GPIO_Pin_0
  #define IN0_GPIO         GPIOA
///============= IN1 ==================================
  #define IN1_PIN          GPIO_Pin_1
  #define IN1_GPIO         GPIOA
///============= IN2 ==================================
  #define IN2_PIN          GPIO_Pin_4
  #define IN2_GPIO         GPIOA
///============= IN3 ==================================
  #define IN3_PIN          GPIO_Pin_5
  #define IN3_GPIO         GPIOA
///============= IN4 ==================================
  #define IN4_PIN          GPIO_Pin_6
  #define IN4_GPIO         GPIOA
///============= IN5 ==================================
  #define IN5_PIN          GPIO_Pin_7
  #define IN5_GPIO         GPIOA
///===================================================
#endif
///===================================================
#define I2C_BR 100000
#define I2C_ADDR 0x2    ///0xa0
////#define I2C_ADDR_DB 0x01

#define MAX_DB 91
#define R1DB (0x1<<7)
#define R2DB (0x1<<6)
#define R4DB (0x1<<5)
#define R8DB (0x1<<4)
#define R16DB (0x1<<3)
#define R20_0DB (0x1<<2)
#define R20_1DB (0x1<<1)
#define R20_2DB (0x1<<0)
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

extern void gpio_init(void);
extern void board_init(void);

extern void set_reles(uint8_t i_on);
extern void set_led(uint8_t on_off);

extern void set_rele1(uint8_t on_off);
extern void set_rele2(uint8_t on_off);
extern void set_rele3(uint8_t on_off);
extern void set_rele4(uint8_t on_off);
extern void set_rele5(uint8_t on_off);
extern void set_rele6(uint8_t on_off);
extern void set_rele7(uint8_t on_off);
extern void set_rele8(uint8_t on_off);

extern void i2c_WriteOneByte(u8 DataToWrite);
///===================================================

#endif /// __BALOO_EMUL_LINE_BRD_H__


