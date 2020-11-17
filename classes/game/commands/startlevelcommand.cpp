#include "startlevelcommand.h"

StartLevelCommand::StartLevelCommand(pGameController controller): Command(controller) {}

void StartLevelCommand::execute() {
    controller_->createLevel();
}
