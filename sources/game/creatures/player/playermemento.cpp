#include "sources/game/creatures/player/playermemento.h"

namespace game {


game::PlayerMemento::PlayerMemento(int health, int max_health, int damage, int protection, Position2D position,
                             Rotation rotation, InteractionType interaction_type, bool pass_founded)
    : health_(health), max_health_(max_health), attack_damage_(damage), protection_(protection),
      position_(position), rotation_(rotation), interaction_type_(interaction_type),
      pass_founded_(pass_founded) {}


int game::PlayerMemento::getHealth() const {
    return health_;
}


int game::PlayerMemento::getMaxHealth() const {
    return max_health_;
}


int game::PlayerMemento::getAttackDamage() const {
    return attack_damage_;
}


int game::PlayerMemento::getProtection() const {
    return protection_;
}


Position2D game::PlayerMemento::getPosition() const {
    return position_;
}


Rotation game::PlayerMemento::getRotation() const {
    return rotation_;
}


game::InteractionType game::PlayerMemento::getInteractionType() const {
    return interaction_type_;
}


bool game::PlayerMemento::getPassFounded() const {
    return pass_founded_;
}


};
