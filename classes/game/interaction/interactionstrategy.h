#ifndef INTERACTION_STRATEGY_H
#define INTERACTION_STRATEGY_H

#include <memory>
#include "classes/game/objects/object.h"
#include "classes/game/objects/creatures/creature.h"

typedef std::shared_ptr<class Object> pObject;
typedef std::shared_ptr<class Creature> pCreature;
typedef std::shared_ptr<class InteractionStrategy> pInteractionStrategy;


class InteractionStrategy {
public:
    virtual void interact(Creature& creature, pObject& object) = 0;
    virtual ~InteractionStrategy() = default;
};


#endif // INTERACTION_STRATEGY_H
