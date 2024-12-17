################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/pwr_modes.c \
../src/stm32f4xx_it.c \
../src/syscalls.c \
../src/system_stm32f4xx.c 

OBJS += \
./src/main.o \
./src/pwr_modes.o \
./src/stm32f4xx_it.o \
./src/syscalls.o \
./src/system_stm32f4xx.o 

C_DEPS += \
./src/main.d \
./src/pwr_modes.d \
./src/stm32f4xx_it.d \
./src/syscalls.d \
./src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o src/%.su src/%.cyclo: ../src/%.c src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DDEBUG -DSTM32F446xx -DUSE_STDPERIPH_DRIVER -c -I"E:/Microcontroller/Stm32/stm32f40x/MCU2_HALlib/STM32CubeIDE/Current_Measurement_Stop_Mode/StdPeriph_Driver/inc" -I"E:/Microcontroller/Stm32/stm32f40x/MCU2_HALlib/STM32CubeIDE/Current_Measurement_Stop_Mode/inc" -I"E:/Microcontroller/Stm32/stm32f40x/MCU2_HALlib/STM32CubeIDE/Current_Measurement_Stop_Mode/CMSIS/device" -I"E:/Microcontroller/Stm32/stm32f40x/MCU2_HALlib/STM32CubeIDE/Current_Measurement_Stop_Mode/CMSIS/core" -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-src

clean-src:
	-$(RM) ./src/main.cyclo ./src/main.d ./src/main.o ./src/main.su ./src/pwr_modes.cyclo ./src/pwr_modes.d ./src/pwr_modes.o ./src/pwr_modes.su ./src/stm32f4xx_it.cyclo ./src/stm32f4xx_it.d ./src/stm32f4xx_it.o ./src/stm32f4xx_it.su ./src/syscalls.cyclo ./src/syscalls.d ./src/syscalls.o ./src/syscalls.su ./src/system_stm32f4xx.cyclo ./src/system_stm32f4xx.d ./src/system_stm32f4xx.o ./src/system_stm32f4xx.su

.PHONY: clean-src

