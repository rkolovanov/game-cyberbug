#ifndef SOURCES_COMMANDS_ATTACK_PLAYER_COMMAND_H
#define SOURCES_COMMANDS_ATTACK_PLAYER_COMMAND_H

#include "sources/commands/command.h"


class AttackPlayerCommand final: public Command {
public:
    AttackPlayerCommand(const sharedGameController& controller);

    void execute() override;
}; // class AttackPlayerCommand


#endif // SOURCES_COMMANDS_ATTACK_PLAYER_COMMAND_H
