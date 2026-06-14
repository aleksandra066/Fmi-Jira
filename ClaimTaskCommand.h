#pragma once
#include "Command.h"
#include "Task.h"
#include "User.h"

class ClaimTaskCommand : public Command
{
private:
	std::shared_ptr<User> student;
	std::shared_ptr<Task> task;
public:
	ClaimTaskCommand(std::shared_ptr<User> student, std::shared_ptr<Task> task);
	void execute() override;
};

