################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
/home/dell/Assignment/assignment/demo/Projects/STM32L4R9ZI-SensorTile.box/Applications/DataLogExtended/STM32CubeIDE/startup_stm32l4r9xx.s 

C_SRCS += \
/home/dell/Assignment/assignment/demo/Projects/STM32L4R9ZI-SensorTile.box/Applications/DataLogExtended/STM32CubeIDE/syscalls.c 

OBJS += \
./Example/STM32CubeIDE/startup_stm32l4r9xx.o \
./Example/STM32CubeIDE/syscalls.o 

S_DEPS += \
./Example/STM32CubeIDE/startup_stm32l4r9xx.d 

C_DEPS += \
./Example/STM32CubeIDE/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Example/STM32CubeIDE/startup_stm32l4r9xx.o: /home/dell/Assignment/assignment/demo/Projects/STM32L4R9ZI-SensorTile.box/Applications/DataLogExtended/STM32CubeIDE/startup_stm32l4r9xx.s Example/STM32CubeIDE/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g -c -I../../../Inc -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Example/STM32CubeIDE/syscalls.o: /home/dell/Assignment/assignment/demo/Projects/STM32L4R9ZI-SensorTile.box/Applications/DataLogExtended/STM32CubeIDE/syscalls.c Example/STM32CubeIDE/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4R9xx -DUSE_HAL_DRIVER -DSTM32_SENSORTILEBOX -c -I../../../Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../Drivers/BSP/Components/lps22hh -I../../../../../../../Drivers/BSP/Components/lis2mdl -I../../../../../../../Drivers/BSP/Components/lsm6dsox -I../../../../../../../Drivers/BSP/Components/lis3dhh -I../../../../../../../Drivers/BSP/Components/lis2dw12 -I../../../../../../../Drivers/BSP/Components/stts751 -I../../../../../../../Drivers/BSP/SensorTile.box -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Example-2f-STM32CubeIDE

clean-Example-2f-STM32CubeIDE:
	-$(RM) ./Example/STM32CubeIDE/startup_stm32l4r9xx.d ./Example/STM32CubeIDE/startup_stm32l4r9xx.o ./Example/STM32CubeIDE/syscalls.cyclo ./Example/STM32CubeIDE/syscalls.d ./Example/STM32CubeIDE/syscalls.o ./Example/STM32CubeIDE/syscalls.su

.PHONY: clean-Example-2f-STM32CubeIDE

