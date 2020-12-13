#ifndef SOURCES_GAME_OBJECTS_OBJECT_H
#define SOURCES_GAME_OBJECTS_OBJECT_H

#include <memory>
#include <typeinfo>

#include "sources/gui/texture.h"
#include "sources/common/eventmanager.h"

namespace game {

using sharedObject = std::shared_ptr<class Object>;
using sharedConstObject = std::shared_ptr<const class Object>;
using sharedCreature = std::shared_ptr<class Creature>;


class Object {
private:
    EventManager event_manager_;

public:
    virtual ~Object() = default;

    EventManager& getEventManager();
    virtual sharedObject getCopy() const = 0;
    virtual const std::type_info& getClass() const = 0;
    virtual void executeInteraction(Creature& creature) = 0;
    virtual bool getReusable() const = 0;
}; // class Object


};

#endif // SOURCES_GAME_OBJECTS_OBJECT_H
