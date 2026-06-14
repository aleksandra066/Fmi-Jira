#pragma once
#include <vector>
#include <memory>
#include <string>
#include "Command.h"
#include "Task.h"

class StudentReportCommand: public Command
{
private:
    const std::vector<std::shared_ptr<Task>>& allTasks;
    std::string targetUsername;
public:
    StudentReportCommand(const std::vector<std::shared_ptr<Task>>& allTasks, std::string targetUsername);
    void execute() override;
};

