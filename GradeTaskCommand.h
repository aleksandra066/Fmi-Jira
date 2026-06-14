#pragma once
#include "Command.h"
#include "Task.h"

class GradeTaskCommand : public Command
{
private:
	std::shared_ptr<Task> task;
	double grade;
public:
	GradeTaskCommand(std::shared_ptr<Task> task, double grade);
	void execute() override;
};

