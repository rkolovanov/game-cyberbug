#include "classes/logging/filelogger.h"
#include "classes/logging/fileloggerimplementation.h"

FileLogger::FileLogger(const std::string& filepath): Logger(pLoggerImplementation(new FileLoggerImplementation)) {
    filepath_ = filepath;
    file_.open(filepath);

    if (!file_.is_open()) {
        error_ = true;
        file_.close();
    }
}

bool FileLogger::isValid() {
    return !error_;
}

void FileLogger::log(std::ostringstream& message) {
    if (!error_) {
        implementation_->log(file_, message);
    }
}

FileLogger::~FileLogger() {
    file_.close();
}
