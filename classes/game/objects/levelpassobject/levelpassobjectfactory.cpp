#include "levelpassobjectfactory.h"

pObject LevelPassObjectFactory::createObject() {
    return pObject(new LevelPassObject);
}

std::ostream& operator<<(std::ostream& stream, const LevelPassObject&a) {
    stream << "Object of class 'LevelPassObject'\n";
    return stream;
}
