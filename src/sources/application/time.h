#ifndef SOURCES_COMMON_TIME_H
#define SOURCES_COMMON_TIME_H

#include <ctime>
#include <string>

namespace application {


class Time final {
private:
    time_t timestamp_;
    tm timeinfo_;

public:
    Time();

    std::string getCurrentDateTime();
}; // class Time


};

#endif // SOURCES_COMMON_TIME_H
