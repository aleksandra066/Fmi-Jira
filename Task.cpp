#include "Task.h"
#include <fstream>

Task::Task(unsigned int id, std::string title, std::string description, TaskType type,
    Priority priority, TimePoint deadline, int points, double estimationHours, double grade)
    : id(id), title(title), description(description), type(type),
    priority(priority), status(TaskStatus::ToDo), deadline(deadline),
    points(points), estimationHours(estimationHours), grade(grade) {
    historyRecord.emplace_back("The task has been created.");
}

void Task::setStatus(TaskStatus newStatus)
{
    status = newStatus;
    historyRecord.emplace_back("The status has been changed! ");
}

void Task::setAssignee(std::shared_ptr<User> user)
{
    assignee = user;
    historyRecord.emplace_back("The Assignee of the task is replaced!");
}

void Task::setPriority(Priority priority)
{
    this->priority = priority; 
}

void Task::addComment(std::shared_ptr<User> author, std::string content)
{
    comments.emplace_back(author, content);
    historyRecord.emplace_back("New comment has been added!");
}

void Task::taskOstream(std::ostream& out) const
{
    out << id << "\n" << title << "\n" << description << "\n"
        << static_cast<int>(status) << "\n" << estimationHours << "\n";
}

void Task::load(std::ifstream& in)
{
    int statusInt;
    if (in >> id) {
        in.ignore();
        std::getline(in, title);
        std::getline(in, description);
        in >> statusInt; 
        in >> estimationHours;
        in.ignore();
        status = static_cast<TaskStatus>(statusInt);
    }
}




