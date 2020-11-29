#include "sources/game/objects/levelpassobject/levelpassobjectfactory.h"


sharedObject LevelPassObjectFactory::createObject() {
    return std::make_shared<LevelPassObject>();
}


std::ostream& operator<<(std::ostream& stream, const LevelPassObject&) {
    stream << "Object of class 'LevelPassObject'\n";
    return stream;
}
