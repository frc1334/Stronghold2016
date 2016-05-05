#ifndef PickupSubsystem_H
#define PickupSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PickupSubsystem: public Subsystem
{
private:

	Timer time;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	CANTalon Angle,Rollers;
	bool Zeroed;
	PickupSubsystem();
	void InitDefaultCommand();
	void Roll(float speed);
	void MoveAngleManual(float speed);
	void SetAngle(bool angle, bool currentangle);
	void ZeroAngle();
};

#endif
