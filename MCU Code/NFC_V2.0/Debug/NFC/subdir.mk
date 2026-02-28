################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../NFC/custom_nfc04a1.c \
../NFC/custom_nfc04a1_nfctag.c 

OBJS += \
./NFC/custom_nfc04a1.o \
./NFC/custom_nfc04a1_nfctag.o 

C_DEPS += \
./NFC/custom_nfc04a1.d \
./NFC/custom_nfc04a1_nfctag.d 


# Each subdirectory must supply rules for building sources it contributes
NFC/custom_nfc04a1.o: ../NFC/custom_nfc04a1.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F070x6 -DDEBUG -c -I../NFC -I../NFC/Target -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/ST25DV -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"NFC/custom_nfc04a1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
NFC/custom_nfc04a1_nfctag.o: ../NFC/custom_nfc04a1_nfctag.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F070x6 -DDEBUG -c -I../NFC -I../NFC/Target -I../Core/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -I../Drivers/BSP/Components/ST25DV -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"NFC/custom_nfc04a1_nfctag.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

