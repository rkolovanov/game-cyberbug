#ifndef SOURCES_GAME_OBJECTS_OBJECT_FACTORY_H
#define SOURCES_GAME_OBJECTS_OBJECT_FACTORY_H

#include "sources/game/objects/object.h"

namespace game {

using sharedObjectFactory = std::shared_ptr<class ObjectFactory>;


class ObjectFactory {
public:
    virtual sharedObject createObject() = 0;
    virtual ~ObjectFactory() = default;
}; // class ObjectFactory


};

#endif // SOURCES_GAME_OBJECTS_OBJECT_FACTORY_H
