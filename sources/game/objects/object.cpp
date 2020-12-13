#include "sources/game/objects/object.h"

namespace game {


EventManager& game::Object::getEventManager() {
    return event_manager_;
}


};
