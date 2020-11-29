#include "sources/game/objects/levelpassobject/levelpassobject.h"
#include "sources/game/objects/levelpassobject/levelpassobjectfactory.h"
#include "sources/game/objects/creatures/player/player.h"


sharedObject LevelPassObject::getCopy() const {
    return sharedObject(std::make_shared<LevelPassObjectFactory>()->createObject());
}


const std::type_info &LevelPassObject::getClass() const {
    return typeid(LevelPassObject);
}


void LevelPassObject::executeInteraction(Creature& creature) {
    try {
        Player& player = dynamic_cast<Player&>(creature);
        player.setPassFounded(true);
    } catch (const std::bad_cast&) {}
}


bool LevelPassObject::getReusable() const {
    return false;
}


LevelPassObject::~LevelPassObject() {
    getEventManager().notify("Destroying: Object of class 'LevelPassObject'.");
}
