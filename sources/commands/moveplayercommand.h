#ifndef SOURCES_COMMANDS_MOVE_PLAYER_COMMAND_H
#define SOURCES_COMMANDS_MOVE_PLAYER_COMMAND_H

#include "sources/commands/command.h"
#include "sources/common/direction.h"


class MovePlayerCommand final: public Command {
private:
    Direction direction_;

public:
    MovePlayerCommand(const sharedGameController& controller, Direction direction);

    void execute() override;
}; // class MovePlayerCommand


#endif // SOURCES_COMMANDS_MOVE_PLAYER_COMMAND_H
