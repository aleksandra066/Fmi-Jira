#pragma once
#include "Command.h"
#include "Task.h"

class ChangePriorityCommand:public Command
{
private:
	std::shared_ptr<Task> task;
	Priority newPriority;
public:
	ChangePriorityCommand(std::shared_ptr<Task> task, Priority priority);
	void execute() override;
};

