#pragma once
#include "User.h"

class TeachingAssistant :public User
{
public:
	TeachingAssistant(unsigned int id, std::string username, std::string password, Role role)
		: User(id, username, password, Role::TeachingAssistant) {}
};

