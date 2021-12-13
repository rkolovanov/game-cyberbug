#ifndef SOURCES_COMMANDS_NEW_GAME_COMMAND_H
#define SOURCES_COMMANDS_NEW_GAME_COMMAND_H

#include "sources/gui/commands/command.h"

namespace gui {


class NewGameCommand final: public Command {
public:
    NewGameCommand(const game::sharedGameController& controller);

    void execute() override;
}; // class NewGameCommand


};

#endif // SOURCES_COMMANDS_NEW_GAME_COMMAND_H
