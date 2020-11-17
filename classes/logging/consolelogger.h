#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include "classes/logging/logger.h"


class ConsoleLogger: public Logger {
private:
    std::ostream& stream_;

public:
    ConsoleLogger(std::ostream& stream);
    void log(std::ostringstream& message);
};


#endif // CONSOLE_LOGGER_H
