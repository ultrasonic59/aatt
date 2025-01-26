################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../aatt/User/ch32v00x_it.c \
../aatt/User/main.c \
../aatt/User/system_ch32v00x.c 

OBJS += \
./aatt/User/ch32v00x_it.o \
./aatt/User/main.o \
./aatt/User/system_ch32v00x.o 

C_DEPS += \
./aatt/User/ch32v00x_it.d \
./aatt/User/main.d \
./aatt/User/system_ch32v00x.d 


# Each subdirectory must supply rules for building sources it contributes
aatt/User/%.o: ../aatt/User/%.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

