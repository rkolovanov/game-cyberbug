#include "classes/game/field.h"
#include "interactionuse.h"

void InteractionUse::interact(Creature& creature, pObject& object) {
    if (object != nullptr) {
        object->executeInteraction(creature);

        if (!object->getReusable()) {
            object = nullptr;
        }
    }
}
