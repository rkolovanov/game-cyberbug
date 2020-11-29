#ifndef SOURCES_COMMAND_INTERACT_PLAYER_COMMAND_H
#define SOURCES_COMMAND_INTERACT_PLAYER_COMMAND_H

#include "sources/commands/command.h"


class InteractPlayerCommand final: public Command {
public:
    InteractPlayerCommand(const sharedGameController& controller);
    void execute() override;
}; // class InteractPlayerCommand


#endif // SOURCES_COMMAND_INTERACT_PLAYER_COMMAND_H
