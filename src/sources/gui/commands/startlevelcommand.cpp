#include "sources/gui/commands/startlevelcommand.h"

namespace gui {


gui::StartLevelCommand::StartLevelCommand(const game::sharedGameController& controller): Command(controller) {}


void gui::StartLevelCommand::execute() {
    controller_->createLevel();
}


};
