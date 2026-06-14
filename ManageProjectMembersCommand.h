#pragma once
#include "Command.h"
#include "Project.h"

class ManageProjectMembersCommand : public Command
{
private:
	std::shared_ptr<Project> project;
	std::shared_ptr<User> user;
	bool isAdding;
public:
	ManageProjectMembersCommand(std::shared_ptr<Project> project, std::shared_ptr<User> user, bool isAdding);
	void execute() override;
};

