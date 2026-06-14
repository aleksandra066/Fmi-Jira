#include "ClaimTaskCommand.h"
#include <iostream>

ClaimTaskCommand::ClaimTaskCommand(std::shared_ptr<User> student, std::shared_ptr<Task> task)
	:student(student), task(task){}

void ClaimTaskCommand::execute(){
	if (task && student) {
		task->setAssignee(student);
		task->setStatus(TaskStatus::InProgress);
		std::cout << "Student " << student->getUsername() << " started doing this task: " << task->getTitle() << "\n";
	}
}
