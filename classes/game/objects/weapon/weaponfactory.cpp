#include "weaponfactory.h"

pObject WeaponFactory::createObject() {
    return pObject(new Weapon(5));
}

pObject WeaponFactory::createWeapon(int damage) {
    return pObject(new Weapon(damage));
}
