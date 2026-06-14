#include "LoginCommand.h"
#include <iostream>
#include "string"
#include "Command.h"
#include "User.h"

LoginCommand::LoginCommand(User& user, std::string password)
    : user(user), attemptedPassword(password) {}

void LoginCommand::execute() {
    if (user.verifyPassword(attemptedPassword)) {
        std::cout << "User " << user.getUsername() << " has logged in successfuly.\n";
    }
    else {
        std::cout << "Wrong password for user: " << user.getUsername() << ".\n";
    }
}
