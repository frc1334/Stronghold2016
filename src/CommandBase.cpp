#include "CommandBase.h"
#include "Subsystems/DriveSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
DriveSubsystem* CommandBase::drivesubsystem= NULL;
OI* CommandBase::oi = NULL;
ElevatorSubsystem* CommandBase::elevatorsubsystem = NULL;
ShooterSubsystem* CommandBase::shootersubsystem = NULL;
PickupSubsystem* CommandBase::pickupsubsystem = NULL;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivesubsystem = new DriveSubsystem();
	oi = new OI();
	elevatorsubsystem = new ElevatorSubsystem();
	shootersubsystem = new ShooterSubsystem();
	pickupsubsystem = new PickupSubsystem();
}
