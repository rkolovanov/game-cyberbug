#ifndef SOURCES_COMMANDS_ATTACK_PLAYER_COMMAND_H
#define SOURCES_COMMANDS_ATTACK_PLAYER_COMMAND_H

#include "sources/gui/commands/command.h"

namespace gui {


class AttackPlayerCommand final: public Command {
public:
    AttackPlayerCommand(const game::sharedGameController& controller);

    void execute() override;
}; // class AttackPlayerCommand


};

#endif // SOURCES_COMMANDS_ATTACK_PLAYER_COMMAND_H
