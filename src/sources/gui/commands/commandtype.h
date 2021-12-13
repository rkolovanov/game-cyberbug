#ifndef SOURCES_COMMANDS_COMMAND_TYPE_H
#define SOURCES_COMMANDS_COMMAND_TYPE_H

namespace gui {


enum class CommandType {
    None,
    MovePlayerTop,
    MovePlayerBottom,
    MovePlayerLeft,
    MovePlayerRight,
    InteractPlayer,
    AttackPlayer,
    StartLevel,
    SaveGame,
    LoadGame,
    NewGame
};


};

#endif // SOURCES_COMMANDS_COMMAND_TYPE_H
