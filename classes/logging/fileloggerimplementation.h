#ifndef FILE_LOGGER_IMPLEMENTATION_H
#define FILE_LOGGER_IMPLEMENTATION_H

#include "classes/logging/loggerimplementation.h"


class FileLoggerImplementation: public LoggerImplementation {
public:
    void log(std::ostream& stream, std::ostringstream& message);
};


#endif // FILE_LOGGER_IMPLEMENTATION_H
