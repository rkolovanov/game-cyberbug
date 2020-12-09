#ifndef SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ENEMY_MEMENTO_H
#define SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ENEMY_MEMENTO_H

#include "sources/common/imemento.h"
#include "sources/game/objects/creatures/creature.h"


class EnemyMemento final: public IMemento {
private:
    int health_;
    int max_health_;
    int attack_damage_;
    int protection_;
    Position2D position_;
    Rotation rotation_;
    size_t movement_behavior_hash_;
    size_t attack_behavior_hash_;

public:
    EnemyMemento() = default;
    EnemyMemento(int health, int max_health, int damage, int protection, Position2D position,
                 Rotation rotation, size_t movement_behavior_hash, size_t attack_behavior_hash);
    int getHealth() const;
    int getMaxHealth() const;
    int getAttackDamage() const;
    int getProtection() const;
    Position2D getPosition() const;
    Rotation getRotation() const;
    size_t getMovementBehaviorHash() const;
    size_t getAttackBehaviorHash() const;
}; // class EnemyMemento


#endif // SOURCES_GAME_OBJECTS_CREATURES_ENEMIES_ENEMY_MEMENTO_H
