#ifndef INTERACTION_NONE_H
#define INTERACTION_NONE_H

#include "classes/game/interaction/interactionstrategy.h"

typedef std::shared_ptr<class InteractionNone> pInteractionNone;


class InteractionNone: public InteractionStrategy {
public:
    void interact(Creature& creature, pObject& object);
};


#endif // INTERACTION_NONE_H
