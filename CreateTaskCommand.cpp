#include "CreateTaskCommand.h"
#include <iostream>


CreateTaskCommand::CreateTaskCommand(std::shared_ptr<Project> project, std::shared_ptr<Task> newTask)
	:project(project), newTask(newTask){}

void CreateTaskCommand::execute(){
	if (project && newTask) {
		project->addTask(newTask);
		std::cout << "A new task has been created " << newTask->getTitle() << " in project " << project->getName() << "\n";
	}
}
