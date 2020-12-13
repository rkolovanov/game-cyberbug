#ifndef SOURCES_GAME_OBJECTS_CREATURES_ATTACK_BEHAVIOR_H
#define SOURCES_GAME_OBJECTS_CREATURES_ATTACK_BEHAVIOR_H

#include "sources/game/creatures/creature.h"

namespace game {

using sharedAttackBehavior = std::shared_ptr<class AttackBehavior>;


class AttackBehavior {
public:
    virtual void attack(Creature& creature, sharedCreature& target) = 0;
}; // class AttackBehavior


};

#endif // SOURCES_GAME_OBJECTS_CREATURES_ATTACK_BEHAVIOR_H
