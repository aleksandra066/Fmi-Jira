#include "Part.h"
#include "Task.h" 
#include <iostream>

Part::Part(std::string name, TimePoint startDate, TimePoint endDate) :name(name),
startDate(startDate), endDate(endDate), status(PartStatus::Planned){}

void Part::addTask(std::shared_ptr<Task> task)
{
	if (task) {
		tasks.push_back(task);
	}
}

void Part::generateReport() const
{
	int totalTasks = tasks.size();
	int completedTasks = 0;
	int inProgressTasks = 0;
	int toDoTasks = 0;
	double totalEstimationHours = 0.0;

	for (const auto& task : tasks) {
		totalEstimationHours += task->getEstimationHours();

		switch (task->getStatus()) {
		case TaskStatus::Done :
			completedTasks++;
			break;
		case TaskStatus::InProgress:
			inProgressTasks++;
			break;
		case TaskStatus::ToDo:
			toDoTasks++;
			break;
		case TaskStatus::InReview:
			inProgressTasks++;
			break;
		}
	}
	double progressPercent = (totalTasks > 0) ? (static_cast<double>(completedTasks) / totalTasks) * 100.0 : 0.0;

	std::cout << "\n=============================================\n";
	std::cout << "STAGE REPORT: " << name << "\n";
	std::cout << "Stage status: " << (status == PartStatus::Active ? "ACTIVE" :
		status == PartStatus::Finished ? "FINISHED" : "PLANNED") << "\n";
	std::cout << "---------------------------------------------\n";
	std::cout << "All tasks count: " << totalTasks << "\n";
	std::cout << " - ToDo: " << toDoTasks << "\n";
	std::cout << " - InProgress/Review: " << inProgressTasks << "\n";
	std::cout << " - Done: " << completedTasks << "\n";
	std::cout << "Total predicted time: " << totalEstimationHours << " hours.\n";
	std::cout << "Progress: " << progressPercent << "%\n";
	std::cout << "=============================================\n\n";
}
