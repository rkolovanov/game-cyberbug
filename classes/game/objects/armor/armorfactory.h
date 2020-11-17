#ifndef ARMOR_FACTORY_H
#define ARMOR_FACTORY_H

#include "classes/game/objects/objectfactory.h"
#include "classes/game/objects/armor/armor.h"

typedef std::shared_ptr<class ArmorFactory> pArmorFactory;


class ArmorFactory: public ObjectFactory {
public:
    virtual pObject createObject();
    virtual pObject createArmor(int protectionValue);
};


#endif // ARMOR_FACTORY_H
