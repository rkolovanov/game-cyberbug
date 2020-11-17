#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include "classes/game/objects/object.h"

typedef std::shared_ptr<class ObjectFactory> pObjectFactory;


class ObjectFactory {
public:
    virtual pObject createObject() = 0;
    virtual ~ObjectFactory() = default;
};


#endif // OBJECT_FACTORY_H
