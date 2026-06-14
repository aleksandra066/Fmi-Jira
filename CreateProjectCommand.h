#pragma once
#include "Command.h"
#include "Project.h"
#include <vector>
#include <string>

class CreateProjectCommand : public Command
{
private:
	std::vector<std::shared_ptr<Project>>& allProjects; 
	std::string name;
	std::string description;
public:
	CreateProjectCommand(std::vector<std::shared_ptr<Project>>& allProjects, std::string name, std::string description);
	void execute() override;
};

