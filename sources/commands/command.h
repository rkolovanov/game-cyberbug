#ifndef SOURCES_COMMANDS_COMMAND_H
#define SOURCES_COMMANDS_COMMAND_H

#include "sources/game/gamecontroller.h"

using sharedCommand = std::shared_ptr<class Command>;


class Command {
protected:
    sharedGameController controller_;

public:
    Command(const sharedGameController& controller);
    virtual ~Command() = default;

    virtual void execute() = 0;
}; // class Command


#endif // SOURCES_COMMANDS_COMMAND_H
