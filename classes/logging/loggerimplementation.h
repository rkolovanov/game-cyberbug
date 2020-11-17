#ifndef LOGGER_IMPLEMENTATION_H
#define LOGGER_IMPLEMENTATION_H

#include <sstream>


class LoggerImplementation {
public:
    virtual void log(std::ostream& stream, std::ostringstream& message) = 0;
    virtual ~LoggerImplementation() = default;
};


#endif // IOGGER_IMPLEMENTATION_H
