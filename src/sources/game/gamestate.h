#ifndef SOURCES_GAME_GAME_STATE_H
#define SOURCES_GAME_GAME_STATE_H

#include "sources/game/gamecontroller.h"

namespace game {

using sharedGameController = std::shared_ptr<class GameController>;
using sharedGameState = std::shared_ptr<class GameState>;


class GameState {
public:
    virtual void startTurn(GameController& controller) = 0;
    virtual void endTurn(GameController& controller) = 0;
    virtual void movePlayer(GameController& controller, Direction direction) = 0;
    virtual void executePlayerInteraction(GameController& controller) = 0;
    virtual void executePlayerAttack(GameController& controller) = 0;
}; // class GameState


};

#endif // SOURCES_GAME_GAME_STATE_H
