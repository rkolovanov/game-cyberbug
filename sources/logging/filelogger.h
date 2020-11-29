#ifndef SOURCES_LOGGING_FILE_LOGGER_H
#define SOURCES_LOGGING_FILE_LOGGER_H

#include <fstream>

#include "sources/logging/logger.h"

using sharedFileLogger = std::shared_ptr<class FileLogger>;


class FileLogger final: public Logger {
private:
    std::ofstream file_;
    bool error_;

public:
    explicit FileLogger(const std::string& filepath);
    ~FileLogger();

    bool isInvalid();
    void log(const std::ostringstream& message) override;
}; // class FileLogger


#endif // SOURCES_LOGGING_FILE_LOGGER_H
