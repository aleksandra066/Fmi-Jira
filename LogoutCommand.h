#pragma once
#include "Command.h"
#include "User.h"

class LogoutCommand : public Command
{
private:
	User& user;
public:
	LogoutCommand(User& user);
	void execute() override;
};

