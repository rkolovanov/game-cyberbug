#include "sources/game/creatures/standmovementbehavior.h"

namespace game {


Position2D game::StandMovementBehavior::getMovementPosition(Creature& creature, const Position2D&) {
    return creature.getPosition();
}


};
