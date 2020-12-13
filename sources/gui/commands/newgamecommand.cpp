#include "sources/gui/commands/newgamecommand.h"

namespace gui {


gui::NewGameCommand::NewGameCommand(const game::sharedGameController& controller): Command(controller) {}


void gui::NewGameCommand::execute() {
    controller_->newGame();
}


};
