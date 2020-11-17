#ifndef TIME_H
#define TIME_H

#include <ctime>
#include <string>


class Time {
private:
    time_t timestamp_;
    tm timeinfo_;

public:
    Time();
    std::string getCurrentDateTime();
};


#endif // TIME_H
