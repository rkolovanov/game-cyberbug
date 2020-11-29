#ifndef SOURCES_GAME_INTERACTIONS_INTERACTION_USE_H
#define SOURCES_GAME_INTERACTIONS_INTERACTION_USE_H

#include "sources/game/interactions/interactionstrategy.h"

using sharedInteractionUse = std::shared_ptr<class InteractionUse>;


class InteractionUse final: public InteractionStrategy {
public:
    void interact(Creature& creature, sharedObject& target) override;
}; // class InteractionUse


#endif // SOURCES_GAME_INTERACTIONS_INTERACTION_USE_H
