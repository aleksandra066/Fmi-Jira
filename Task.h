#pragma once
#include "Structures.h"
#include <string>
#include <vector>
#include <memory>

class User;

enum class TaskType { Feature, Bug, Task, Improvement };
enum class Priority { Low, Medium, High, Critical };
enum class TaskStatus { ToDo, InProgress, InReview, Done };

class Task
{
private:
	unsigned int id;
	std::string title;
	std::string description;
	TaskType type;
	Priority priority;
	TaskStatus status;
	std::weak_ptr<User> assignee;
	TimePoint deadline;
	int points;
	double estimationHours;
	double grade;

	std::vector<Comment> comments;
	std::vector<HistoryRecord> historyRecord;
	std::vector<std::string> tags;

public:
	Task(unsigned int id, std::string title, std::string description,
		TaskType type, Priority priority, TimePoint deadline, int points, double estimationHours, double grade = 0.0);

	unsigned int getId() const noexcept { return id; }
	std::string getTitle() const noexcept { return title; }
	TaskStatus getStatus() const noexcept { return status; }
	TimePoint getDeadline() const noexcept { return deadline; } 
	double getEstimationHours() const noexcept { return estimationHours; }
	double getGrade() const noexcept { return grade; }
	std::weak_ptr<User> getAssignee() const noexcept { return assignee; }
	std::vector<HistoryRecord> getHistory() noexcept { return historyRecord; }

	void setStatus(TaskStatus newStatus);
	void setAssignee(std::shared_ptr<User> user);
	void setPriority(Priority priority);
	void addComment(std::shared_ptr<User> author, std::string content);
	void setGrade(double newGrade) { 
		this->grade = newGrade;
		historyRecord.emplace_back("The task has been graded with: " + std::to_string(newGrade));
	}

	const std::vector<Comment>& getComments() const noexcept { return comments; }

	void taskOstream(std::ostream& out) const;
	void load(std::ifstream& in);
};

