#pragma once
#include "Command.h"
#include "Project.h"
#include "Task.h"

class LoadDataCommand: public Command
{
private: 
	std::vector<std::shared_ptr<User>>& users;
	std::vector<std::shared_ptr<Project>>& projects;
	std::vector<std::shared_ptr<Task>>& tasks;
public:
	LoadDataCommand(std::vector < std::shared_ptr<User>>& users, std::vector<std::shared_ptr<Project>>& projects,
		std::vector<std::shared_ptr<Task>>& tasks);
	void execute() override;
};

