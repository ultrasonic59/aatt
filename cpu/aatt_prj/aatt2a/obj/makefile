################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
aatt2a.hex \

SECONDARY_LIST += \
aatt2a.lst \

SECONDARY_SIZE += \
aatt2a.siz \


# All Target
all: aatt2a.elf secondary-outputs

# Tool invocations
aatt2a.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "D:\proj\velograph\aatt\cpu\aatt_prj\aatt2a\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"aatt2a.map" --specs=nano.specs --specs=nosys.specs -o "aatt2a.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
aatt2a.hex: aatt2a.elf
	@	riscv-none-embed-objcopy -O ihex "aatt2a.elf"  "aatt2a.hex"
	@	@
aatt2a.lst: aatt2a.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "aatt2a.elf" > "aatt2a.lst"
	@	@
aatt2a.siz: aatt2a.elf
	@	riscv-none-embed-size --format=berkeley "aatt2a.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) aatt2a.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
