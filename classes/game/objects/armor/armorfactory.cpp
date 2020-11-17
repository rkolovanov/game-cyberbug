#include "armorfactory.h"

pObject ArmorFactory::createObject() {
    return pObject(new Armor(5));
}

pObject ArmorFactory::createArmor(int protectionValue) {
    return pObject(new Armor(protectionValue));
}
