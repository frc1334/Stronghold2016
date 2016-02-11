#include "DriveCommand.h"

DriveCommand::DriveCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	Requires(shootersubsystem);
	Requires(elevatorsubsystem);
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute()
{
	drivesubsystem->Drive(oi->GetDriveLeftTrigger(),oi->GetDriveRightTrigger(),oi->GetSteering());
	if (oi->GetDriveA())
	{
		drivesubsystem->SetShiftState(true);
	} else {
		drivesubsystem->SetShiftState(false);
	}

	if (oi->GetOPA())
	{
		std::cout << "a";
		shootersubsystem->Shoot(1.0f);
	}else{
		shootersubsystem->Shoot(0.0f);
	}
	if (oi->GetOPB()){
		elevatorsubsystem->WinchDrive(1.0f);
	}else{
		elevatorsubsystem->WinchDrive(0.0f);
	}
	if (oi->GetOPX()){
		elevatorsubsystem->TrolleyDrive(1.0f);
	}else{
		elevatorsubsystem->TrolleyDrive(0.0f);
	}
	pickupsubsystem->Roll(oi->GetRoller());
	pickupsubsystem->MoveAngleManual(oi->GetPickupManual());
	//elevatorsubsystem->WinchSlack(oi->GetOPLeftTrigger());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted()
{

}
