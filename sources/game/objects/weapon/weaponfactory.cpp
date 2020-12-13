#include "sources/game/objects/weapon/weaponfactory.h"

namespace game {


game::sharedObject game::WeaponFactory::createObject() {
    return std::make_shared<Weapon>(1);
}


game::sharedObject game::WeaponFactory::createWeapon(int damage) {
    return std::make_shared<Weapon>(damage);
}


};
