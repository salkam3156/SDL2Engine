################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Instance.cpp \
../src/SDLSetup.cpp \
../src/Window.cpp \
../src/main.cpp 

OBJS += \
./src/Instance.o \
./src/SDLSetup.o \
./src/Window.o \
./src/main.o 

CPP_DEPS += \
./src/Instance.d \
./src/SDLSetup.d \
./src/Window.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


