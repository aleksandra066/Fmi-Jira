#pragma once
#include "Command.h"
#include "Project.h"

class FinalizeProjectCommand : public Command
{
private:
	std::shared_ptr<Project> project;
public:
	explicit FinalizeProjectCommand(std::shared_ptr<Project> project);
	void execute() override;
};

