#ifndef CONSOLE_LOGGER_IMPLEMENTATION_H
#define CONSOLE_LOGGER_IMPLEMENTATION_H

#include "classes/logging/loggerimplementation.h"


class ConsoleLoggerImplementation: public LoggerImplementation {
public:
    void log(std::ostream& stream, std::ostringstream& message);
};


#endif // CONSOLE_LOGGER_IMPLEMENTATION_H
