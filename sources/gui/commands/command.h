#ifndef SOURCES_COMMANDS_COMMAND_H
#define SOURCES_COMMANDS_COMMAND_H

#include "sources/game/gamecontroller.h"

namespace gui {

using sharedCommand = std::shared_ptr<class Command>;


class Command {
protected:
    game::sharedGameController controller_;

public:
    Command(const game::sharedGameController& controller);
    virtual ~Command() = default;

    virtual void execute() = 0;
}; // class Command


};

#endif // SOURCES_COMMANDS_COMMAND_H
