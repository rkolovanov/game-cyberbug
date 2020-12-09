#include "sources/game/objects/creatures/player/playermemento.h"


PlayerMemento::PlayerMemento(int health, int max_health, int damage, int protection, Position2D position,
                             Rotation rotation, InteractionType interaction_type, bool pass_founded)
    : health_(health), max_health_(max_health), attack_damage_(damage), protection_(protection),
      position_(position), rotation_(rotation), interaction_type_(interaction_type),
      pass_founded_(pass_founded) {}


int PlayerMemento::getHealth() const {
    return health_;
}


int PlayerMemento::getMaxHealth() const {
    return max_health_;
}


int PlayerMemento::getAttackDamage() const {
    return attack_damage_;
}


int PlayerMemento::getProtection() const {
    return protection_;
}


Position2D PlayerMemento::getPosition() const {
    return position_;
}


Rotation PlayerMemento::getRotation() const {
    return rotation_;
}


InteractionType PlayerMemento::getInteractionType() const {
    return interaction_type_;
}


bool PlayerMemento::getPassFounded() const {
    return pass_founded_;
}
