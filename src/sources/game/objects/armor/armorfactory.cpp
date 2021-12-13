#include "sources/game/objects/armor/armorfactory.h"

namespace game {


game::sharedObject game::ArmorFactory::createObject() {
    return std::make_shared<Armor>(1);
}


game::sharedObject game::ArmorFactory::createArmor(int protectionValue) {
    return std::make_shared<Armor>(protectionValue);
}


};
