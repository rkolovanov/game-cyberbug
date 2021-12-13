#include "sources/logging/fileloggerimplementation.h"
#include "sources/application/time.h"

namespace logging {


void FileLoggerImplementation::log(std::ostream& stream, const std::ostringstream& message) {
    stream << "[" << application::Time().getCurrentDateTime() << "] " << message.str() << "\n";
}


};
