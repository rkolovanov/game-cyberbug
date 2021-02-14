#include "sources/application/time.h"

namespace application {


Time::Time() {
    timestamp_ = time(nullptr);

    if (localtime(&timestamp_) != nullptr) {
        timeinfo_ = *localtime(&timestamp_);
    }
}


std::string Time::getCurrentDateTime() {
    char buffer[20];
    strftime(buffer, 20, "%d-%m-%y %H:%M:%S", &timeinfo_);
    return std::string(buffer);
}


};
