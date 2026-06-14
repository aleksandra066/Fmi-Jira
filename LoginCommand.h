#pragma once
#include "Command.h"
#include "User.h"

class LoginCommand :public Command
{
private:
	User& user;
	std::string attemptedPassword;
public:
	LoginCommand(User& user, std::string attemptedPassword);
	void execute() override;
};

