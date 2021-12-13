#ifndef SOURCES_COMMANDS_LOAD_GAME_COMMAND_H
#define SOURCES_COMMANDS_LOAD_GAME_COMMAND_H

#include "sources/gui/commands/command.h"

namespace gui {


class LoadGameCommand final: public Command {
private:
    std::string path_;

public:
    LoadGameCommand(const game::sharedGameController& controller);

    void execute() override;
    void setPath(const std::string& path);
}; // class LoadGameCommand


};

#endif // SOURCES_COMMANDS_LOAD_GAME_COMMAND_H
