#ifndef ElevatorSubsystem_H
#define ElevatorSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ElevatorSubsystem: public Subsystem
{
private:

	Solenoid TiltPiston,ClimbPiston;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	CANTalon Winch1,Winch2,Trolley;
	ElevatorSubsystem();
	void InitDefaultCommand();
	void TrolleyDrive(float speed);
	void WinchDrive(bool isUp, bool isDown);
	void Tilt(bool isTilted);
	void Climb(bool isClimbing);
};

#endif
