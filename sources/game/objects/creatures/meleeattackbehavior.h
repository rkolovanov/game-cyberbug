#ifndef SOURCES_GAME_OBJECTS_CREATURES_MELEE_ATTACK_BEHAVIOR_H
#define SOURCES_GAME_OBJECTS_CREATURES_MELEE_ATTACK_BEHAVIOR_H

#include "sources/game/objects/creatures/attackbehavior.h"


class MeleeAttackBehavior final: public AttackBehavior {
public:
    virtual void attack(Creature& creature, sharedCreature& target) override;
}; // class MeleeAttackBehavior


#endif // SOURCES_GAME_OBJECTS_CREATURES_MELEE_ATTACK_BEHAVIOR_H
