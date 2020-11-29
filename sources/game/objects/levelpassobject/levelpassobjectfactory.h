#ifndef SOURCES_GAME_OBJECTS_LEVEL_PASS_OBJECT_LEVEL_PASS_OBJECT_FACTORY_H
#define SOURCES_GAME_OBJECTS_LEVEL_PASS_OBJECT_LEVEL_PASS_OBJECT_FACTORY_H

#include "sources/game/objects/objectfactory.h"
#include "sources/game/objects/levelpassobject/levelpassobject.h"

using sharedLevelPassObjectFactory = std::shared_ptr<class LevelPassObjectFactory>;


class LevelPassObjectFactory final: public ObjectFactory {
public:
    virtual sharedObject createObject() override;
}; // class LevelPassObjectFactory


#endif // SOURCES_GAME_OBJECTS_LEVEL_PASS_OBJECT_LEVEL_PASS_OBJECT_FACTORY_H
