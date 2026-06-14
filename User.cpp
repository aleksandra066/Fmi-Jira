#include "User.h"
#include <fstream>

User::User(unsigned int id, std::string username, std::string password, Role role) : id(id),
username(username), password(password), role(role)
{
}

unsigned int User::getId() const noexcept
{
	return id;
}
std::string User::getUsername() const noexcept
{
	return username;
}
Role User::getRole() const noexcept
{
	return role;
}

void User::setUsername(std::string username)
{
	this->username = username;
}
void User::setPassword(std::string password)
{
	this->password = password;
}
void User::setRole(Role role) noexcept
{
	this->role = role;
}

bool User::verifyPassword(std::string password) const noexcept
{
	return this->password == password;
}

void User::userOfstream(std::ofstream& out) const
{
	out << id << "\n"
		<< username << "\n"
		<< password << "\n"
		<< static_cast<int>(role) << "\n";
}

void User::load(std::ifstream& in)
{
	unsigned int id;
	std::string username; 
	std::string password;
	int roleInt;

	if (in >> id) {
		in.ignore();
		std::getline(in, username);
		std::getline(in, password);
		in >> roleInt;
		in.ignore();
		this->id = id;
		this->username = username;
		this->password = password;
		this->role = static_cast<Role>(roleInt);
	}
}
