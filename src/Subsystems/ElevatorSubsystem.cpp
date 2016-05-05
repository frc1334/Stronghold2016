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

void ElevatorSubsystem::WinchDrive(bool isUp,bool isDown)
{
	Winch1.SetSafetyEnabled(true);
	Winch1.SetExpiration(1.0f);
	Winch2.SetSafetyEnabled(true);
	Winch2.SetExpiration(1.0f);
	if (isUp){
		Winch1.Set(-0.1f);
		Winch2.Set(1.0f);
	} else if(isDown){
		Winch1.Set(-0.1f);
		Winch2.Set(-1.0f);
	}else{
		Winch1.Set(0.0f);
		Winch2.Set(0.0f);
	}
}

void ElevatorSubsystem::Tilt(bool isTilted)
{
	TiltPiston.Set(isTilted);
}

void ElevatorSubsystem::Climb(bool isClimbing)
{
	ClimbPiston.Set(isClimbing);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
