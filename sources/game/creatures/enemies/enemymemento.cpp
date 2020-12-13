#include "sources/game/creatures/enemies/enemymemento.h"

namespace game {


game::EnemyMemento::EnemyMemento(int health, int max_health, int damage, int protection, Position2D position,
                           Rotation rotation, size_t movement_behavior_hash, size_t attack_behavior_hash)
    : health_(health), max_health_(max_health), attack_damage_(damage), protection_(protection),
      position_(position), rotation_(rotation), movement_behavior_hash_(movement_behavior_hash),
      attack_behavior_hash_(attack_behavior_hash) {}


int game::EnemyMemento::getHealth() const {
    return health_;
}


int game::EnemyMemento::getMaxHealth() const {
    return max_health_;
}


int game::EnemyMemento::getAttackDamage() const {
    return attack_damage_;
}


int game::EnemyMemento::getProtection() const {
    return protection_;
}


Position2D game::EnemyMemento::getPosition() const {
    return position_;
}


Rotation game::EnemyMemento::getRotation() const {
    return rotation_;
}


size_t game::EnemyMemento::getMovementBehaviorHash() const {
    return movement_behavior_hash_;
}


size_t game::EnemyMemento::getAttackBehaviorHash() const {
    return attack_behavior_hash_;
}


};
