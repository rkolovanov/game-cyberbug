#include <sstream>

#include "sources/common/eventmanager.h"


void EventManager::subscribe(const sharedEventListener& listener) {
    listeners_.insert(listener);
}


void EventManager::unsubscribe(const sharedEventListener& listener) {
    listeners_.erase(listener);
}


void EventManager::notify(const std::ostringstream& message) const {
    for (auto& listener : listeners_) {
        if (listener != nullptr) {
            listener->update(message);
        }
    }
}


void EventManager::notify(const std::string& message) const {
    notify(std::ostringstream(message));
}
