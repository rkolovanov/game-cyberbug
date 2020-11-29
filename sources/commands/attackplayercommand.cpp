#include "sources/commands/attackplayercommand.h"


AttackPlayerCommand::AttackPlayerCommand(const sharedGameController& controller): Command(controller) {}


void AttackPlayerCommand::execute() {
    controller_->executePlayerAttack();
}
