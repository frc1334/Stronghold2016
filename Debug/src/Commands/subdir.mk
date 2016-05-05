################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/DriveCommand.cpp \
../src/Commands/TestCommand.cpp 

OBJS += \
./src/Commands/DriveCommand.o \
./src/Commands/TestCommand.o 

CPP_DEPS += \
./src/Commands/DriveCommand.d \
./src/Commands/TestCommand.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/%.o: ../src/Commands/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\Robotics/wpilib/cpp/current/include" -I"C:\Users\Robotics\workspace\Stronghold2016\src" -I"C:\Users\Robotics\workspace\Stronghold2016\_Includes\OpenCV\2.4.10" -I"C:\Users\Robotics\workspace\Stronghold2016\_Libraries\softFP\lib_OpenCV" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


