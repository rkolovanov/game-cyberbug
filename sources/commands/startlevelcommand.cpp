#include "sources/commands/startlevelcommand.h"


StartLevelCommand::StartLevelCommand(const sharedGameController& controller): Command(controller) {}


void StartLevelCommand::execute() {
    controller_->createLevel();
}
