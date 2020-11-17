#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

enum class CommandType {
    None,
    MovePlayerTop,
    MovePlayerBottom,
    MovePlayerLeft,
    MovePlayerRight,
    InteractPlayer,
    StartLevel
};

#endif // COMMAND_TYPE_H
