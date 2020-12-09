#include "sources/game/interactions/interactionnone.h"


void InteractionNone::interact(Creature&, sharedObject&) {}


InteractionType InteractionNone::getType() const {
    return InteractionType::None;
}
