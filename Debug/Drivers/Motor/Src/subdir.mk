################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Drivers/Motor/Src/Motor.cpp 

OBJS += \
./Drivers/Motor/Src/Motor.o 

CPP_DEPS += \
./Drivers/Motor/Src/Motor.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Motor/Src/%.o Drivers/Motor/Src/%.su Drivers/Motor/Src/%.cyclo: ../Drivers/Motor/Src/%.cpp Drivers/Motor/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I/home/sergey/project/STM32/robot/robot/Drivers/Parser/Inc -I../Drivers/Motor/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Motor-2f-Src

clean-Drivers-2f-Motor-2f-Src:
	-$(RM) ./Drivers/Motor/Src/Motor.cyclo ./Drivers/Motor/Src/Motor.d ./Drivers/Motor/Src/Motor.o ./Drivers/Motor/Src/Motor.su

.PHONY: clean-Drivers-2f-Motor-2f-Src

