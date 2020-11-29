#ifndef SOURCES_LOGGING_FILE_LOGGER_IMPLEMENTATION_H
#define SOURCES_LOGGING_FILE_LOGGER_IMPLEMENTATION_H

#include "sources/logging/loggerimplementation.h"


class FileLoggerImplementation final: public LoggerImplementation {
public:
    void log(std::ostream& stream, const std::ostringstream& message) override;
}; // class FileLoggerImplementation


#endif // SOURCES_LOGGING_FILE_LOGGER_IMPLEMENTATION_H
