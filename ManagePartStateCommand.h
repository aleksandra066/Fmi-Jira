#pragma once
#include "Command.h"
#include "Project.h"
#include "User.h"
#include <memory>

class ManagePartStateCommand : public Command
{
private:
	Part& part;
	PartStatus newState;
public:
	ManagePartStateCommand(Part& part, PartStatus newState);
	void execute() override;
};

