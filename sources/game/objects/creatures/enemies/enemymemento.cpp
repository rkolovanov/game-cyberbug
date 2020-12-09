#include "sources/game/objects/creatures/enemies/enemymemento.h"


EnemyMemento::EnemyMemento(int health, int max_health, int damage, int protection, Position2D position,
                           Rotation rotation, size_t movement_behavior_hash, size_t attack_behavior_hash)
    : health_(health), max_health_(max_health), attack_damage_(damage), protection_(protection),
      position_(position), rotation_(rotation), movement_behavior_hash_(movement_behavior_hash),
      attack_behavior_hash_(attack_behavior_hash) {}


int EnemyMemento::getHealth() const {
    return health_;
}


int EnemyMemento::getMaxHealth() const {
    return max_health_;
}


int EnemyMemento::getAttackDamage() const {
    return attack_damage_;
}


int EnemyMemento::getProtection() const {
    return protection_;
}


Position2D EnemyMemento::getPosition() const {
    return position_;
}


Rotation EnemyMemento::getRotation() const {
    return rotation_;
}


size_t EnemyMemento::getMovementBehaviorHash() const {
    return movement_behavior_hash_;
}


size_t EnemyMemento::getAttackBehaviorHash() const {
    return attack_behavior_hash_;
}
