#include "FilterTasksCommand.h"
#include "Task.h"
#include <iostream> 
#include <ctime>

FilterTasksCommand::FilterTasksCommand(const Project& project, std::string tagFilter, bool upcomingDeadLine)
	:project(project), tagFilter(tagFilter), upcomingDeadLine(upcomingDeadLine){}

void FilterTasksCommand::execute() {
	std::cout << "\n---FILTERING RESULTS IN " << project.getName() << " ---\n";
	TimePoint now = std::time(nullptr);
	TimePoint threeDaysFromNow = now + (3 * 24 * 60 * 60);

	for (const auto& task : project.getTasks()) {
		bool matchesTag = tagFilter.empty();

		bool matchesDeadline = !upcomingDeadLine || (task->getDeadline() > now && task->getDeadline() <= threeDaysFromNow);
		if (matchesTag && matchesDeadline) {
			std::cout << "- [" << task->getId() << "] " << task->getTitle()
				<< " | Status: " << (int)task->getStatus() << "\n";
		}
	}
	std::cout << "---------------------------------------------\n";
}
