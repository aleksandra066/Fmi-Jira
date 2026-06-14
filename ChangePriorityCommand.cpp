#include "ChangePriorityCommand.h"
#include <iostream>

ChangePriorityCommand::ChangePriorityCommand(std::shared_ptr<Task> task, Priority priority)
	:task(task), newPriority(priority){}

void ChangePriorityCommand::execute()
{
	if (task) {
		task->setPriority(newPriority);
		task->getHistory().emplace_back("The priority has been changed!");
		std::cout <<"The priority of the task " << task->getTitle() << " has been changed\n";
	}
}
