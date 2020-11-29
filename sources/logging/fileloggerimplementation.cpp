#include "sources/logging/fileloggerimplementation.h"
#include "sources/common/time.h"


void FileLoggerImplementation::log(std::ostream& stream, const std::ostringstream& message) {
    stream << "[" << Time().getCurrentDateTime() << "] " << message.str() << "\n";
}
