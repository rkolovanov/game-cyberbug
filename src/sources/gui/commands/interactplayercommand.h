#ifndef SOURCES_COMMAND_INTERACT_PLAYER_COMMAND_H
#define SOURCES_COMMAND_INTERACT_PLAYER_COMMAND_H

#include "sources/gui/commands/command.h"

namespace gui {


class InteractPlayerCommand final: public Command {
public:
    InteractPlayerCommand(const game::sharedGameController& controller);
    void execute() override;
}; // class InteractPlayerCommand


};

#endif // SOURCES_COMMAND_INTERACT_PLAYER_COMMAND_H
