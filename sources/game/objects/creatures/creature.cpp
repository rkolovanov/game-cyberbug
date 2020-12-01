#include "sources/game/objects/creatures/creature.h"


void Creature::operator<=(sharedCreature& creature) {
    if (creature == nullptr) {
        return;
    }

    int damage = attack_damage_ - creature->getProtection();

    if (damage < 0) {
        damage = 0;
    }

    creature->setHealth(creature->getHealth() - damage);
}


EventManager& Creature::getEventManager() {
    return event_manager_;
}


Rotation Creature::getRotation() const {
    return rotation_;
}


Position2D Creature::getPosition() const {
    return position_;
}


int Creature::getHealth() const {
    return health_;
}


int Creature::getMaxHealth() const {
    return max_health_;
}


int Creature::getAttackDamage() const {
    return attack_damage_;
}


int Creature::getProtection() const {
    return protection_;
}


void Creature::setRotation(Rotation rotation) {
    rotation_ = rotation;
}


void Creature::setPosition(Position2D position) {
    position_ = position;
}


void Creature::setHealth(int health) {
    if (health > max_health_) {
        health_ = max_health_;
    } else if (health < 0) {
        health_ = 0;
    } else {
        health_ = health;
    }
}


void Creature::setMaxHealth(int maxHealth) {
    max_health_ = maxHealth;
}


void Creature::setAttackDamage(int damage) {
    attack_damage_ = damage;
}


void Creature::setProtection(int protection) {
    protection_ = protection;
}


void Creature::setInteractionStrategy(const sharedInteractionStrategy& objectInteractionStrategy) {
    object_interaction_strategy_ = objectInteractionStrategy;
}
