#pragma once
#include <vector>
#include <memory>
#include "Command.h"

class CommandExecute
{
private:
	std::vector<std::unique_ptr<Command>> history;
public:
	void executeCommand(std::unique_ptr<Command> cmd) {
		if (cmd) {
			cmd->execute();
			history.push_back(std::move(cmd));
		}
	}
};

