#pragma once
#include "Command.h"
#include "Project.h"
#include "Task.h"

class User; 

class JoinProjectsCommand :public Command
{
private:
	std::shared_ptr<User> student;
	std::shared_ptr<Project> project;
public:
	JoinProjectsCommand(std::shared_ptr<User> student, std::shared_ptr<Project> project);
	void execute() override;
};

