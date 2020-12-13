#ifndef SOURCES_GAME_OBJECTS_ARMOR_ARMOR_FACTORY_H
#define SOURCES_GAME_OBJECTS_ARMOR_ARMOR_FACTORY_H

#include "sources/game/objects/objectfactory.h"
#include "sources/game/objects/armor/armor.h"

namespace game {

using sharedArmorFactory = std::shared_ptr<class ArmorFactory>;


class ArmorFactory final: public ObjectFactory {
public:
    virtual sharedObject createObject() override;
    virtual sharedObject createArmor(int protection_value);
}; // class ArmorFactor


};

#endif // SOURCES_GAME_OBJECTS_ARMOR_ARMOR_FACTORY_H
