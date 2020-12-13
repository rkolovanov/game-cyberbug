#ifndef SOURCES_COMMANDS_MOVE_PLAYER_COMMAND_H
#define SOURCES_COMMANDS_MOVE_PLAYER_COMMAND_H

#include "sources/gui/commands/command.h"
#include "sources/common/direction.h"

namespace gui {


class MovePlayerCommand final: public Command {
private:
    Direction direction_;

public:
    MovePlayerCommand(const game::sharedGameController& controller, Direction direction);

    void execute() override;
}; // class MovePlayerCommand


};

#endif // SOURCES_COMMANDS_MOVE_PLAYER_COMMAND_H
