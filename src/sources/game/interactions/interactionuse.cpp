#include "sources/game/field.h"
#include "sources/game/interactions/interactionuse.h"

namespace game {


void game::InteractionUse::interact(Creature& creature, sharedObject& target) {
    if (target != nullptr) {
        target->executeInteraction(creature);

        if (!target->getReusable()) {
            target.reset();
        }
    }
}


game::InteractionType game::InteractionUse::getType() const {
    return InteractionType::Use;
}


};
