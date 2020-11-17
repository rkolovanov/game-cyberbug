#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include <fstream>
#include "classes/logging/logger.h"

typedef std::shared_ptr<class FileLogger> pFileLogger;


class FileLogger: public Logger {
private:
    std::string filepath_;
    std::ofstream file_;
    bool error_ = false;

public:
    explicit FileLogger(const std::string& filepath);
    bool isValid();
    void log(std::ostringstream& message);
    ~FileLogger();
};


#endif // FILE_LOGGER_H
