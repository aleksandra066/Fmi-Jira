#pragma once
#include <vector>
#include <memory>
#include "User.h"
#include "Task.h"
#include "Command.h"

class MyTasksCommand:public Command
{
private:
    const std::vector<std::shared_ptr<Task>>& allTasks;
    std::shared_ptr<User> currentUser;
public:
    MyTasksCommand(const std::vector<std::shared_ptr<Task>>& allTasks, std::shared_ptr<User> currentUser);
    void execute() override;
};

