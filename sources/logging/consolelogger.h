#ifndef SOURCES_LOGGING_CONSOLE_LOGGER_H
#define SOURCES_LOGGING_CONSOLE_LOGGER_H

#include "sources/logging/logger.h"


class ConsoleLogger final: public Logger {
private:
    std::ostream& stream_;

public:
    explicit ConsoleLogger(std::ostream& stream);

    void log(const std::ostringstream& message) override;
}; // class ConsoleLogger


#endif // SOURCES_LOGGING_CONSOLE_LOGGER_H
