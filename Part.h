#pragma once
#include "Structures.h" 
#include <string>
#include <vector>
#include <memory>

class Task; 

enum class PartStatus { Planned, Active, Finished };

class Part
{
private:
	std::string name;
	TimePoint startDate;
	TimePoint endDate;
	std::vector<std::shared_ptr<Task>> tasks;
	PartStatus status;
public:
	Part(std::string name, TimePoint startDate, TimePoint endDate);

	std::string getName() const noexcept { return name; }
	PartStatus getStatus() const noexcept { return status; }

	void setStatus(PartStatus status) noexcept { this->status = status; }

	void addTask(std::shared_ptr<Task> task);
	void generateReport() const;

	const std::vector<std::shared_ptr<Task>>& getTasks() const noexcept { return tasks; }
};

