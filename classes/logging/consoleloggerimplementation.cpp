#include "classes/logging/consoleloggerimplementation.h"

void ConsoleLoggerImplementation::log(std::ostream &stream, std::ostringstream &message) {
    stream << message.str();
}
