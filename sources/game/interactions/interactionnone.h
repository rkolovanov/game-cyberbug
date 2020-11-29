#ifndef SOURCES_GAME_INTERACTIONS_INTERACTION_NONE_H
#define SOURCES_GAME_INTERACTIONS_INTERACTION_NONE_H

#include "sources/game/interactions/interactionstrategy.h"

using sharedInteractionNone = std::shared_ptr<class InteractionNone>;


class InteractionNone final: public InteractionStrategy {
public:
    void interact(Creature& creature, sharedObject& target) override;
}; // class InteractionNone


#endif // SOURCES_GAME_INTERACTIONS_INTERACTION_NONE_H
