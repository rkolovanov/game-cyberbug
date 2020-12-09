#ifndef SOURCES_INTERACTIONS_INTERACTION_STRATEGY_H
#define SOURCES_INTERACTIONS_INTERACTION_STRATEGY_H

#include <memory>

#include "sources/game/interactions/interactiontype.h"

class Creature;
using sharedObject = std::shared_ptr<class Object>;
using sharedInteractionStrategy = std::shared_ptr<class InteractionStrategy>;


class InteractionStrategy {
public:
    virtual void interact(Creature& creature, sharedObject& target) = 0;
    virtual InteractionType getType() const = 0;
    virtual ~InteractionStrategy() = default;
}; // class InteractionStrategy


#endif // SOURCES_INTERACTIONS_INTERACTION_STRATEGY_H
