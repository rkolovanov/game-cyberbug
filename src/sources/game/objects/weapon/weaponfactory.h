#ifndef SOURCES_GAME_OBJECTS_WEAPON_WEAPON_FACTORY_H
#define SOURCES_GAME_OBJECTS_WEAPON_WEAPON_FACTORY_H

#include "sources/game/objects/objectfactory.h"
#include "sources/game/objects/weapon/weapon.h"

namespace game {

using sharedWeaponFactory = std::shared_ptr<class WeaponFactory>;


class WeaponFactory final: public ObjectFactory {
public:
    virtual sharedObject createObject() override;
    virtual sharedObject createWeapon(int damage);
}; // class WeaponFactory


};

#endif // SOURCES_GAME_OBJECTS_WEAPON_WEAPON_FACTORY_H
