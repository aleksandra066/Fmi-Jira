#include "Administrator.h"
#include <iostream>

Administrator::Administrator()
    : User(0, "admin", "Password2006", Role::Admin) {}

Administrator& Administrator::getInstance() {
    static Administrator instance;
    return instance;
}

void Administrator::shutdownSystem() const {
    std::cout << "System is shutting down by Administrator: " << getUsername() << "\n";
}
