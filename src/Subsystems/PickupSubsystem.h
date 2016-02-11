#ifndef PickupSubsystem_H
#define PickupSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class PickupSubsystem: public Subsystem
{
private:
	CANTalon Angle,Rollers;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	PickupSubsystem();
	void InitDefaultCommand();
	void Roll(float speed);
	void MoveAngleManual(float speed);
	void SetAngle(float angle, float currentangle);
	void ZeroAngle();
};

#endif
