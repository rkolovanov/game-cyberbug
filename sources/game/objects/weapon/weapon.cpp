#include <sstream>

#include "sources/game/objects/weapon/weapon.h"
#include "sources/game/objects/weapon/weaponfactory.h"
#include "sources/game/creatures/creature.h"

namespace game {


game::Weapon::Weapon(int damage): damage_(damage) {}


game::sharedObject game::Weapon::getCopy() const {
    return sharedObject(std::make_shared<WeaponFactory>()->createWeapon(damage_));
}


void game::Weapon::executeInteraction(Creature& creature) {
    creature.setAttackDamage(creature.getAttackDamage() + damage_);
}


const std::type_info& game::Weapon::getClass() const {
    return typeid(Weapon);
}


bool game::Weapon::getReusable() const {
    return false;
}


game::Weapon::~Weapon() {
    std::ostringstream ss;
    ss << "Destroying: " << *this;
    getEventManager().notify(ss);
}


int game::Weapon::getDamage() const {
    return damage_;
}


std::ostream& operator<<(std::ostream& stream, const Weapon& weapon) {
    stream << "Object of class 'Weapon': Damage(" << weapon.damage_ << ")";
    return stream;
}


};
