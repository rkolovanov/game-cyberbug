#include "eventmanager.h"
#include <sstream>

void EventManager::subscribe(pEventListener& listener) {
    listeners_.insert(listener);
}

void EventManager::unsubscribe(pEventListener& listener) {
    listeners_.erase(listener);
}

void EventManager::notify(std::ostringstream& message) {
    for (auto listener : listeners_) {
        if (listener != nullptr) {
            listener->update(message);
        }
    }
}

void EventManager::notify(const std::string& message) {
    std::ostringstream ss(message);
    notify(ss);
}
