################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../aatt/Debug/debug.c 

OBJS += \
./aatt/Debug/debug.o 

C_DEPS += \
./aatt/Debug/debug.d 


# Each subdirectory must supply rules for building sources it contributes
aatt/Debug/%.o: ../aatt/Debug/%.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

