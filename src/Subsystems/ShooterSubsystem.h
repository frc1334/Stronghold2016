#ifndef ShooterSubsystem_H
#define ShooterSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShooterSubsystem: public Subsystem
{
private:

	CANTalon Speedwheel,Flywheel;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	ShooterSubsystem();
	void InitDefaultCommand();
	void Shoot(float speed);
};

#endif
