#include "creature.h"

EventManager& Creature::getEventManager() {
    return eventManager_;
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
    return maxHealth_;
}

int Creature::getAttackDamage() const {
    return attackDamage_;
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
    if (health > maxHealth_) {
        health_ = maxHealth_;
    } else {
        health_ = health;
    }
}

void Creature::setMaxHealth(int maxHealth) {
    maxHealth_ = maxHealth;
}

void Creature::setAttackDamage(int damage) {
    attackDamage_ = damage;
}

void Creature::setProtection(int protection) {
    protection_ = protection;
}
