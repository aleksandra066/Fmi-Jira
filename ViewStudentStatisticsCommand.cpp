#include "ViewStudentStatisticsCommand.h"
#include "map"
#include "Task.h"

ViewStudentStatisticsCommand::ViewStudentStatisticsCommand(const Project& project):project(project){}

void ViewStudentStatisticsCommand::execute(){
    std::cout << "\n=============================================\n";
    std::cout << "STATISTICS FOR THE STUDENTS IN THE PROJECT: " << project.getName() << "\n";
    std::cout << "=============================================\n";

    std::map<std::string, int> completedTasksCount;
    std::map<std::string, double> totalHoursSpent;

    for (const auto& task : project.getTasks()) {
        if (auto userPtr = task->getAssignee().lock()) {
            std::string username = std::string(userPtr->getUsername());

            if (task->getStatus() == TaskStatus::Done) {
                completedTasksCount[username]++;
            }
            totalHoursSpent[username] += task->getEstimationHours();
        }
    }

    if (completedTasksCount.empty()) {
        std::cout << "No activity found from students\n";
    }
    else {
        for (const auto& pair : completedTasksCount) {
            std::cout << "Student: " << pair.first << "\n";
            std::cout << " - Done tasks: " << pair.second << "\n";
            std::cout << " - Estimated hours: " << totalHoursSpent[pair.first] << " ÷.\n";
            std::cout << "---------------------------------------------\n";
        }
    }
}
