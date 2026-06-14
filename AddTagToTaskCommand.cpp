#include "AddTagToTaskCommand.h"
#include "Task.h"
#include <iostream> 

AddTagToTaskCommand::AddTagToTaskCommand(std::shared_ptr<Task> task, std::string tag)
	: task(task), tag(tag) {}

void AddTagToTaskCommand::execute() {
	if (task) {
		task->getHistory().emplace_back("This tag has been added: " + tag);
		std::cout << "Added tag '" << tag << "' for task " << task->getTitle() << "\n";
	}
}
