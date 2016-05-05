################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/DriveSubsystem.cpp \
../src/Subsystems/ElevatorSubsystem.cpp \
../src/Subsystems/PickupSubsystem.cpp \
../src/Subsystems/ShooterSubsystem.cpp 

OBJS += \
./src/Subsystems/DriveSubsystem.o \
./src/Subsystems/ElevatorSubsystem.o \
./src/Subsystems/PickupSubsystem.o \
./src/Subsystems/ShooterSubsystem.o 

CPP_DEPS += \
./src/Subsystems/DriveSubsystem.d \
./src/Subsystems/ElevatorSubsystem.d \
./src/Subsystems/PickupSubsystem.d \
./src/Subsystems/ShooterSubsystem.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\Robotics/wpilib/cpp/current/include" -I"C:\Users\Robotics\workspace\Stronghold2016\src" -I"C:\Users\Robotics\workspace\Stronghold2016\_Includes\OpenCV\2.4.10" -I"C:\Users\Robotics\workspace\Stronghold2016\_Libraries\softFP\lib_OpenCV" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


