#include "sources/logging/logginglistener.h"

namespace logging {


void LoggingListener::addLogger(const sharedLogger& logger) {
    loggers_.insert(logger);
}


void LoggingListener::removeLogger(const sharedLogger& logger) {
    loggers_.erase(logger);
}


void LoggingListener::update(const std::ostringstream& message) {
    for (auto& logger : loggers_) {
        if (logger != nullptr) {
            logger->log(message);
        }
    }
}


void LoggingListener::update(const std::string &message) {
    update(std::ostringstream(message));
}


};
