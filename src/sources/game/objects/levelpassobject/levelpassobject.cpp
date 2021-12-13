#include "sources/game/objects/levelpassobject/levelpassobject.h"
#include "sources/game/objects/levelpassobject/levelpassobjectfactory.h"
#include "sources/game/creatures/player/player.h"

namespace game {


game::sharedObject game::LevelPassObject::getCopy() const {
    return sharedObject(std::make_shared<LevelPassObjectFactory>()->createObject());
}


const std::type_info& game::LevelPassObject::getClass() const {
    return typeid(LevelPassObject);
}


void game::LevelPassObject::executeInteraction(Creature& creature) {
    try {
        Player& player = dynamic_cast<Player&>(creature);
        player.setPassFounded(true);
    } catch (const std::bad_cast&) {}
}


bool game::LevelPassObject::getReusable() const {
    return false;
}


game::LevelPassObject::~LevelPassObject() {
    getEventManager().notify("Destroying: Object of class 'LevelPassObject'.");
}


};
