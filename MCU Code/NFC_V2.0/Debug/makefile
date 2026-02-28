################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include NFC/subdir.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Drivers/BSP/Components/ST25DV/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
NFC_V0.2.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
NFC_V0.2.list \


# All Target
all: NFC_V0.2.elf secondary-outputs

# Tool invocations
NFC_V0.2.elf: $(OBJS) $(USER_OBJS) C:\Users\mhn\Desktop\Door\ NFC\Program\V0\NFC_V0.2\NFC_V0.2\STM32F070F6PX_FLASH.ld
	arm-none-eabi-gcc -o "NFC_V0.2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"C:\Users\mhn\Desktop\Door NFC\Program\V0\NFC_V0.2\NFC_V0.2\STM32F070F6PX_FLASH.ld" --specs=nosys.specs -Wl,-Map="NFC_V0.2.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

NFC_V0.2.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "NFC_V0.2.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
