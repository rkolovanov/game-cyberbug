#ifndef SOURCES_LOGGING_LOGGING_LISTENER_H
#define SOURCES_LOGGING_LOGGING_LISTENER_H

#include <set>

#include "sources/common/eventlistener.h"
#include "sources/logging/consolelogger.h"
#include "sources/logging/filelogger.h"

namespace logging {

using sharedLoggingListener = std::shared_ptr<class LoggingListener>;


class LoggingListener final: public EventListener {
private:
    std::set<sharedLogger> loggers_;

public:
    void addLogger(const sharedLogger& logger);
    void removeLogger(const sharedLogger& logger);
    void update(const std::ostringstream& message) override;
    void update(const std::string& message);
}; // class LoggingListener


};

#endif // SOURCES_LOGGING_LOGGING_LISTENER_H
