#include "SaveDataCommand.h"
#include <fstream>

SaveDataCommand::SaveDataCommand(const std::vector<std::shared_ptr<User>>& users, const std::vector<std::shared_ptr<Project>>& projects, const std::vector<std::shared_ptr<Task>>& tasks)
	:users(users), projects(projects), tasks(tasks){}

void SaveDataCommand::execute()
{
    std::ofstream uFile("users.txt");
    if (uFile) {
        uFile << users.size() << "\n";
        for (const auto& u : users) u->userOfstream(uFile);
    }

    std::ofstream pFile("projects.txt");
    if (pFile) {
        pFile << projects.size() << "\n";
        for (const auto& p : projects) p->projectOstream(pFile);
    }

    std::ofstream tFile("tasks.txt");
    if (tFile) {
        tFile << tasks.size() << "\n";
        for (const auto& t : tasks) t->taskOstream(tFile);
    }

    std::cout << "auto save: all states were save in users.txt, projects.txt, tasks.txt.\n";
}
