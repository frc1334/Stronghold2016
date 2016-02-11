#include "PickupSubsystem.h"
#include "../RobotMap.h"

PickupSubsystem::PickupSubsystem() :
		Subsystem("ExampleSubsystem")
{

}

void PickupSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}


void PickupSubsystem::Roll(float speed)
{
	Rollers.SetSafetyEnabled(true);
	Rollers.SetExpiration(1.0f);
	Rollers.Set(speed);
}

void PickupSubsystem::MoveAngleManual(float speed)
{
	Angle.SetSafetyEnabled(true);
	Angle.SetExpiration(1.0f);
	Angle.Set(speed);
}

void PickupSubsystem::SetAngle(float angle,float currentAngle)
{
	Angle.SetSafetyEnabled(true);
	Angle.SetExpiration(1.0f);
	Angle.Set(1.0f);
}

void PickupSubsystem::ZeroAngle()
{
	//TODO FOR AUTOMATIC PICKUP PROCEDURE ZERO POINT
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
