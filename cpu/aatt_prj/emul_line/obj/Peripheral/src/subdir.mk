################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/src/ch32x035_adc.c \
../Peripheral/src/ch32x035_awu.c \
../Peripheral/src/ch32x035_dbgmcu.c \
../Peripheral/src/ch32x035_dma.c \
../Peripheral/src/ch32x035_exti.c \
../Peripheral/src/ch32x035_flash.c \
../Peripheral/src/ch32x035_gpio.c \
../Peripheral/src/ch32x035_i2c.c \
../Peripheral/src/ch32x035_iwdg.c \
../Peripheral/src/ch32x035_misc.c \
../Peripheral/src/ch32x035_opa.c \
../Peripheral/src/ch32x035_pwr.c \
../Peripheral/src/ch32x035_rcc.c \
../Peripheral/src/ch32x035_spi.c \
../Peripheral/src/ch32x035_tim.c \
../Peripheral/src/ch32x035_usart.c \
../Peripheral/src/ch32x035_wwdg.c 

OBJS += \
./Peripheral/src/ch32x035_adc.o \
./Peripheral/src/ch32x035_awu.o \
./Peripheral/src/ch32x035_dbgmcu.o \
./Peripheral/src/ch32x035_dma.o \
./Peripheral/src/ch32x035_exti.o \
./Peripheral/src/ch32x035_flash.o \
./Peripheral/src/ch32x035_gpio.o \
./Peripheral/src/ch32x035_i2c.o \
./Peripheral/src/ch32x035_iwdg.o \
./Peripheral/src/ch32x035_misc.o \
./Peripheral/src/ch32x035_opa.o \
./Peripheral/src/ch32x035_pwr.o \
./Peripheral/src/ch32x035_rcc.o \
./Peripheral/src/ch32x035_spi.o \
./Peripheral/src/ch32x035_tim.o \
./Peripheral/src/ch32x035_usart.o \
./Peripheral/src/ch32x035_wwdg.o 

C_DEPS += \
./Peripheral/src/ch32x035_adc.d \
./Peripheral/src/ch32x035_awu.d \
./Peripheral/src/ch32x035_dbgmcu.d \
./Peripheral/src/ch32x035_dma.d \
./Peripheral/src/ch32x035_exti.d \
./Peripheral/src/ch32x035_flash.d \
./Peripheral/src/ch32x035_gpio.d \
./Peripheral/src/ch32x035_i2c.d \
./Peripheral/src/ch32x035_iwdg.d \
./Peripheral/src/ch32x035_misc.d \
./Peripheral/src/ch32x035_opa.d \
./Peripheral/src/ch32x035_pwr.d \
./Peripheral/src/ch32x035_rcc.d \
./Peripheral/src/ch32x035_spi.d \
./Peripheral/src/ch32x035_tim.d \
./Peripheral/src/ch32x035_usart.d \
./Peripheral/src/ch32x035_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/ch32x035_adc.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_adc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_awu.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_awu.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_dbgmcu.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_dbgmcu.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_dma.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_dma.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_exti.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_exti.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_flash.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_flash.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_gpio.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_gpio.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_i2c.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_i2c.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_iwdg.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_iwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_misc.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_misc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_opa.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_opa.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_pwr.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_pwr.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_rcc.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_rcc.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_spi.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_spi.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_tim.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_tim.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_usart.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_usart.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
Peripheral/src/ch32x035_wwdg.o: D:/proj/velograph/aatt/cpu/aatt_prj/emul_line/Peripheral/src/ch32x035_wwdg.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Debug" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Core" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\User" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Peripheral\inc" -I"/emul_line/calc_crc" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\brd" -I"D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\pc_cmd" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

