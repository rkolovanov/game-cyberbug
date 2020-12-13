#include "sources/gui/commands/loadgamecommand.h"

namespace gui {


gui::LoadGameCommand::LoadGameCommand(const game::sharedGameController& controller): Command(controller) {}


void gui::LoadGameCommand::execute() {
    controller_->loadGame(path_);
}


void gui::LoadGameCommand::setPath(const std::string& path) {
    path_ = path;
}


};
