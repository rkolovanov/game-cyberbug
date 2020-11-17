#ifndef LOGGINGLISTENER_H
#define LOGGINGLISTENER_H

#include <iostream>
#include <set>
#include "classes/common/eventlistener.h"
#include "classes/logging/consolelogger.h"
#include "classes/logging/filelogger.h"

typedef std::shared_ptr<class LoggingListener> pLoggingListener;


class LoggingListener: public EventListener {
private:
    std::set<pLogger> loggers_;

public:
    void addLogger(pLogger& logger);
    void removeLogger(pLogger& logger);
    void update(std::ostringstream& message);
    void update(const std::string& message);
};


#endif // LOGGINGLISTENER_H
