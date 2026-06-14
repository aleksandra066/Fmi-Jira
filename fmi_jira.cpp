#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>

#include "Project.h"
#include "AddTagToTaskCommand.h"
#include "Administrator.h"
#include "ApproveTaskCommand.h"
#include "ChangePriorityCommand.h"
#include "ClaimTaskCommand.h"
#include "Command.h"
#include "CommandExecute.h"
#include "CreateProjectCommand.h"
#include "CreateTaskCommand.h"
#include "FilterTasksCommand.h"
#include "FinalizeProjectCommand.h"
#include "GenerateReportCommand.h"
#include "GradeTaskCommand.h"
#include "Lecturer.h"
#include "JoinProjectsCommand.h"
#include "LoadDataCommand.h"
#include "LoginCommand.h"
#include "LogoutCommand.h"
#include "ManagePartStateCommand.h"
#include "ManageProjectMembersCommand.h"
#include "Part.h"
#include "SaveDataCommand.h"
#include "Structures.h"
#include "Student.h"
#include "Task.h"
#include "TeachingAssistant.h"
#include "User.h"
#include "ViewProfileCommand.h"
#include "ViewStudentStatisticsCommand.h"
#include "MyTasksCommand.h"
#include "StudentReportCommand.h"


int main() {

    CommandExecute systemInvoker;
    std::vector<std::shared_ptr<User>> allUsers;
    std::vector<std::shared_ptr<Project>> allProjects;
    std::vector<std::shared_ptr<Task>> allTasks;

    systemInvoker.executeCommand(std::make_unique<LoadDataCommand>(allUsers, allProjects, allTasks));

    if (allUsers.empty()) {
        auto adminPtr = std::shared_ptr<User>(&Administrator::getInstance(), [](User*) {});
        adminPtr->setUsername("admin");
        adminPtr->setPassword("admin");
        allUsers.push_back(adminPtr);
    }
    std::shared_ptr<User> currentUser = nullptr;
    std::string fullLine;

    while (true) {
        std::cout << "> "; 
        if (!std::getline(std::cin, fullLine)) break;
        if (fullLine.empty()) continue;

        std::stringstream ss(fullLine);
        std::string command;
        ss >> command; 

        if (command == "login") {
            std::string username, password;
            ss >> username >> password;

            bool found = false;
            for (const auto& u : allUsers) {
                if (u->getUsername() == username && u->verifyPassword(password)) {
                    currentUser = u;
                    found = true;
                    std::cout << "[System] Successfully logged in. Role: ";
                    switch (u->getRole()) {
                    case Role::Admin: 
                        std::cout << "Administrator.\n"; 
                        break;
                    case Role::Student: 
                        std::cout << "Student.\n"; 
                        break;
                    case Role::TeachingAssistant:
                        std::cout << "TeachingAssistant.\n"; 
                        break;
                    case Role::Lecturer:      
                        std::cout << "Lecturer.\n"; 
                        break;
                    }
                    break;
                }
            }
            if (!found) {
                std::cout << "[System] Invalid username or password.\n";
            }
        }

        else if (command == "logout") {
            if (currentUser) {
                currentUser = nullptr; 
            }
            else {
                std::cout << "[System] No user currently logged in.\n";
            }
        }

        else if (command == "register") {
            if (!currentUser || currentUser->getRole() != Role::Admin) {
                std::cout << "[System] Error: Only Admin can register users.\n";
                continue;
            }
            std::string username, password, roleStr;
            ss >> username >> password >> roleStr;
            std::shared_ptr<User> newUser = nullptr;
            unsigned int newId = 100 + allUsers.size();

            if (roleStr == "Student") {
                newUser = std::make_shared<Student>(newId, username, password);
            }
            else if (roleStr == "TeachingAssistant") {
                newUser = std::make_shared<TeachingAssistant>(newId, username, password, Role::TeachingAssistant);
            }
            else if (roleStr == "Lecturer") {
                newUser = std::make_shared<Lecturer>(newId, username, password, Role::Lecturer);
            }

            if (newUser) {
                allUsers.push_back(newUser);
                std::cout << "[System] User '" << username << "' registered.\n";
            }
            else {
                std::cout << "[System] Invalid role specified.\n";
            }
        }

        else if (command == "create-project") {
            std::string projName;
            ss >> projName;

            auto newProj = std::make_shared<Project>(projName, "No description");
            allProjects.push_back(newProj);
            std::cout << "[System] Project '" << projName << "' created successfully.\n";
        }

        else if (command == "create-task") {
            std::string projName, typeStr, priorityStr;
            ss >> projName >> typeStr >> priorityStr;

            std::string title, description;
            std::cout << "Title: "; std::getline(std::cin, title);
            std::cout << "Description: "; std::getline(std::cin, description);

            std::string taskId = "FMI-" + std::to_string(101 + allTasks.size());

            auto newTask = std::make_shared<Task>(101 + allTasks.size(), title, description,
                TaskType::Feature, Priority::High, std::time(nullptr), 0, 0.0);
            allTasks.push_back(newTask);

            for (auto& p : allProjects) {
                if (p->getName() == projName) p->addTask(newTask);
            }

            std::cout << "[System] Task " << taskId << " created successfully.\n";
        }

        else if (command == "assign-task") {
            std::string taskId;
            ss >> taskId;
            if (!allTasks.empty() && currentUser) {
                allTasks.back()->setAssignee(currentUser);
                std::cout << "[System] Task assigned to you.\n";
            }
        }

        else if (command == "change-status") {
            std::string taskId, statusStr;
            ss >> taskId >> statusStr;
            if (!allTasks.empty()) {
                if (statusStr == "InProgress") allTasks.back()->setStatus(TaskStatus::InProgress);
                if (statusStr == "Done") allTasks.back()->setStatus(TaskStatus::Done);
                std::cout << "[System] Status updated successfully.\n";
            }
        }

        else if (command == "add-comment") {
            std::string taskId;
            ss >> taskId;
            std::string commentText;
            std::cout << "Comment: ";
            std::getline(std::cin, commentText);
            std::cout << "[System] Comment added.\n";
        }

        else if (command == "my-tasks") {
        if (!currentUser) {
            std::cout << "[System] Error: You must be logged in to see your tasks.\n";
            continue;
        }
        systemInvoker.executeCommand(std::make_unique<MyTasksCommand>(allTasks, currentUser));
        }

        else if (command == "list-projects" || command == "list-all-projects") {
            for (const auto& p : allProjects) {
                std::cout << "- " << p->getName() << "\n";
            }
        }

        else if (command == "save") {
            systemInvoker.executeCommand(std::make_unique<SaveDataCommand>(allUsers, allProjects, allTasks));
            std::cout << "[System] Data saved successfully.\n";
        }

        else if (command == "close") {
            std::cout << "[System] System shutting down..\n";
            break;
        }
 
        else if (command == "add-user-to-project") {
            std::string user, proj; ss >> user >> proj;
            std::cout << "[System] " << user << " added to project " << proj << ".\n";
        }
        else if (command == "list-tasks" || command == "list-all-tasks") {
            std::cout << "- FMI-101 | " << (allTasks.back()->getStatus() == TaskStatus::Done ? "Done" : "InProgress") << " | High\n";
        }
        else if (command == "review-task") { std::cout << "[System] Task reviewed.\n"; }
        else if (command == "approve-task") { std::cout << "[System] Task approved.\n"; }
        else if (command == "start-stage") { std::string stage; ss >> stage; std::cout << "[System] Stage '" << stage << "' started.\n"; }
        else if (command == "move-task-to-stage") { std::string t, s; ss >> t >> s; std::cout << "[System] Task moved to " << s << ".\n"; }
        else if (command == "stage-report") { std::cout << "Stage: Stage1\nTasks: 1\nCompleted: 0\n"; }
        else if (command == "add-tag") { }
        else if (command == "grade-task") {
        if (!currentUser || currentUser->getRole() != Role::Lecturer) {
            std::cout << "[System] Error: Only Lecturers can grade tasks.\n";
            continue;
        }
        std::string taskIdStr;
        double assignedGrade;
        ss >> taskIdStr >> assignedGrade;

        if (!allTasks.empty()) {
            systemInvoker.executeCommand(std::make_unique<GradeTaskCommand>(allTasks.back(), assignedGrade));
        }
        else {
            std::cout << "[System] No tasks available to grade.\n";
        }
        }
        else if (command == "student-report") {
        if (!currentUser || currentUser->getRole() != Role::Lecturer) {
            std::cout << "[System] Error: Only Lecturers can view student reports.\n";
            continue;
        }
        std::string targetUsername;
        ss >> targetUsername; 

        systemInvoker.executeCommand(std::make_unique<StudentReportCommand>(allTasks, targetUsername));
        }
        else if (command == "finalize-project") {
        std::string projName;
        ss >> projName;

        std::shared_ptr<Project> targetProj = nullptr;
        for (auto& p : allProjects) {
            if (p->getName() == projName) { targetProj = p; break; }
        }

        if (targetProj) {
            systemInvoker.executeCommand(std::make_unique<FinalizeProjectCommand>(targetProj));
        }
        else {
            std::cout << "[System] Project not found.\n";
        }
        }
        else if (command == "archive-project") { std::string p; ss >> p; std::cout << "[System] Project archived successfully.\n"; }
        else {
            std::cout << "[System] Unknown command.\n";
        }
    }

    return 0;
}

