#include "sources/game/objects/weapon/weaponfactory.h"


sharedObject WeaponFactory::createObject() {
    return std::make_shared<Weapon>(1);
}


sharedObject WeaponFactory::createWeapon(int damage) {
    return std::make_shared<Weapon>(damage);
}
