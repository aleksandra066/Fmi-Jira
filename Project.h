#pragma once
#include "Part.h" 
#include <string> 
#include <vector> 
#include <memory>

class User;
class Task;

enum class ProjectStatus{Active, Finished};

class Project
{
private:
	std::string name;
	std::string description;
	std::vector<std::shared_ptr<User>> members;
	std::vector<std::shared_ptr<Task>> tasks;
	std::vector<Part> parts;
	ProjectStatus status;

public:
	Project(std::string name, std::string description);

	void addMember(std::shared_ptr<User> user);
	void addTask(std::shared_ptr<Task> task);
	void addPart(const Part& part);

	void setStatus(ProjectStatus status) noexcept { this->status = status; }
	ProjectStatus getStatus() const noexcept { return status; }

	std::string getName() const noexcept { return name; }
	const std::vector<std::shared_ptr<Task>>& getTasks() const noexcept { return tasks; }

	void finaliseProject();

	void projectOstream(std::ofstream& out) const;
	void load(std::ifstream& in);
};

