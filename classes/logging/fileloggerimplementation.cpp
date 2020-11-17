#include "classes/logging/fileloggerimplementation.h"
#include "classes/common/time.h"

void FileLoggerImplementation::log(std::ostream& stream, std::ostringstream& message) {
    stream << "[" << Time().getCurrentDateTime() << "] " << message.str();
}
