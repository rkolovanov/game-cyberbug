#ifndef WEAPON_FACTORY_H
#define WEAPON_FACTORY_H

#include "classes/game/objects/objectfactory.h"
#include "classes/game/objects/weapon/weapon.h"

typedef std::shared_ptr<class WeaponFactory> pWeaponFactory;


class WeaponFactory: public ObjectFactory {
public:
    virtual pObject createObject();
    virtual pObject createWeapon(int damage);
};


#endif // WEAPON_FACTORY_H
