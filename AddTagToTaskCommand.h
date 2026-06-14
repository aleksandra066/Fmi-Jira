#pragma once
#include "Command.h"
#include <memory>
#include <string>

class Task;

class AddTagToTaskCommand : public Command
{
private:
	std::shared_ptr<Task> task;
	std::string tag;
public:
	AddTagToTaskCommand(std::shared_ptr<Task> task, std::string tag);
	void execute() override;
};

