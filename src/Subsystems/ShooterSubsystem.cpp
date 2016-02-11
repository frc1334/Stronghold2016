#include "ShooterSubsystem.h"
#include "../RobotMap.h"

ShooterSubsystem::ShooterSubsystem() :
		Subsystem("ExampleSubsystem"),Speedwheel(7),Flywheel(8)
{

}

void ShooterSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());

}
void ShooterSubsystem::Shoot(float speed)
{
	Speedwheel.SetSafetyEnabled(true);
	Speedwheel.SetExpiration(1.0f);
	Flywheel.SetSafetyEnabled(true);
	Flywheel.SetExpiration(1.0f);
	Speedwheel.Set(-speed);
	Flywheel.Set(speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
