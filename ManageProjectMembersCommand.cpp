#include "ManageProjectMembersCommand.h"
#include <iostream>

ManageProjectMembersCommand::ManageProjectMembersCommand(std::shared_ptr<Project> project, std::shared_ptr<User> user, bool isAdding)
	:project(project), user(user), isAdding(isAdding){}

void ManageProjectMembersCommand::execute()
{
	if (!project || !user) { return; }

	if (isAdding) {
		project->addMember(user);
		std::cout << "User " << user->getUsername() << " has been added to project " << project->getName() << "\n";
	}
	else {
		std::cout<< "User " << user->getUsername() << " has been removed from " << project->getName() << "\n";
	}
}
