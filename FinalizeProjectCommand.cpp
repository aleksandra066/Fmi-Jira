#include "FinalizeProjectCommand.h"
#include <iostream>

FinalizeProjectCommand::FinalizeProjectCommand(std::shared_ptr<Project> project): project(project){}

void FinalizeProjectCommand::execute()
{
	if (project) {
		project->finaliseProject();
		std::cout << "Project marked as Finished. \n";
	}
}
