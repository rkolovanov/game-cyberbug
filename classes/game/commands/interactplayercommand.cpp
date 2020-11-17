#include "interactplayercommand.h"

InteractPlayerCommand::InteractPlayerCommand(pGameController controller): Command(controller) {}

void InteractPlayerCommand::execute() {
    controller_->executePlayerInteraction();
}
