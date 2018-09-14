################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Types/TestState.cpp \
../src/Types/TestState2.cpp 

OBJS += \
./src/Types/TestState.o \
./src/Types/TestState2.o 

CPP_DEPS += \
./src/Types/TestState.d \
./src/Types/TestState2.d 


# Each subdirectory must supply rules for building sources it contributes
src/Types/%.o: ../src/Types/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


