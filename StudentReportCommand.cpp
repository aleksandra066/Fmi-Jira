#include "StudentReportCommand.h"
#include <iostream>

StudentReportCommand::StudentReportCommand(const std::vector<std::shared_ptr<Task>>& allTasks, std::string targetUsername)
	:allTasks(allTasks), targetUsername(targetUsername){}

void StudentReportCommand::execute()
{
    int completed = 0;
    double totalGrade = 0.0;
    int gradedTasksCount = 0;
    int performanceScore = 0;

    for (const auto& task : allTasks) {
        if (auto assignee = task->getAssignee().lock()) {
            if (assignee->getUsername() == targetUsername) {
                if (task->getStatus() == TaskStatus::Done) {
                    completed++;
                    performanceScore += 10;
                    if (task->getGrade() > 0) {
                        totalGrade += task->getGrade();
                        gradedTasksCount++;
                    }
                }
            }
        }
    }
    double averageGrade = (gradedTasksCount > 0) ? (totalGrade / gradedTasksCount) : 0.0;

    std::cout << "Completed tasks: " << completed << "\n";
    std::cout << "Average grade: " << averageGrade << "\n";
    std::cout << "Performance score: " << performanceScore << "\n";
}
