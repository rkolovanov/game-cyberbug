#include "sources/game/objects/levelpassobject/levelpassobjectfactory.h"

namespace game {


game::sharedObject game::LevelPassObjectFactory::createObject() {
    return std::make_shared<LevelPassObject>();
}


std::ostream& operator<<(std::ostream& stream, const LevelPassObject&) {
    stream << "Object of class 'LevelPassObject'\n";
    return stream;
}


};
