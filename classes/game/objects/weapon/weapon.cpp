#include "weapon.h"
#include "weaponfactory.h"
#include <sstream>

Weapon::Weapon(int damage): damage_(damage) {}

pObject Weapon::getCopy() const {
    pWeaponFactory factory(new WeaponFactory);
    return pObject(factory->createWeapon(damage_));
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
    stream << "Object of class 'Weapon': Damage(" << weapon.damage_ << ")\n";
    return stream;
}
