#ifndef SOURCES_COMMON_EXCEPTION_H
#define SOURCES_COMMON_EXCEPTION_H

#include <string>

namespace application {


class Exception final {
private:
    const std::string message_;

public:
    explicit Exception(const std::string& message);

    const std::string& getMessage() const;
}; // class Exception


};

#endif // SOURCES_COMMON_EXCEPTION_H
