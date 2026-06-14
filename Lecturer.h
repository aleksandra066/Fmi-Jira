#pragma once
#include "User.h"

class Lecturer :public User
{
public:
	Lecturer(unsigned int id, std::string username, std::string password, Role role)
		: User(id, username, password, Role::Lecturer) {}
};

