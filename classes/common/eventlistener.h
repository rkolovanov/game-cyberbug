#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <memory>

typedef std::shared_ptr<class EventListener> pEventListener;


class EventListener {
public:
    virtual void update(std::ostringstream& message) = 0;
};


#endif // EVENT_LISTENER_H
