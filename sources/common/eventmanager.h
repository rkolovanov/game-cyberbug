#ifndef SOURCES_COMMON_EVENT_MANAGER_H
#define SOURCES_COMMON_EVENT_MANAGER_H

#include <set>
#include <sstream>

#include "sources/common/eventlistener.h"


class EventManager final {
private:
    std::set<sharedEventListener> listeners_;

public:
    void subscribe(const sharedEventListener& listener);
    void unsubscribe(const sharedEventListener& listener);
    void notify(const std::ostringstream& message) const;
    void notify(const std::string& message) const;
}; // class EventManager


#endif // SOURCES_COMMON_EVENT_MANAGER_H
