#include "sources/commands/loadgamecommand.h"


LoadGameCommand::LoadGameCommand(const sharedGameController& controller): Command(controller) {}


void LoadGameCommand::execute() {
    controller_->loadGame(path_);
}


void LoadGameCommand::setPath(const std::string& path) {
    path_ = path;
}
