#ifndef SOURCES_COMMANDS_SAVE_GAME_COMMAND_H
#define SOURCES_COMMANDS_SAVE_GAME_COMMAND_H

#include "sources/commands/command.h"


class SaveGameCommand final: public Command {
private:
    std::string path_;

public:
    SaveGameCommand(const sharedGameController& controller);

    void execute() override;
    void setPath(const std::string& path);
}; // class SaveGameCommand


#endif // SOURCES_COMMANDS_SAVE_GAME_COMMAND_H
