#include "ManagePartStateCommand.h"
#include <iostream>

ManagePartStateCommand::ManagePartStateCommand(Part& part, PartStatus newState)
	:part(part), newState(newState){}

void ManagePartStateCommand::execute()
{
    part.setStatus(newState);
    std::cout << "The status of the stage '" << part.getName() << "' has been changed to ";
    if (newState == PartStatus::Active) std::cout << "ACTIVE.\n";
    if (newState == PartStatus::Finished) std::cout << "FINISHED.\n";
}
