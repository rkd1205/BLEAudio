################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include tensorflow/third_party/cmsis_nn/Source/SoftmaxFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/SVDFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/ReshapeFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/PoolingFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/NNSupportFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/FullyConnectedFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/ConvolutionFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/ConcatenationFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/BasicMathFunctions/subdir.mk
-include tensorflow/third_party/cmsis_nn/Source/ActivationFunctions/subdir.mk
-include X-CUBE-AI/App/subdir.mk
-include Middlewares/uzlib/subdir.mk
-include Middlewares/STM32_USBD_Library/Core/subdir.mk
-include Middlewares/STM32_USBD_Library/Class/CDC/subdir.mk
-include Middlewares/Parson/subdir.mk
-include Middlewares/BlueNRG-2/Utils/subdir.mk
-include Middlewares/BlueNRG-2/HCI_TL/Basic/subdir.mk
-include Middlewares/BlueNRG-2/Controller/subdir.mk
-include Middlewares/BLE_Manager/subdir.mk
-include Middlewares/AI/SystemPerformance/Src/subdir.mk
-include Middlewares/AI/Reloc/Src/subdir.mk
-include Middlewares/AI/Misc/Src/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/SensorTile.box/subdir.mk
-include Drivers/BSP/STM32L4xx_HAL_Driver/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include BLEMLC/User/subdir.mk
-include BLEMLC/STM32CubeIDE/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SensorTileBox-BLEMLC
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SensorTileBox-BLEMLC.elf \

MAP_FILES += \
SensorTileBox-BLEMLC.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SensorTileBox-BLEMLC.list \

OBJCOPY_BIN += \
SensorTileBox-BLEMLC.bin \


# All Target
all: main-build

# Main-build Target
main-build: SensorTileBox-BLEMLC.elf secondary-outputs

# Tool invocations
SensorTileBox-BLEMLC.elf SensorTileBox-BLEMLC.map: $(OBJS) $(USER_OBJS) ../STM32L4R9AIIx_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "SensorTileBox-BLEMLC.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"../STM32L4R9AIIx_FLASH.ld" --specs=nosys.specs -Wl,-Map="SensorTileBox-BLEMLC.map" -Wl,--gc-sections -static -L"/home/dell/Assignment/assignment/demo/Middlewares/ST/AI/Lib" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -u _printf_float -u _scanf_float -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SensorTileBox-BLEMLC.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SensorTileBox-BLEMLC.list"
	@echo 'Finished building: $@'
	@echo ' '

SensorTileBox-BLEMLC.bin: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "SensorTileBox-BLEMLC.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SensorTileBox-BLEMLC.bin SensorTileBox-BLEMLC.elf SensorTileBox-BLEMLC.list SensorTileBox-BLEMLC.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
