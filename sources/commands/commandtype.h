#ifndef SOURCES_COMMANDS_COMMAND_TYPE_H
#define SOURCES_COMMANDS_COMMAND_TYPE_H


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
    LoadGame
};


#endif // SOURCES_COMMANDS_COMMAND_TYPE_H
