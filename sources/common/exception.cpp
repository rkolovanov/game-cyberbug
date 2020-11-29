#include "sources/common/exception.h"


Exception::Exception(const std::string& message): message_(message) {}


const std::string& Exception::getMessage() const {
    return message_;
}
