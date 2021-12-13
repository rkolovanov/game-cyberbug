#include "sources/gui/commands/attackplayercommand.h"

namespace gui {


gui::AttackPlayerCommand::AttackPlayerCommand(const game::sharedGameController& controller): Command(controller) {}


void gui::AttackPlayerCommand::execute() {
    controller_->executePlayerAttack();
}


};
