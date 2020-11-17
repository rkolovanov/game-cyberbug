#include "levelpassobject.h"
#include "levelpassobjectfactory.h"
#include "classes/game/objects/creatures/player/player.h"

pObject LevelPassObject::getCopy() const {
    pLevelPassObjectFactory factory(new LevelPassObjectFactory);
    return pObject(factory->createObject());
}

const std::type_info &LevelPassObject::getClass() const {
    return typeid(LevelPassObject);
}

void LevelPassObject::executeInteraction(Creature& creature) {
    try {
        Player& player = dynamic_cast<Player&>(creature);
        player.setPassFounded(true);
    } catch (const std::bad_cast&) {
        return;
    }
}

bool LevelPassObject::getReusable() const {
    return false;
}

LevelPassObject::~LevelPassObject() {
    getEventManager().notify("Destroying: Object of class 'LevelPassObject'.\n");
}
