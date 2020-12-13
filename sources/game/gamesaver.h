#ifndef SOURCES_GAME_GAME_SAVER_H
#define SOURCES_GAME_GAME_SAVER_H

#include <string>
#include <fstream>

#include "sources/logging/logger.h"
#include "sources/common/eventmanager.h"
#include "sources/game/creatures/player/player.h"
#include "sources/game/creatures/enemies/abstractenemy.h"

namespace game {


class GameSaver final {
private:
    EventManager event_manager_;
    std::ofstream file_;
    bool error_;

public:
    GameSaver(const std::string& path, const sharedEventListener& logging_listener);
    ~GameSaver();

    bool isInvalid() const;
    void save(const sharedPlayer& player, const Enemies& enemies);
}; // class GameSaver


};

#endif // SOURCES_GAME_GAME_SAVER_H
