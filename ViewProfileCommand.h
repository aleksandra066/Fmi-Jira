#pragma once
#include <iostream>
#include "string"
#include "Command.h"
#include "User.h"

class ViewProfileCommand : public Command
{
private:
	const User& user;
public:
	explicit ViewProfileCommand(const User& user);
	void execute() override;
};

