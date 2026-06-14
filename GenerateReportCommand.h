#pragma once
#include "Command.h"
#include "Part.h"

class GenerateReportCommand:public Command
{
private:
	const Part& part;
public:
	explicit GenerateReportCommand(const Part& part);
	void execute() override;
};

