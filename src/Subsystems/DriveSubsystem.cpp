#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "Commands/Subsystem.h"
DriveSubsystem::DriveSubsystem() :
		Subsystem("DriveSubsystem"),DriveRight1(0),DriveRight2(1),DriveLeft1(2),DriveLeft2(3),Shift1(2),Shift2(3)
{

}

void DriveSubsystem::InitDefaultCommand()
{

}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveSubsystem :: Drive(float backwards, float forwards, float turn)
{
	DriveRight1.SetSafetyEnabled(true);
	DriveRight1.SetExpiration(1.0f);
	DriveRight2.SetSafetyEnabled(true);
	DriveRight2.SetExpiration(1.0f);
	DriveLeft1.SetSafetyEnabled(true);
	DriveLeft1.SetExpiration(1.0f);
	DriveLeft2.SetSafetyEnabled(true);
	DriveLeft2.SetExpiration(1.0f);
	float speed = (backwards*-1) + forwards ;
	DriveRight1.Set(turn - speed);
	DriveRight2.Set(turn - speed);
	DriveLeft1.Set(turn + speed);
	DriveLeft2.Set(turn + speed);


}

void DriveSubsystem::SetShiftState(bool IsShiftedUp)
{
	if (IsShiftedUp == true){
		Shift1.Set(true);
		Shift2.Set(true);
	}else if(IsShiftedUp == false){
		Shift1.Set(false);
		Shift2.Set(false);
	}
}
