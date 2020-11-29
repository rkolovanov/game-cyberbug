#include "sources/commands/moveplayercommand.h"


MovePlayerCommand::MovePlayerCommand(const sharedGameController& controller, Direction direction)
    : Command(controller), direction_(direction) {}


void MovePlayerCommand::execute() {
    controller_->movePlayer(direction_);
}
