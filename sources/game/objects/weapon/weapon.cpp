#include <sstream>

#include "sources/game/objects/weapon/weapon.h"
#include "sources/game/objects/weapon/weaponfactory.h"
#include "sources/game/objects/creatures/creature.h"


Weapon::Weapon(int damage): damage_(damage) {}


sharedObject Weapon::getCopy() const {
    return sharedObject(std::make_shared<WeaponFactory>()->createWeapon(damage_));
}


void Weapon::executeInteraction(Creature& creature) {
    creature.setAttackDamage(creature.getAttackDamage() + damage_);
}


const std::type_info &Weapon::getClass() const {
    return typeid(Weapon);
}


bool Weapon::getReusable() const {
    return false;
}


Weapon::~Weapon() {
    std::ostringstream ss;
    ss << "Destroying: " << *this;
    getEventManager().notify(ss);
}


std::ostream& operator<<(std::ostream& stream, const Weapon& weapon) {
    stream << "Object of class 'Weapon': Damage(" << weapon.damage_ << ")";
    return stream;
}
