################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32f446xx.s 

OBJS += \
./startup/startup_stm32f446xx.o 

S_DEPS += \
./startup/startup_stm32f446xx.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -I"E:/Microcontroller/Stm32/stm32f40x/MCU2_HALlib/STM32CubeIDE/Current_Measurement_Run_Mode/StdPeriph_Driver/inc" -I"E:/Microcontroller/Stm32/stm32f40x/MCU2_HALlib/STM32CubeIDE/Current_Measurement_Run_Mode/inc" -I"E:/Microcontroller/Stm32/stm32f40x/MCU2_HALlib/STM32CubeIDE/Current_Measurement_Run_Mode/CMSIS/device" -I"E:/Microcontroller/Stm32/stm32f40x/MCU2_HALlib/STM32CubeIDE/Current_Measurement_Run_Mode/CMSIS/core" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-startup

clean-startup:
	-$(RM) ./startup/startup_stm32f446xx.d ./startup/startup_stm32f446xx.o

.PHONY: clean-startup

