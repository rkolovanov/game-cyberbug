#ifndef SOURCES_COMMANDS_START_LEVEL_COMMAND_H
#define SOURCES_COMMANDS_START_LEVEL_COMMAND_H

#include "sources/gui/commands/command.h"

namespace gui {


class StartLevelCommand final: public Command {
public:
    StartLevelCommand(const game::sharedGameController& controller);

    void execute() override;
}; // class StartLevelCommand


};

#endif // SOURCES_COMMANDS_START_LEVEL_COMMAND_H
