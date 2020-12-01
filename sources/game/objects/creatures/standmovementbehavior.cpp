#include "sources/game/objects/creatures/standmovementbehavior.h"


Position2D StandMovementBehavior::getMovementPosition(Creature& creature, const Position2D&) {
    return creature.getPosition();
}
