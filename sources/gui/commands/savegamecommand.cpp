#include "sources/gui/commands/savegamecommand.h"

namespace gui {


gui::SaveGameCommand::SaveGameCommand(const game::sharedGameController& controller): Command(controller) {}


void gui::SaveGameCommand::execute() {
    controller_->saveGame(path_);
}


void gui::SaveGameCommand::setPath(const std::string& path) {
    path_ = path;
}


};
