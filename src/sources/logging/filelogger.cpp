#include "sources/logging/filelogger.h"
#include "sources/logging/fileloggerimplementation.h"

namespace logging {


FileLogger::FileLogger(const std::string& filepath)
    : Logger(std::make_shared<FileLoggerImplementation>()), error_(false) {
    file_.open(filepath);

    if (!file_.is_open()) {
        error_ = true;
    }
}


bool FileLogger::isInvalid() {
    return error_;
}


void FileLogger::log(const std::ostringstream& message) {
    if (!isInvalid()) {
        implementation_->log(file_, message);
    }
}


FileLogger::~FileLogger() {
    file_.close();
}


};
