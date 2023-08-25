################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd_ex.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.c \
../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_usart.c 

OBJS += \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd_ex.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.o \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_usart.o 

C_DEPS += \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd_ex.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.d \
./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_usart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F0xx_HAL_Driver/Src/%.o: ../Drivers/STM32F0xx_HAL_Driver/Src/%.c Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F070xB -c -I../Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc -I../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/HID/Inc -I../Drivers/CMSIS/Device/ST/STM32F0xx/Include -I../Drivers/CMSIS/Include -Og -ffunction-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F0xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32F0xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd_ex.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pcd_ex.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.o ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_usart.d ./Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_usart.o

.PHONY: clean-Drivers-2f-STM32F0xx_HAL_Driver-2f-Src

