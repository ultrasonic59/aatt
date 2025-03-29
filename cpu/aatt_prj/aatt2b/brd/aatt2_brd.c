
#include "aatt2_brd.h"

void init_gpio(void)
{
GPIO_InitTypeDef  GPIO_InitStructure = {0};
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

///RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
///=============rele1==================================
GPIO_InitStructure.GPIO_Pin = RELE1_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(RELE1_GPIO, &GPIO_InitStructure);
///=============rele2==================================
GPIO_InitStructure.GPIO_Pin = RELE2_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(RELE2_GPIO, &GPIO_InitStructure);
///=============rele3==================================
GPIO_InitStructure.GPIO_Pin = RELE3_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(RELE3_GPIO, &GPIO_InitStructure);
///=============rele4==================================
GPIO_InitStructure.GPIO_Pin = RELE4_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(RELE4_GPIO, &GPIO_InitStructure);
///=============rele5==================================
GPIO_InitStructure.GPIO_Pin = RELE5_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(RELE5_GPIO, &GPIO_InitStructure);
///=============rele6==================================
GPIO_InitStructure.GPIO_Pin = RELE6_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(RELE6_GPIO, &GPIO_InitStructure);
///=============rele7==================================
GPIO_InitStructure.GPIO_Pin = RELE7_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(RELE7_GPIO, &GPIO_InitStructure);
///=============rele8==================================
GPIO_InitStructure.GPIO_Pin = RELE8_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(RELE8_GPIO, &GPIO_InitStructure);
///=============kk0==================================
GPIO_InitStructure.GPIO_Pin = KK0_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(KK0_GPIO, &GPIO_InitStructure);
////=============kk14==================================
GPIO_InitStructure.GPIO_Pin = KK14_PIN;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(KK14_GPIO, &GPIO_InitStructure);
///========== uart_dbg_tx =============================
GPIO_InitStructure.GPIO_Pin = UART_DBG_TX_PIN;
///GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;

GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(UART_DBG_TX_GPIO, &GPIO_InitStructure);
GPIO_PinRemapConfig( GPIO_FullRemap_USART2, ENABLE);


}
///=============== led kk14 =======================================
void set_led(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(KK14_GPIO,KK14_PIN,Bit_SET);
 else
     GPIO_WriteBit(KK14_GPIO,KK14_PIN, Bit_RESET);
}
void set_kk0(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(KK0_GPIO,KK0_PIN,Bit_SET);
 else
     GPIO_WriteBit(GPIOA,GPIO_Pin_15, Bit_RESET);
}

///=============== rele1 =======================================
void set_rele1(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE1_GPIO,RELE1_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE1_GPIO,RELE1_PIN, Bit_RESET);
}
///=============== rele2 =======================================
void set_rele2(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE2_GPIO,RELE2_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE2_GPIO,RELE2_PIN, Bit_RESET);
}
///=============== rele3 =======================================
void set_rele3(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE3_GPIO,RELE3_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE3_GPIO,RELE3_PIN, Bit_RESET);
}
///=============== rele4 =======================================
void set_rele4(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE4_GPIO,RELE4_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE4_GPIO,RELE4_PIN, Bit_RESET);
}
///=============== rele5 =======================================
void set_rele5(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE5_GPIO,RELE5_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE5_GPIO,RELE5_PIN, Bit_RESET);
}
///=============== rele6 =======================================
void set_rele6(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE6_GPIO,RELE6_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE6_GPIO,RELE6_PIN, Bit_RESET);
}
///=============== rele7 =======================================
void set_rele7(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE7_GPIO,RELE7_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE7_GPIO,RELE7_PIN, Bit_RESET);
}
///=============== rele8 =======================================
void set_rele8(uint8_t on_off)
{
 if(on_off&0x1)
     GPIO_WriteBit(RELE8_GPIO,RELE8_PIN,Bit_SET);
 else
     GPIO_WriteBit(RELE8_GPIO,RELE8_PIN, Bit_RESET);
}
///===============reles=========================================
void set_reles(uint8_t i_on)
{
if(i_on&(0x1<<0))
    set_rele1(0x1);
else
    set_rele1(0x0);

if(i_on&(0x1<<1))
    set_rele2(0x1);
else
    set_rele2(0x0);

if(i_on&(0x1<<2))
    set_rele3(0x1);
else
    set_rele3(0x0);

if(i_on&(0x1<<3))
    set_rele4(0x1);
else
    set_rele4(0x0);

if(i_on&(0x1<<4))
    set_rele5(0x1);
else
    set_rele5(0x0);

if(i_on&(0x1<<5))
    set_rele6(0x1);
else
    set_rele6(0x0);

if(i_on&(0x1<<6))
    set_rele7(0x1);
else
    set_rele7(0x0);

if(i_on&(0x1<<7))
    set_rele8(0x1);
else
    set_rele8(0x0);

}
uint8_t RCC_Configuration( void )
{
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_USART2, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_TIM3, ENABLE );
    RCC_AHBPeriphClockCmd( RCC_AHBPeriph_DMA1, ENABLE );
    return 0;
}

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
void IIC_Init()
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    I2C_InitTypeDef I2C_InitTSturcture={0};
    GPIO_PinRemapConfig( GPIO_PartialRemap1_I2C1, ENABLE);

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE );
    RCC_APB1PeriphClockCmd( RCC_APB1Periph_I2C1, ENABLE );

    GPIO_InitStructure.GPIO_Pin = I2C_SCL_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( I2C_SCL_GPIO, &GPIO_InitStructure );

    GPIO_InitStructure.GPIO_Pin = I2C_SDA_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( I2C_SDA_GPIO, &GPIO_InitStructure );

    I2C_InitTSturcture.I2C_ClockSpeed = I2C_BR;
    I2C_InitTSturcture.I2C_Mode = I2C_Mode_I2C;
    I2C_InitTSturcture.I2C_DutyCycle = I2C_DutyCycle_2;
    I2C_InitTSturcture.I2C_OwnAddress1 = I2C_ADDR;
    I2C_InitTSturcture.I2C_Ack = I2C_Ack_Enable;
    I2C_InitTSturcture.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
    I2C_Init( I2C1, &I2C_InitTSturcture );

    I2C_Cmd( I2C1, ENABLE );

    I2C_AcknowledgeConfig( I2C1, ENABLE );
}
void i2c_WriteOneByte(u8 DataToWrite)
{
    while( I2C_GetFlagStatus( I2C1, I2C_FLAG_BUSY ) != RESET );
    I2C_GenerateSTART( I2C1, ENABLE );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_MODE_SELECT ) );
    I2C_Send7bitAddress( I2C1, I2C_ADDR, I2C_Direction_Transmitter );

    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED ) );

///    I2C_SendData( I2C1, (u8)(WriteAddr&0x00FF) );
 ////   while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );

 ///   if( I2C_GetFlagStatus( I2C1, I2C_FLAG_TXE ) !=  RESET )
    {
        I2C_SendData( I2C1, DataToWrite );
    }
    while( !I2C_CheckEvent( I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED ) );
    I2C_GenerateSTOP( I2C1, ENABLE );
}

void board_init(void)
{
    init_gpio();
    IIC_Init();
}
