#include "GenerateReportCommand.h"

GenerateReportCommand::GenerateReportCommand(const Part& part) : part(part){}

void GenerateReportCommand::execute()
{
	part.generateReport();
}
