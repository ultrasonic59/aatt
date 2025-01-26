################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../brd/aatt2_brd.c 

OBJS += \
./brd/aatt2_brd.o 

C_DEPS += \
./brd/aatt2_brd.d 


# Each subdirectory must supply rules for building sources it contributes
brd/%.o: ../brd/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2a\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2a\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2a\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2a\Peripheral\inc" -I"/aatt2a/pc_cmd" -I"/aatt2a/calc_crc" -I"D:\proj\velograph\baloo\wch\emul_line\brd" -I"D:\proj\velograph\baloo\wch\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

