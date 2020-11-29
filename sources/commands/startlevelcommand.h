#ifndef SOURCES_COMMANDS_START_LEVEL_COMMAND_H
#define SOURCES_COMMANDS_START_LEVEL_COMMAND_H

#include "sources/commands/command.h"


class StartLevelCommand final: public Command {
public:
    StartLevelCommand(const sharedGameController& controller);

    void execute() override;
}; // class StartLevelCommand


#endif // SOURCES_COMMANDS_START_LEVEL_COMMAND_H
