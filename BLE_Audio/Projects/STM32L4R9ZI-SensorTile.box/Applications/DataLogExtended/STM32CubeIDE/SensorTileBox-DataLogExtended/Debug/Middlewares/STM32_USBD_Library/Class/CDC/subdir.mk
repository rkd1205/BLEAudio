################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/dell/Assignment/assignment/demo/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c 

OBJS += \
./Middlewares/STM32_USBD_Library/Class/CDC/usbd_cdc.o 

C_DEPS += \
./Middlewares/STM32_USBD_Library/Class/CDC/usbd_cdc.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_USBD_Library/Class/CDC/usbd_cdc.o: /home/dell/Assignment/assignment/demo/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Src/usbd_cdc.c Middlewares/STM32_USBD_Library/Class/CDC/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4R9xx -DUSE_HAL_DRIVER -DSTM32_SENSORTILEBOX -c -I../../../Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../Drivers/BSP/Components/lps22hh -I../../../../../../../Drivers/BSP/Components/lis2mdl -I../../../../../../../Drivers/BSP/Components/lsm6dsox -I../../../../../../../Drivers/BSP/Components/lis3dhh -I../../../../../../../Drivers/BSP/Components/lis2dw12 -I../../../../../../../Drivers/BSP/Components/stts751 -I../../../../../../../Drivers/BSP/SensorTile.box -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-STM32_USBD_Library-2f-Class-2f-CDC

clean-Middlewares-2f-STM32_USBD_Library-2f-Class-2f-CDC:
	-$(RM) ./Middlewares/STM32_USBD_Library/Class/CDC/usbd_cdc.cyclo ./Middlewares/STM32_USBD_Library/Class/CDC/usbd_cdc.d ./Middlewares/STM32_USBD_Library/Class/CDC/usbd_cdc.o ./Middlewares/STM32_USBD_Library/Class/CDC/usbd_cdc.su

.PHONY: clean-Middlewares-2f-STM32_USBD_Library-2f-Class-2f-CDC

