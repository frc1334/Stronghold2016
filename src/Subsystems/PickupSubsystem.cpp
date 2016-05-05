#include "PickupSubsystem.h"
#include "../RobotMap.h"

PickupSubsystem::PickupSubsystem() :
		Subsystem("ExampleSubsystem"),Angle(9),Rollers(10)
{

}

void PickupSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	time.Stop();
	time.Reset();
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
	Zeroed = false;
}

void PickupSubsystem::SetAngle(bool angle,bool currentAngle)
{
	Angle.SetSafetyEnabled(true);
	Angle.SetExpiration(1.0f);
	if (Zeroed == true){
		if (currentAngle and angle == false){
			time.Stop();
			time.Reset();
			time.Start();
			Angle.Set(1.0f);
			angle=true;
		} else if(currentAngle and angle and time.Get()<1){
			Angle.Set(1.0f);
		} else if(currentAngle == false and angle){
			time.Stop();
			time.Reset();
			time.Start();
			Angle.Set(-1.0f);
			angle = false;
		} else if(currentAngle == false and angle == false and time.Get()<1){
			Angle.Set(-1.0f);
		} else{
			Angle.Set(0.0f);
		}
	}
}

void PickupSubsystem::ZeroAngle()
{
	if(Zeroed == false){
		Angle.Set(1.0f);
		if (Angle.IsFwdLimitSwitchClosed()){
			Zeroed = true;
		}else{
			Angle.Set(0.0f);
		}
	}
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
