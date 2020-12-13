#ifndef SOURCES_COMMANDS_SAVE_GAME_COMMAND_H
#define SOURCES_COMMANDS_SAVE_GAME_COMMAND_H

#include "sources/gui/commands/command.h"

namespace gui {


class SaveGameCommand final: public Command {
private:
    std::string path_;

public:
    SaveGameCommand(const game::sharedGameController& controller);

    void execute() override;
    void setPath(const std::string& path);
}; // class SaveGameCommand


};

#endif // SOURCES_COMMANDS_SAVE_GAME_COMMAND_H
