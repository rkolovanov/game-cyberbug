#ifndef SOURCES_COMMANDS_NEW_GAME_COMMAND_H
#define SOURCES_COMMANDS_NEW_GAME_COMMAND_H

#include "sources/commands/command.h"


class NewGameCommand final: public Command {
public:
    NewGameCommand(const sharedGameController& controller);

    void execute() override;
}; // class NewGameCommand


#endif // SOURCES_COMMANDS_NEW_GAME_COMMAND_H
