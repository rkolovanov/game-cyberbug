#ifndef INTERACTION_USE_H
#define INTERACTION_USE_H

#include "classes/game/interaction/interactionstrategy.h"

typedef std::shared_ptr<class InteractionUse> pInteractionUse;


class InteractionUse: public InteractionStrategy {
public:
    void interact(Creature& creature, pObject& object);
};


#endif // INTERACTION_USE_H
