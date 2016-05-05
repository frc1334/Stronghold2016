#include "DriveCommand.h"
double p = 0;
double i = 0;
double d = 0;
double f = 0;
int Izone = 100;
int RampRate = 25;


DriveCommand::DriveCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivesubsystem);
	Requires(shootersubsystem);
	Requires(elevatorsubsystem);
	Requires(pickupsubsystem);
}

// Called just before this Command runs the first time
void DriveCommand::Initialize()
{
	drivesubsystem->DriveLeft1.SetControlMode(CANSpeedController::kPercentVbus);
	drivesubsystem->DriveLeft2.SetControlMode(CANSpeedController::kPercentVbus);
	drivesubsystem->DriveRight1.SetControlMode(CANSpeedController::kPercentVbus);
	drivesubsystem->DriveRight2.SetControlMode(CANSpeedController::kPercentVbus);
	elevatorsubsystem->Winch1.SetControlMode(CANSpeedController::kPercentVbus);
	elevatorsubsystem->Winch2.SetControlMode(CANSpeedController::kPercentVbus);
	elevatorsubsystem->Trolley.SetControlMode(CANSpeedController::kPercentVbus);
	pickupsubsystem->Angle.SetControlMode(CANSpeedController::kPercentVbus);
	pickupsubsystem->Rollers.SetControlMode(CANSpeedController::kPercentVbus);
	shootersubsystem->Flywheel.SetControlMode(CANSpeedController::kSpeed);
	shootersubsystem->Flywheel.SetSensorDirection(true);
	shootersubsystem->Speedwheel.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	//shootersubsystem->Flywheel.SetPID(p,i,d,f);
	//shootersubsystem->Flywheel.SetIzone(Izone);
	//shootersubsystem->Flywheel.SetVoltageRampRate(ramprate);
	shootersubsystem->Speedwheel.SetControlMode(CANSpeedController::kSpeed);
	shootersubsystem->Speedwheel.SetSensorDirection(true);
	shootersubsystem->Speedwheel.SetFeedbackDevice(CANTalon::CtreMagEncoder_Relative);
	//shootersubsystem->Speedwheel.SetPID(p,i,d,f);
	//shootersubsystem->Speedwheel.SetIzone(Izone);
	//shootersubsystem->Speedwheel.SetVoltageRampRate(ramprate);
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
	if (oi->GetOPA()){
		elevatorsubsystem->WinchDrive(true,false);
	}else if (oi->GetOPB()){
		elevatorsubsystem->WinchDrive(false,true);
	}
	if (oi->GetOPX()){
		elevatorsubsystem->TrolleyDrive(1.0f);
	}else{
		elevatorsubsystem->TrolleyDrive(0.0f);
	}
	pickupsubsystem->Roll(oi->GetRoller());
	pickupsubsystem->MoveAngleManual(oi->GetPickupManual());
	//elevatorsubsystem->WinchSlack(oi->GetOPLeftTrigger());
	if(oi->GetOPY()){
		shootersubsystem->Speedwheel.SetExpiration(1.0f);
		shootersubsystem->Flywheel.SetExpiration(1.0f);
		shootersubsystem->Flywheel.Set(3000);
		shootersubsystem->Speedwheel.Set(0);
	}else{
		shootersubsystem->Speedwheel.SetExpiration(1.0f);
		shootersubsystem->Flywheel.SetExpiration(1.0f);
		shootersubsystem->Flywheel.Set(0);
		shootersubsystem->Speedwheel.Set(0);
	}
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
