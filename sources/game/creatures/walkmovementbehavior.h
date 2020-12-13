#ifndef SOURCES_GAME_OBJECTS_CREATURES_WALK_MOVEMENT_BEHAVIOR_H
#define SOURCES_GAME_OBJECTS_CREATURES_WALK_MOVEMENT_BEHAVIOR_H

#include "sources/game/creatures/movementbehavior.h"

namespace game {


class WalkMovementBehavior final: public MovementBehavior {
public:
    virtual Position2D getMovementPosition(Creature& creature, const Position2D& target_position) override;
}; // class WalkMovementBehavior


};

#endif // SOURCES_GAME_OBJECTS_CREATURES_WALK_MOVEMENT_BEHAVIOR_H
