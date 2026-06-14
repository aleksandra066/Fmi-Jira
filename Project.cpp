#include "Project.h"
#include "User.h"  
#include "Task.h"  
#include <fstream>
#include <string>

Project::Project(std::string name, std::string description) :name(name),
description(description), status(ProjectStatus::Active) {}

void Project::addMember(std::shared_ptr<User> user)
{
	if (user) {
		members.push_back(user);
	}
}

void Project::addTask(std::shared_ptr<Task> task)
{
	if (task) {
		tasks.push_back(task);
	}
}

void Project::addPart(const Part& part)
{
	parts.push_back(part);
}

void Project::projectOstream(std::ofstream& out) const
{
	out << name << "\n" << description << static_cast<int>(status) << "\n";
}

void Project::load(std::ifstream& in)
{
	if (std::getline(in, name)) {
		std::getline(in, description);
		int statusInt;
		in >> statusInt;
		in.ignore();
		status = static_cast<ProjectStatus>(statusInt);
	}
}

void Project::finaliseProject()
{
	status = ProjectStatus::Finished;
	for (auto& task : tasks) {
		if (task->getStatus() != TaskStatus::Done) {
			task->setStatus(TaskStatus::Done);
		}
	}
}
