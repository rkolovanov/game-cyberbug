#ifndef COMMAND_H
#define COMMAND_H

#include "classes/game/gamecontroller.h"

typedef std::shared_ptr<class Command> pCommand;


class Command {
protected:
    pGameController controller_;

public:
    Command(pGameController controller);
    virtual void execute() = 0;
    virtual ~Command() = default;
};


#endif // COMMAND_H
