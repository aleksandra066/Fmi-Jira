#include "MyTasksCommand.h"
#include <iostream>

MyTasksCommand::MyTasksCommand(const std::vector<std::shared_ptr<Task>>& allTasks, std::shared_ptr<User> currentUser)
	:allTasks(allTasks), currentUser(currentUser){}

void MyTasksCommand::execute()
{
    if (!currentUser) return;

    int completed = 0;
    int inProgress = 0;
    int performanceScore = 0;

    for (const auto& task : allTasks) {
        if (auto assignee = task->getAssignee().lock()) {
            if (assignee->getId() == currentUser->getId()) {
                if (task->getStatus() == TaskStatus::Done) {
                    completed++;
                    performanceScore += 10;
                }
                else if (task->getStatus() == TaskStatus::InProgress) {
                    inProgress++;
                }
            }
        }
    }
    std::cout << "Completed tasks: " << completed << "\n";
    std::cout << "In progress: " << inProgress << "\n";
    std::cout << "Performance score: " << performanceScore << "\n";
}
