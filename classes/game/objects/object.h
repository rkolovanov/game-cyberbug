#ifndef OBJECT_H
#define OBJECT_H

#include <memory>
#include <typeinfo>
#include "classes/enumerations/texture.h"
#include "classes/game/objects/creatures/creature.h"
#include "classes/common/eventmanager.h"

typedef std::shared_ptr<class Object> pObject;
typedef std::shared_ptr<const class Object> pConstObject;
typedef std::shared_ptr<class Creature> pCreature;

class Object {
private:
    EventManager eventManager_;

public:
    EventManager& getEventManager();
    virtual pObject getCopy() const = 0;
    virtual const std::type_info& getClass() const = 0;
    virtual void executeInteraction(Creature& creature) = 0;
    virtual bool getReusable() const = 0;
    virtual ~Object() = default;
};


#endif // OBJECT_H
