################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include pc_cmd/subdir.mk
-include calc_crc/subdir.mk
-include brd/subdir.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
emul_line.hex \

SECONDARY_LIST += \
emul_line.lst \

SECONDARY_SIZE += \
emul_line.siz \


# All Target
all: emul_line.elf secondary-outputs

# Tool invocations
emul_line.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "D:\proj\velograph\aatt\cpu\aatt_prj\emul_line\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"emul_line.map" --specs=nano.specs --specs=nosys.specs -o "emul_line.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
emul_line.hex: emul_line.elf
	@	riscv-none-embed-objcopy -O ihex "emul_line.elf"  "emul_line.hex"
	@	@
emul_line.lst: emul_line.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "emul_line.elf" > "emul_line.lst"
	@	@
emul_line.siz: emul_line.elf
	@	riscv-none-embed-size --format=berkeley "emul_line.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) emul_line.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
