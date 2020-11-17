#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <set>
#include "classes/common/eventlistener.h"


class EventManager {
private:
    std::set<pEventListener> listeners_;

public:
    void subscribe(pEventListener& listener);
    void unsubscribe(pEventListener& listener);
    void notify(std::ostringstream& message);
    void notify(const std::string& message);
};


#endif // EVENT_MANAGER_H
