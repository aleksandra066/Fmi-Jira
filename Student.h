#pragma once
#include "User.h"

class Student: public User
{
public:
	Student(unsigned int id, std::string username, std::string password)
		: User(id, username, password, Role::Student) {}

};

