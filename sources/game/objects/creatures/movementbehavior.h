#ifndef SOURCES_GAME_OBJECTS_CREATURES_MOVEMENT_BEHAVIOR_H
#define SOURCES_GAME_OBJECTS_CREATURES_MOVEMENT_BEHAVIOR_H

#include "sources/game/objects/creatures/creature.h"

using sharedMovementBehavior = std::shared_ptr<class MovementBehavior>;


class MovementBehavior {
public:
    virtual Position2D getMovementPosition(Creature& creature, const Position2D& target_position) = 0;
}; // class MovementBehavior


#endif // SOURCES_GAME_OBJECTS_CREATURES_MOVEMENT_BEHAVIOR_H
