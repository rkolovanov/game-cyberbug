#ifndef SOURCES_GAME_ENEMIES_TURN_STATE_H
#define SOURCES_GAME_ENEMIES_TURN_STATE_H

#include "sources/game/gamestate.h"

using sharedEnemiesTurnState = std::shared_ptr<class EnemiesTurnState>;


class EnemiesTurnState final: public GameState {
public:
    virtual void startTurn(GameController& controller) override;
    virtual void endTurn(GameController& controller) override;
    virtual void movePlayer(GameController& controller, Direction direction) override;
    virtual void executePlayerInteraction(GameController& controller) override;
    virtual void executePlayerAttack(GameController& controller) override;
}; // class EnemiesTurnState


#endif // SOURCES_GAME_ENEMIES_TURN_STATE_H
