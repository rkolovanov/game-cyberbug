#ifndef SOURCES_LOGGING_CONSOLE_LOGGER_IMPLEMENTATION_H
#define SOURCES_LOGGING_CONSOLE_LOGGER_IMPLEMENTATION_H

#include "sources/logging/loggerimplementation.h"


class ConsoleLoggerImplementation final: public LoggerImplementation {
public:
    void log(std::ostream& stream, const std::ostringstream& message) override;
}; // class ConsoleLoggerImplementation


#endif // SOURCES_LOGGING_CONSOLE_LOGGER_IMPLEMENTATION_H
