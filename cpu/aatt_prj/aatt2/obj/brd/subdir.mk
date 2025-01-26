################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../brd/aatt_brd.c 

OBJS += \
./brd/aatt_brd.o 

C_DEPS += \
./brd/aatt_brd.d 


# Each subdirectory must supply rules for building sources it contributes
brd/%.o: ../brd/%.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

