#include "ViewProfileCommand.h"

ViewProfileCommand::ViewProfileCommand(const User& user) : user(user) {}

void ViewProfileCommand::execute() {
    std::cout << "\n=== USER PROFILE ===" << "\n";
    std::cout << "ID: " << user.getId() << "\n";
    std::cout << "Username: " << user.getUsername() << "\n";
    std::cout << "Role: ";
    switch (user.getRole()) {
    case Role::Admin:
        std::cout << "Administrator\n";
        break;
    case Role::Lecturer:
        std::cout << "Lecturer\n";
        break;
    case Role::TeachingAssistant:
        std::cout << "Assistant\n";
        break;
    case Role::Student:
        std::cout << "Student\n";
        break;
    }
    std::cout << "============================\n\n";
}


