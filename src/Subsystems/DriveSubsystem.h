#ifndef DRIVE_SUBSYSTEM_H
#define DRIVE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem
{
private:

	CANTalon DriveRight1;
	CANTalon DriveRight2;
	CANTalon DriveLeft1;
	CANTalon DriveLeft2;
	Solenoid Shift1,Shift2;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveSubsystem();
	void InitDefaultCommand();
	void Drive(float backward,float forward, float turn);
	void SetShiftState(bool isShiftedUp);
};

#endif
