#pragma once
#include "Command.h"
#include "Task.h"

class ApproveTaskCommand:public Command
{
private:
	std::shared_ptr<Task> task;
public:
	explicit ApproveTaskCommand(std::shared_ptr<Task> task);
	void execute() override;
};

