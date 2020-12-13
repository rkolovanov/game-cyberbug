#ifndef SOURCES_LOGGING_LOGGER_H
#define SOURCES_LOGGING_LOGGER_H

#include <memory>
#include <sstream>

#include "sources/logging/loggerimplementation.h"

namespace logging {

using sharedLogger = std::shared_ptr<class Logger>;


class Logger {
protected:
    sharedLoggerImplementation implementation_;

public:
    explicit Logger(const sharedLoggerImplementation& implementation);
    virtual ~Logger() = default;

    virtual void log(const std::ostringstream& message) = 0;
}; // class Logger


};

#endif // SOURCES_LOGGING_LOGGER_H
