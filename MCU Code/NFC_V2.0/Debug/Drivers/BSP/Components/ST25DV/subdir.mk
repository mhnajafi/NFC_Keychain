################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/Components/ST25DV/st25dv.c \
../Drivers/BSP/Components/ST25DV/st25dv_reg.c 

OBJS += \
./Drivers/BSP/Components/ST25DV/st25dv.o \
./Drivers/BSP/Components/ST25DV/st25dv_reg.o 

C_DEPS += \
./Drivers/BSP/Components/ST25DV/st25dv.d \
./Drivers/BSP/Components/ST25DV/st25dv_reg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/Components/ST25DV/st25dv.o: ../Drivers/BSP/Components/ST25DV/st25dv.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F070x6 -DDEBUG -c -I../NFC -I../NFC/Target -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/ST25DV -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/ST25DV/st25dv.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/BSP/Components/ST25DV/st25dv_reg.o: ../Drivers/BSP/Components/ST25DV/st25dv_reg.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F070x6 -DDEBUG -c -I../NFC -I../NFC/Target -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/ST25DV -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/Components/ST25DV/st25dv_reg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

