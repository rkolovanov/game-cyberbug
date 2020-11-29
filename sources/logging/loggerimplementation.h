#ifndef SOURCES_LOGGING_LOGGER_IMPLEMENTATION_H
#define SOURCES_LOGGING_LOGGER_IMPLEMENTATION_H

#include <memory>
#include <sstream>

using sharedLoggerImplementation = std::shared_ptr<class LoggerImplementation>;


class LoggerImplementation {
public:
    virtual ~LoggerImplementation() = default;

    virtual void log(std::ostream& stream, const std::ostringstream& message) = 0;
}; // class LoggerImplementation


#endif // SOURCES_LOGGING_LOGGER_IMPLEMENTATION_H
