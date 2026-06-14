#pragma once
#include "Command.h"
#include "Project.h"
#include "Task.h"

class CreateTaskCommand: public Command
{
private:
	std::shared_ptr<Project> project;
	std::shared_ptr<Task> newTask;
public:
	CreateTaskCommand(std::shared_ptr<Project> project, std::shared_ptr<Task> newTask);
	void execute() override;
};

