#ifndef SOURCES_GAME_GAME_LOADER_H
#define SOURCES_GAME_GAME_LOADER_H

#include <string>
#include <fstream>

#include "sources/logging/logger.h"
#include "sources/application/eventmanager.h"
#include "sources/game/creatures/player/player.h"
#include "sources/game/creatures/enemies/abstractenemy.h"

namespace game {


class GameLoader final {
private:
    const application::sharedEventListener& logging_listener_;
    application::EventManager event_manager_;
    std::ifstream file_;
    bool error_;

public:
    GameLoader(const std::string& path, const application::sharedEventListener& logging_listener);
    ~GameLoader();

    bool isInvalid() const;
    void load(sharedPlayer& player, Enemies& enemies, size_t& level);
}; // class GameLoader


};

#endif // SOURCES_GAME_GAME_SAVER_H
