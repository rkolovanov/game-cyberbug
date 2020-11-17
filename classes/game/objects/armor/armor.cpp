#include "armor.h"
#include "armorfactory.h"
#include <sstream>

Armor::Armor(int protectionValue): protectionValue_(protectionValue) {}

pObject Armor::getCopy() const {
    pArmorFactory factory(new ArmorFactory);
    return pObject(factory->createArmor(protectionValue_));
}

void Armor::executeInteraction(Creature& creature) {
    creature.setProtection(creature.getProtection() + protectionValue_);
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

std::ostream& operator<<(std::ostream& stream, const Armor& armor) {
    stream << "Object of class 'Armor': ProtectionValue(" << armor.protectionValue_ << ")\n";
    return stream;
}
