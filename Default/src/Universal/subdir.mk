################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Universal/CommonFun.cpp 

OBJS += \
./src/Universal/CommonFun.o 

CPP_DEPS += \
./src/Universal/CommonFun.d 


# Each subdirectory must supply rules for building sources it contributes
src/Universal/%.o: ../src/Universal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I/usr/include/gdal/ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


