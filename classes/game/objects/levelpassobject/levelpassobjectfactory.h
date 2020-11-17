#ifndef LEVEL_PASS_OBJECT_FACTORY_H
#define LEVEL_PASS_OBJECT_FACTORY_H

#include "classes/game/objects/objectfactory.h"
#include "classes/game/objects/levelpassobject/levelpassobject.h"

typedef std::shared_ptr<class LevelPassObjectFactory> pLevelPassObjectFactory;


class LevelPassObjectFactory: public ObjectFactory {
public:
    virtual pObject createObject();
};


#endif // LEVEL_PASS_OBJECT_FACTORY_H
