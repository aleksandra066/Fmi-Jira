#include "GradeTaskCommand.h"
#include <iostream>

GradeTaskCommand::GradeTaskCommand(std::shared_ptr<Task> task, double grade):task(task), grade(grade){}

void GradeTaskCommand::execute()
{
	if (task && task->getStatus() == TaskStatus::Done) {
		task->setGrade(grade);
		std::cout << "Task graded successfuly. \n";
	}
	else {
		std::cout << "Only fully done tasks can be graded!\n";
	}
}
