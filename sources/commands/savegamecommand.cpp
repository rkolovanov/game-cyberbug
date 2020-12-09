#include "sources/commands/savegamecommand.h"


SaveGameCommand::SaveGameCommand(const sharedGameController& controller): Command(controller) {}


void SaveGameCommand::execute() {
    controller_->saveGame(path_);
}


void SaveGameCommand::setPath(const std::string& path) {
    path_ = path;
}
