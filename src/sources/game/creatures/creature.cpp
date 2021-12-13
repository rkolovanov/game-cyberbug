#include "sources/game/creatures/creature.h"

namespace game {


void game::Creature::operator<=(sharedCreature& creature) {
    if (creature == nullptr) {
        return;
    }

    int damage = attack_damage_ - creature->getProtection();

    if (damage < 0) {
        damage = 0;
    }

    creature->setHealth(creature->getHealth() - damage);
}


application::EventManager& game::Creature::getEventManager() {
    return event_manager_;
}


Rotation game::Creature::getRotation() const {
    return rotation_;
}


Position2D game::Creature::getPosition() const {
    return position_;
}


int game::Creature::getHealth() const {
    return health_;
}


int game::Creature::getMaxHealth() const {
    return max_health_;
}


int game::Creature::getAttackDamage() const {
    return attack_damage_;
}


int game::Creature::getProtection() const {
    return protection_;
}


void game::Creature::setRotation(Rotation rotation) {
    rotation_ = rotation;
}


void game::Creature::setPosition(Position2D position) {
    position_ = position;
}


void game::Creature::setHealth(int health) {
    if (health > max_health_) {
        health_ = max_health_;
    } else if (health < 0) {
        health_ = 0;
    } else {
        health_ = health;
    }
}


void game::Creature::setMaxHealth(int maxHealth) {
    max_health_ = maxHealth;
}


void game::Creature::setAttackDamage(int damage) {
    attack_damage_ = damage;
}


void game::Creature::setProtection(int protection) {
    protection_ = protection;
}


void game::Creature::setInteractionStrategy(const sharedInteractionStrategy& objectInteractionStrategy) {
    object_interaction_strategy_ = objectInteractionStrategy;
}


};
