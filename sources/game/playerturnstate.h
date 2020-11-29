#ifndef SOURCES_GAME_PLAYER_TURN_STATE_H
#define SOURCES_GAME_PLAYER_TURN_STATE_H

#include "sources/game/gamestate.h"

using sharedPlayerTurnState = std::shared_ptr<class PlayerTurnState>;


class PlayerTurnState final: public GameState {
public:
    virtual void startTurn(GameController& controller) override;
    virtual void endTurn(GameController& controller) override;
    virtual void movePlayer(GameController& controller, Direction direction) override;
    virtual void executePlayerInteraction(GameController& controller) override;
    virtual void executePlayerAttack(GameController& controller) override;
}; // class PlayerTurnState


#endif // SOURCES_GAME_PLAYER_TURN_STATE_H
