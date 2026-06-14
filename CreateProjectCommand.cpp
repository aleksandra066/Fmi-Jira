#include "CreateProjectCommand.h"
#include <iostream> 

CreateProjectCommand::CreateProjectCommand(std::vector<std::shared_ptr<Project>>& allProjects, std::string name, std::string description)
	: allProjects(allProjects), name(name), description(description) {}

void CreateProjectCommand::execute()
{
	auto newProject = std::make_shared<Project>(name, description);
	allProjects.push_back(newProject);
	std::cout << "Successfully created project: " << name << "\n";
}
