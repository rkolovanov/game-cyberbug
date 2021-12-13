#include "sources/game/objects/object.h"

namespace game {


application::EventManager& game::Object::getEventManager() {
    return event_manager_;
}


};
