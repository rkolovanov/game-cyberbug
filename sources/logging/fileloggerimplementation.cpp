#include "sources/logging/fileloggerimplementation.h"
#include "sources/common/time.h"

namespace logging {


void FileLoggerImplementation::log(std::ostream& stream, const std::ostringstream& message) {
    stream << "[" << Time().getCurrentDateTime() << "] " << message.str() << "\n";
}


};
