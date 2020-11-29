#ifndef SOURCES_COMMON_EVENT_LISTENER_H
#define SOURCES_COMMON_EVENT_LISTENER_H

#include <memory>
#include <sstream>

using sharedEventListener = std::shared_ptr<class EventListener>;


class EventListener {
public:
    virtual void update(const std::ostringstream& message) = 0;
}; // class EventListener


#endif // SOURCES_COMMON_EVENT_LISTENER_H
