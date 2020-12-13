#include "sources/gui/commands/moveplayercommand.h"

namespace gui {


gui::MovePlayerCommand::MovePlayerCommand(const game::sharedGameController& controller, Direction direction)
    : Command(controller), direction_(direction) {}


void gui::MovePlayerCommand::execute() {
    controller_->movePlayer(direction_);
}


};
