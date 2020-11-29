#include "sources/commands/interactplayercommand.h"


InteractPlayerCommand::InteractPlayerCommand(const sharedGameController& controller): Command(controller) {}


void InteractPlayerCommand::execute() {
    controller_->executePlayerInteraction();
}
