################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../aatt/Peripheral/src/ch32v00x_adc.c \
../aatt/Peripheral/src/ch32v00x_dbgmcu.c \
../aatt/Peripheral/src/ch32v00x_dma.c \
../aatt/Peripheral/src/ch32v00x_exti.c \
../aatt/Peripheral/src/ch32v00x_flash.c \
../aatt/Peripheral/src/ch32v00x_gpio.c \
../aatt/Peripheral/src/ch32v00x_i2c.c \
../aatt/Peripheral/src/ch32v00x_iwdg.c \
../aatt/Peripheral/src/ch32v00x_misc.c \
../aatt/Peripheral/src/ch32v00x_opa.c \
../aatt/Peripheral/src/ch32v00x_pwr.c \
../aatt/Peripheral/src/ch32v00x_rcc.c \
../aatt/Peripheral/src/ch32v00x_spi.c \
../aatt/Peripheral/src/ch32v00x_tim.c \
../aatt/Peripheral/src/ch32v00x_usart.c \
../aatt/Peripheral/src/ch32v00x_wwdg.c 

OBJS += \
./aatt/Peripheral/src/ch32v00x_adc.o \
./aatt/Peripheral/src/ch32v00x_dbgmcu.o \
./aatt/Peripheral/src/ch32v00x_dma.o \
./aatt/Peripheral/src/ch32v00x_exti.o \
./aatt/Peripheral/src/ch32v00x_flash.o \
./aatt/Peripheral/src/ch32v00x_gpio.o \
./aatt/Peripheral/src/ch32v00x_i2c.o \
./aatt/Peripheral/src/ch32v00x_iwdg.o \
./aatt/Peripheral/src/ch32v00x_misc.o \
./aatt/Peripheral/src/ch32v00x_opa.o \
./aatt/Peripheral/src/ch32v00x_pwr.o \
./aatt/Peripheral/src/ch32v00x_rcc.o \
./aatt/Peripheral/src/ch32v00x_spi.o \
./aatt/Peripheral/src/ch32v00x_tim.o \
./aatt/Peripheral/src/ch32v00x_usart.o \
./aatt/Peripheral/src/ch32v00x_wwdg.o 

C_DEPS += \
./aatt/Peripheral/src/ch32v00x_adc.d \
./aatt/Peripheral/src/ch32v00x_dbgmcu.d \
./aatt/Peripheral/src/ch32v00x_dma.d \
./aatt/Peripheral/src/ch32v00x_exti.d \
./aatt/Peripheral/src/ch32v00x_flash.d \
./aatt/Peripheral/src/ch32v00x_gpio.d \
./aatt/Peripheral/src/ch32v00x_i2c.d \
./aatt/Peripheral/src/ch32v00x_iwdg.d \
./aatt/Peripheral/src/ch32v00x_misc.d \
./aatt/Peripheral/src/ch32v00x_opa.d \
./aatt/Peripheral/src/ch32v00x_pwr.d \
./aatt/Peripheral/src/ch32v00x_rcc.d \
./aatt/Peripheral/src/ch32v00x_spi.d \
./aatt/Peripheral/src/ch32v00x_tim.d \
./aatt/Peripheral/src/ch32v00x_usart.d \
./aatt/Peripheral/src/ch32v00x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
aatt/Peripheral/src/%.o: ../aatt/Peripheral/src/%.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

