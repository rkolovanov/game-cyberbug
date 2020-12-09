#include <sstream>

#include "sources/game/objects/armor/armor.h"
#include "sources/game/objects/armor/armorfactory.h"
#include "sources/game/objects/creatures/creature.h"


Armor::Armor(int protection_value): protection_value_(protection_value) {}


sharedObject Armor::getCopy() const {
    return sharedObject(std::make_shared<ArmorFactory>()->createArmor(protection_value_));
}


void Armor::executeInteraction(Creature& creature) {
    creature.setProtection(creature.getProtection() + protection_value_);
}


const std::type_info &Armor::getClass() const {
    return typeid(Armor);
}


bool Armor::getReusable() const {
    return false;
}


Armor::~Armor() {
    std::ostringstream ss;
    ss << "Destroying: " << *this;
    getEventManager().notify(ss);
}


int Armor::getProtection() const {
    return protection_value_;
}


std::ostream& operator<<(std::ostream& stream, const Armor& armor) {
    stream << "Object of class 'Armor': ProtectionValue(" << armor.protection_value_ << ")";
    return stream;
}
