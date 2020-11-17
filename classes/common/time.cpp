#include "time.h"

Time::Time() {
    timestamp_ = time(nullptr);

    if (localtime(&timestamp_)) {
        timeinfo_ = *localtime(&timestamp_);
    }
}

std::string Time::getCurrentDateTime() {
    char buffer[25];
    strftime(buffer, 25, "%d-%m-%y %H:%M:%S", &timeinfo_);
    return std::string(buffer);
}
