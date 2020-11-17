#ifndef MOVE_PLAYER_COMMAND_H
#define MOVE_PLAYER_COMMAND_H

#include "classes/game/commands/command.h"
#include "classes/enumerations/direction.h"


class MovePlayerCommand: public Command {
private:
    Direction direction_;

public:
    MovePlayerCommand(pGameController controller, Direction direction);
    void execute();
};

#endif // MOVE_PLAYER_COMMAND_H
