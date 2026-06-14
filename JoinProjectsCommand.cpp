#include "JoinProjectsCommand.h"
#include <iostream>
#include "User.h"


JoinProjectsCommand::JoinProjectsCommand(std::shared_ptr<User> student, std::shared_ptr<Project> project)
	:student(student), project(project){}

void JoinProjectsCommand::execute(){
	if (project && student) {
		project->addMember(student);
		std::cout << "The student " << student->getUsername() << " has joined the project " << project->getName() << "\n";
	}
}
