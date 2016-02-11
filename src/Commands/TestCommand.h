#ifndef TestCommand_H
#define TestCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class TestCommand: public CommandBase
{
public:
	TestCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
