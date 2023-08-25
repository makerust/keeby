################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/keeb/keeb.c 

OBJS += \
./Drivers/keeb/keeb.o 

C_DEPS += \
./Drivers/keeb/keeb.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/keeb/%.o: ../Drivers/keeb/%.c Drivers/keeb/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F070xB -c -I../Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-keeb

clean-Drivers-2f-keeb:
	-$(RM) ./Drivers/keeb/keeb.d ./Drivers/keeb/keeb.o

.PHONY: clean-Drivers-2f-keeb

