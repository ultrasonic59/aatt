################################################################################
# MRS Version: 1.9.2
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include usb/subdir.mk
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
aatt2b.hex \

SECONDARY_LIST += \
aatt2b.lst \

SECONDARY_SIZE += \
aatt2b.siz \


# All Target
all: aatt2b.elf secondary-outputs

# Tool invocations
aatt2b.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "E:\proj\velograph\aatt\cpu\aatt_prj\aatt2b\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"aatt2b.map" --specs=nano.specs --specs=nosys.specs -o "aatt2b.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
aatt2b.hex: aatt2b.elf
	@	riscv-none-embed-objcopy -O ihex "aatt2b.elf"  "aatt2b.hex"
	@	@
aatt2b.lst: aatt2b.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "aatt2b.elf" > "aatt2b.lst"
	@	@
aatt2b.siz: aatt2b.elf
	@	riscv-none-embed-size --format=berkeley "aatt2b.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) aatt2b.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
