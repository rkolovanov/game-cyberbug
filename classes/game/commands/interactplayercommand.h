#ifndef INTERACT_PLAYER_COMMAND_H
#define INTERACT_PLAYER_COMMAND_H

#include "classes/game/commands/command.h"


class InteractPlayerCommand: public Command {
public:
    InteractPlayerCommand(pGameController controller);
    void execute();
};


#endif // INTERACT_PLAYER_COMMAND_H
