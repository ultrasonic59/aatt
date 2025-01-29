################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/core_riscv.c 

OBJS += \
./Core/core_riscv.o 

C_DEPS += \
./Core/core_riscv.d 


# Each subdirectory must supply rules for building sources it contributes
Core/%.o: ../Core/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Peripheral\inc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\usb" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\brd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

