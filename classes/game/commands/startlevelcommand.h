#ifndef START_LEVEL_COMMAND_H
#define START_LEVEL_COMMAND_H

#include "classes/game/commands/command.h"


class StartLevelCommand: public Command {
public:
    StartLevelCommand(pGameController controller);
    void execute();
};


#endif // START_LEVEL_COMMAND_H
