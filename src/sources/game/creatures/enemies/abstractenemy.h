#ifndef SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ABSTRACT_ENEMY_H
#define SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ABSTRACT_ENEMY_H

#include <memory>
#include <vector>

#include "sources/game/creatures/creature.h"
#include "sources/game/interactions/interactionnone.h"
#include "sources/game/creatures/enemies/enemymemento.h"

namespace game {

using sharedAbstractEnemy = std::shared_ptr<class AbstractEnemy>;
using Enemies = std::vector<sharedAbstractEnemy>;


class AbstractEnemy: public Creature {
public:
    void operator<=(sharedObject& object) override = 0;
    void operator<=(sharedCreature& creature) override = 0;
    virtual Position2D getMovementPosition(const Position2D& target_position) = 0;
    virtual void tryAttack(sharedCreature& target) = 0;
    const std::type_info& getClass() const override = 0;
    virtual EnemyMemento save() const = 0;
    virtual void restore(const EnemyMemento& snapshot) = 0;
}; // class AbstractEnem


};

#endif // SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ABSTRACT_ENEMY_H
