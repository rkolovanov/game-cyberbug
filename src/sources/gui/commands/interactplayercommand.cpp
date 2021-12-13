#include "sources/gui/commands/interactplayercommand.h"

namespace gui {


gui::InteractPlayerCommand::InteractPlayerCommand(const game::sharedGameController& controller): Command(controller) {}


void gui::InteractPlayerCommand::execute() {
    controller_->executePlayerInteraction();
}


};
