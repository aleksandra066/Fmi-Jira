#include "LoginCommand.h"
#include <iostream>
#include "string"
#include "Command.h"
#include "User.h"

LoginCommand::LoginCommand(User& user, std::string password)
    : user(user), attemptedPassword(password) {}

void LoginCommand::execute() {
    if (user.verifyPassword(attemptedPassword)) {
        std::cout << "Потребител " << user.getUsername() << "се вписа успешно!\n";
    }
    else {
        std::cout << "Грешна парола за потребител " << user.getUsername() << ".\n";
    }
}
