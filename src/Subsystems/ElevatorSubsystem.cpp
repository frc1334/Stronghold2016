#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() :
		Subsystem("ExampleSubsystem"),Winch1(4),Winch2(5),Trolley(6),TiltPiston(0),ClimbPiston(1)
{

}

void ElevatorSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());


}

void ElevatorSubsystem::TrolleyDrive(float speed)
{
	Trolley.SetSafetyEnabled(true);
	Trolley.SetExpiration(1.0f);
	Trolley.Set(speed);
}

void ElevatorSubsystem::WinchDrive(float speed)
{
	Winch1.SetSafetyEnabled(true);
	Winch1.SetExpiration(1.0f);
	Winch2.SetSafetyEnabled(true);
	Winch2.SetExpiration(1.0f);
	Winch1.Set(speed);
	Winch2.Set(speed);
}

void ElevatorSubsystem::Tilt(bool isTilted)
{
	TiltPiston.Set(isTilted);
}

void ElevatorSubsystem::Climb(bool isClimbing)
{
	ClimbPiston.Set(isClimbing);
}

void ElevatorSubsystem::WinchSlack(float speed)
{
	Winch1.SetSafetyEnabled(true);
	Winch1.SetExpiration(1.0f);
	Winch1.Set(speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
