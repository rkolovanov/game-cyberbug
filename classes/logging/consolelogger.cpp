#include "classes/logging/consolelogger.h"
#include "classes/logging/consoleloggerimplementation.h"

ConsoleLogger::ConsoleLogger(std::ostream& stream): Logger(pLoggerImplementation(new ConsoleLoggerImplementation)), stream_(stream) {}

void ConsoleLogger::log(std::ostringstream& message) {
    implementation_->log(stream_, message);
}
