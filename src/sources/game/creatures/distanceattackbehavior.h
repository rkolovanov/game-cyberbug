#ifndef SOURCES_GAME_OBJECTS_CREATURES_DISTANCE_BEHAVIOR_H
#define SOURCES_GAME_OBJECTS_CREATURES_DISTANCE_BEHAVIOR_H

#include "sources/game/creatures/attackbehavior.h"

namespace game {


class DistanceAttackBehavior final: public AttackBehavior {
public:
    virtual void attack(Creature& creature, sharedCreature& target) override;
}; // class DistanceAttackBehavior


};

#endif // SOURCES_GAME_OBJECTS_CREATURES_DISTANCE_BEHAVIOR_H
