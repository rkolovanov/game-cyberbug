#include "sources/game/field.h"
#include "sources/game/interactions/interactionuse.h"


void InteractionUse::interact(Creature& creature, sharedObject& target) {
    if (target != nullptr) {
        target->executeInteraction(creature);

        if (!target->getReusable()) {
            target.reset();
        }
    }
}


InteractionType InteractionUse::getType() const {
    return InteractionType::Use;
}
