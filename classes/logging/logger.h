#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <sstream>

typedef std::shared_ptr<class LoggerImplementation> pLoggerImplementation;
typedef std::shared_ptr<class Logger> pLogger;


class Logger {
protected:
    pLoggerImplementation implementation_;

public:
    Logger(const pLoggerImplementation& implementation);
    virtual void log(std::ostringstream& message) = 0;
    virtual ~Logger() = default;
};


#endif // LOGGER_H
