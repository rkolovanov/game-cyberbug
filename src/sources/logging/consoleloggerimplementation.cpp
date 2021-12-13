#include "sources/logging/consoleloggerimplementation.h"

namespace logging {


void ConsoleLoggerImplementation::log(std::ostream& stream, const std::ostringstream& message) {
    stream << message.str() << "\n";
}


};
