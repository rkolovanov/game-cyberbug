#include "sources/game/interactions/interactionnone.h"

namespace game {


void game::InteractionNone::interact(Creature&, sharedObject&) {}


game::InteractionType game::InteractionNone::getType() const {
    return InteractionType::None;
}


};
