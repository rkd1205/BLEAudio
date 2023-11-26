################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/dell/Assignment/assignment/Assignment/demo_1/Middlewares/Third_Party/uzlib/src/adler32.c \
/home/dell/Assignment/assignment/Assignment/demo_1/Middlewares/Third_Party/uzlib/src/crc32.c \
/home/dell/Assignment/assignment/Assignment/demo_1/Middlewares/Third_Party/uzlib/src/tinfgzip.c \
/home/dell/Assignment/assignment/Assignment/demo_1/Middlewares/Third_Party/uzlib/src/tinflate.c 

OBJS += \
./Middlewares/uzlib/adler32.o \
./Middlewares/uzlib/crc32.o \
./Middlewares/uzlib/tinfgzip.o \
./Middlewares/uzlib/tinflate.o 

C_DEPS += \
./Middlewares/uzlib/adler32.d \
./Middlewares/uzlib/crc32.d \
./Middlewares/uzlib/tinfgzip.d \
./Middlewares/uzlib/tinflate.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/uzlib/adler32.o: /home/dell/Assignment/assignment/Assignment/demo_1/Middlewares/Third_Party/uzlib/src/adler32.c Middlewares/uzlib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4R9xx -DUSE_HAL_DRIVER -DSTM32_SENSORTILEBOX -c -I../../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/SensorTile.box -I../../../../../../../Drivers/BSP/Components/lsm6dsox -I../../../../../../../Middlewares/ST/BlueNRG-2/includes -I../../../../../../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../../../../../../Middlewares/ST/BlueNRG-2/utils -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/STM32_BLE_Manager/Inc -I../../../../../../../Middlewares/Third_Party/parson -I../../../../../../../Middlewares/Third_Party/uzlib/src -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Misc/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Reloc/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/SystemPerformance/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/TFliteMicro/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/c" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/core/api" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/core/c" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/reference/integer_ops" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/reference" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/optimized" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/tflite_bridge" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/memory_planner" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal/reference/integer_ops" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal/reference" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/arena_allocator" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/schema" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/cmsis_nn/Include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/flatbuffers/include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/gemmlowp" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/ruy" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI/Target" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI/App" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI" -O2 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/uzlib/crc32.o: /home/dell/Assignment/assignment/Assignment/demo_1/Middlewares/Third_Party/uzlib/src/crc32.c Middlewares/uzlib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4R9xx -DUSE_HAL_DRIVER -DSTM32_SENSORTILEBOX -c -I../../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/SensorTile.box -I../../../../../../../Drivers/BSP/Components/lsm6dsox -I../../../../../../../Middlewares/ST/BlueNRG-2/includes -I../../../../../../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../../../../../../Middlewares/ST/BlueNRG-2/utils -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/STM32_BLE_Manager/Inc -I../../../../../../../Middlewares/Third_Party/parson -I../../../../../../../Middlewares/Third_Party/uzlib/src -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Misc/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Reloc/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/SystemPerformance/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/TFliteMicro/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/c" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/core/api" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/core/c" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/reference/integer_ops" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/reference" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/optimized" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/tflite_bridge" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/memory_planner" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal/reference/integer_ops" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal/reference" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/arena_allocator" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/schema" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/cmsis_nn/Include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/flatbuffers/include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/gemmlowp" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/ruy" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI/Target" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI/App" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI" -O2 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/uzlib/tinfgzip.o: /home/dell/Assignment/assignment/Assignment/demo_1/Middlewares/Third_Party/uzlib/src/tinfgzip.c Middlewares/uzlib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4R9xx -DUSE_HAL_DRIVER -DSTM32_SENSORTILEBOX -c -I../../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/SensorTile.box -I../../../../../../../Drivers/BSP/Components/lsm6dsox -I../../../../../../../Middlewares/ST/BlueNRG-2/includes -I../../../../../../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../../../../../../Middlewares/ST/BlueNRG-2/utils -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/STM32_BLE_Manager/Inc -I../../../../../../../Middlewares/Third_Party/parson -I../../../../../../../Middlewares/Third_Party/uzlib/src -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Misc/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Reloc/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/SystemPerformance/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/TFliteMicro/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/c" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/core/api" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/core/c" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/reference/integer_ops" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/reference" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/optimized" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/tflite_bridge" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/memory_planner" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal/reference/integer_ops" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal/reference" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/arena_allocator" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/schema" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/cmsis_nn/Include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/flatbuffers/include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/gemmlowp" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/ruy" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI/Target" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI/App" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI" -O2 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/uzlib/tinflate.o: /home/dell/Assignment/assignment/Assignment/demo_1/Middlewares/Third_Party/uzlib/src/tinflate.c Middlewares/uzlib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g -DSTM32L4R9xx -DUSE_HAL_DRIVER -DSTM32_SENSORTILEBOX -c -I../../../Inc -I../../../../../../../Drivers/CMSIS/Include -I../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../Drivers/BSP/SensorTile.box -I../../../../../../../Drivers/BSP/Components/lsm6dsox -I../../../../../../../Middlewares/ST/BlueNRG-2/includes -I../../../../../../../Middlewares/ST/BlueNRG-2/hci/hci_tl_patterns/Basic -I../../../../../../../Middlewares/ST/BlueNRG-2/utils -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../../../../../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../../../../../../Middlewares/ST/STM32_BLE_Manager/Inc -I../../../../../../../Middlewares/Third_Party/parson -I../../../../../../../Middlewares/Third_Party/uzlib/src -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Misc/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Reloc/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/SystemPerformance/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/TFliteMicro/Inc" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/c" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/core/api" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/core/c" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/reference/integer_ops" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/reference" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal/optimized" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels/internal" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/kernels" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/tflite_bridge" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/memory_planner" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal/reference/integer_ops" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal/reference" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels/cmsis_nn/internal" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/kernels" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro/arena_allocator" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/micro" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite/schema" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/tensorflow/lite" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/cmsis/CMSIS/Core/Include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/cmsis_nn/Include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/flatbuffers/include" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/gemmlowp" -I"/home/dell/Assignment/assignment/demo/Middlewares/tensorflow/third_party/ruy" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI/Target" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI/App" -I"/home/dell/Assignment/assignment/demo/X-CUBE-AI" -O2 -ffunction-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-uzlib

clean-Middlewares-2f-uzlib:
	-$(RM) ./Middlewares/uzlib/adler32.cyclo ./Middlewares/uzlib/adler32.d ./Middlewares/uzlib/adler32.o ./Middlewares/uzlib/adler32.su ./Middlewares/uzlib/crc32.cyclo ./Middlewares/uzlib/crc32.d ./Middlewares/uzlib/crc32.o ./Middlewares/uzlib/crc32.su ./Middlewares/uzlib/tinfgzip.cyclo ./Middlewares/uzlib/tinfgzip.d ./Middlewares/uzlib/tinfgzip.o ./Middlewares/uzlib/tinfgzip.su ./Middlewares/uzlib/tinflate.cyclo ./Middlewares/uzlib/tinflate.d ./Middlewares/uzlib/tinflate.o ./Middlewares/uzlib/tinflate.su

.PHONY: clean-Middlewares-2f-uzlib
