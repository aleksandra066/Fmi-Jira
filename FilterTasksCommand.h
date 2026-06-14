#pragma once
#include "Command.h"
#include "Project.h"

class FilterTasksCommand : public Command
{
private:
	const Project& project;
	std::string tagFilter;
	bool upcomingDeadLine;
public:
	FilterTasksCommand(const Project& project, std::string tagFilter, bool upcomingDeadLine);
	void execute() override;
};

