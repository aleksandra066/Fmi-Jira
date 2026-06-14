#include "LoadDataCommand.h"
#include <fstream>

LoadDataCommand::LoadDataCommand(std::vector<std::shared_ptr<User>>& users, std::vector<std::shared_ptr<Project>>& projects, std::vector<std::shared_ptr<Task>>& tasks)
	:users(users), projects(projects), tasks(tasks){}

void LoadDataCommand::execute()
{
    std::ifstream uFile("users.txt");
    if (uFile) {
        size_t count = 0;
        uFile >> count; uFile.ignore();
        users.clear();
        for (size_t i = 0; i < count; ++i) {
            auto u = std::make_shared<User>(0, "", "", Role::Student);
            u->load(uFile);
            users.push_back(u);
        }
    }

    std::ifstream pFile("projects.txt");
    if (pFile) {
        size_t count = 0;
        pFile >> count; pFile.ignore();
        projects.clear();
        for (size_t i = 0; i < count; ++i) {
            auto p = std::make_shared<Project>("", "");
            p->load(pFile);
            projects.push_back(p);
        }
    }

    std::ifstream tFile("tasks.txt");
    if (tFile) {
        size_t count = 0;
        tFile >> count; tFile.ignore();
        tasks.clear();
        for (size_t i = 0; i < count; ++i) {
            auto t = std::make_shared<Task>(0, "", "", TaskType::Task, Priority::Low, std::time(nullptr), 0, 0.0);
            t->load(tFile);
            tasks.push_back(t);
        }
    }
    std::cout << " Autoload: Database restored successfully!\n";
}
