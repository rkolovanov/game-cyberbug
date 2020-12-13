#include "sources/commands/newgamecommand.h"


NewGameCommand::NewGameCommand(const sharedGameController& controller): Command(controller) {}


void NewGameCommand::execute() {
    controller_->newGame();
}
