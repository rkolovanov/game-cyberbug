#include "sources/logging/consoleloggerimplementation.h"


void ConsoleLoggerImplementation::log(std::ostream& stream, const std::ostringstream& message) {
    stream << message.str() << "\n";
}
