#include "ApproveTaskCommand.h"
#include <iostream>

ApproveTaskCommand::ApproveTaskCommand(std::shared_ptr<Task> task):task(task){}

void ApproveTaskCommand::execute()
{
	if (task) {
		if (task->getStatus() == TaskStatus::InReview) {
			task->setStatus(TaskStatus::Done);
			std::cout << "The task " << task->getTitle() << " has been approved and marked as DONE\n";
		}
		else {
			std::cout << "The task's state is not 'In Review' and it cannot be approved\n";
		}
	}
}
