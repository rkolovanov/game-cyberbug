#include "sources/logging/consolelogger.h"
#include "sources/logging/consoleloggerimplementation.h"


ConsoleLogger::ConsoleLogger(std::ostream& stream)
    : Logger(std::make_shared<ConsoleLoggerImplementation>()), stream_(stream) {}


void ConsoleLogger::log(const std::ostringstream& message) {
    implementation_->log(stream_, message);
}
