################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../usb/ch32x035_usbfs_device.c \
../usb/usb_desc.c 

OBJS += \
./usb/ch32x035_usbfs_device.o \
./usb/usb_desc.o 

C_DEPS += \
./usb/ch32x035_usbfs_device.d \
./usb/usb_desc.d 


# Each subdirectory must supply rules for building sources it contributes
usb/%.o: ../usb/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"E:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Core" -I"E:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\User" -I"E:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Peripheral\inc" -I"E:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\brd" -I"E:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\usb" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

