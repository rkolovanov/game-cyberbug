#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>


class Exception {
private:
    std::string message_;

public:
    Exception(const std::string& message);
    const std::string& getMessage() const;
};


#endif // EXCEPTION_H
