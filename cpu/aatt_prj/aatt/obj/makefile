################################################################################
# MRS Version: 1.9.1
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
aatt.hex \

SECONDARY_LIST += \
aatt.lst \

SECONDARY_SIZE += \
aatt.siz \


# All Target
all: aatt.elf secondary-outputs

# Tool invocations
aatt.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "D:\proj\velograph\aatt\cpu\aatt_prj\aatt\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"aatt.map" --specs=nano.specs --specs=nosys.specs -o "aatt.elf" $(OBJS) $(USER_OBJS) $(LIBS) -lprintf
	@	@
aatt.hex: aatt.elf
	@	riscv-none-embed-objcopy -O ihex "aatt.elf"  "aatt.hex"
	@	@
aatt.lst: aatt.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "aatt.elf" > "aatt.lst"
	@	@
aatt.siz: aatt.elf
	@	riscv-none-embed-size --format=berkeley "aatt.elf"
	@	@
# Other Targets
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) aatt.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
