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
Core/core_riscv.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Core/core_riscv.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

