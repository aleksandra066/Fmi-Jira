#pragma once
#include "User.h"

class Administrator : public User
{
private:
	Administrator();
public:
    Administrator(const Administrator&) = delete;
    Administrator& operator=(const Administrator&) = delete;
    Administrator(Administrator&&) = delete;
    Administrator& operator=(Administrator&&) = delete;

    static Administrator& getInstance();

    void shutdownSystem() const;
};

