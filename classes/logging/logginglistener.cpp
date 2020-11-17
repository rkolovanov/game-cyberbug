#include "classes/logging/logginglistener.h"

void LoggingListener::addLogger(pLogger& logger) {
    loggers_.insert(logger);
}

void LoggingListener::removeLogger(pLogger& logger) {
    loggers_.erase(logger);
}

void LoggingListener::update(std::ostringstream& message) {
    for (auto logger : loggers_) {
        if (logger != nullptr) {
            logger->log(message);
        }
    }
}

void LoggingListener::update(const std::string &message) {
    std::ostringstream ss;
    ss << message;
    update(ss);
}
