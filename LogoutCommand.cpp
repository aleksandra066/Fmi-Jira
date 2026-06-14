#include "LogoutCommand.h"
#include <iostream>

LogoutCommand::LogoutCommand(User& user) : user(user) {}

void LogoutCommand::execute() {
    std::cout << "User '" << user.getUsername() << "' left the system.\n";
}
