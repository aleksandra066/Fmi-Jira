#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Command.h"
#include "Project.h"

class ViewStudentStatisticsCommand: public Command
{
private:
	const Project& project;
public:
	explicit ViewStudentStatisticsCommand(const Project& project);
	void execute() override;
};

