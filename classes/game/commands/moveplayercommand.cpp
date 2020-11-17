#include "moveplayercommand.h"

MovePlayerCommand::MovePlayerCommand(pGameController controller, Direction direction): Command(controller), direction_(direction) {}

void MovePlayerCommand::execute() {
    controller_->movePlayer(direction_);
}
