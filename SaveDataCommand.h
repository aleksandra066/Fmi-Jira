#pragma once
#include "Command.h"
#include "Project.h"
#include "Task.h"

class SaveDataCommand : public Command
{
private:
    const std::vector<std::shared_ptr<User>>& users;
    const std::vector<std::shared_ptr<Project>>& projects;
    const std::vector<std::shared_ptr<Task>>& tasks;
public:
    SaveDataCommand(const std::vector<std::shared_ptr<User>>& users,
        const std::vector<std::shared_ptr<Project>>& projects,
        const std::vector<std::shared_ptr<Task>>& tasks);
    void execute() override;
};

