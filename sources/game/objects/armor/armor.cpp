#include <sstream>

#include "sources/game/objects/armor/armor.h"
#include "sources/game/objects/armor/armorfactory.h"
#include "sources/game/creatures/creature.h"

namespace game {


game::Armor::Armor(int protection_value): protection_value_(protection_value) {}


game::sharedObject game::Armor::getCopy() const {
    return sharedObject(std::make_shared<ArmorFactory>()->createArmor(protection_value_));
}


void game::Armor::executeInteraction(Creature& creature) {
    creature.setProtection(creature.getProtection() + protection_value_);
}


const std::type_info& game::Armor::getClass() const {
    return typeid(Armor);
}


bool game::Armor::getReusable() const {
    return false;
}


game::Armor::~Armor() {
    std::ostringstream ss;
    ss << "Destroying: " << *this;
    getEventManager().notify(ss);
}


int game::Armor::getProtection() const {
    return protection_value_;
}


std::ostream& operator<<(std::ostream& stream, const Armor& armor) {
    stream << "Object of class 'Armor': ProtectionValue(" << armor.protection_value_ << ")";
    return stream;
}


};
