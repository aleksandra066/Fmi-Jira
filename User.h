#pragma once
#include <iostream>
#include "string"
#include "vector"
#include "memory"

class Project;

enum class Role {
	Admin,
	Lecturer,
	TeachingAssistant,
	Student
};

class User
{
protected:
	unsigned int id;
	std::string username;
	std::string password;
	Role role;
	std::vector<std::shared_ptr<Project>> joinedProjects;

public:
	User(unsigned int id, std::string username, std::string password, Role role);
	virtual ~User() = default;

	unsigned int getId() const noexcept;
	std::string getUsername() const noexcept;
	Role getRole() const noexcept;

	void setUsername(std::string username);
	void setPassword(std::string password);
	void setRole(Role role) noexcept;

	bool verifyPassword(std::string password) const noexcept;

	void userOfstream(std::ofstream& out) const;
	void load(std::ifstream& in);
};

