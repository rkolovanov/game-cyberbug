#include "sources/common/settings.h"
#include "sources/common/exception.h"


Settings::Settings(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        error_ = true;
        file.close();
        return;
    }

    while (!file.eof()) {
        std::string line, key, value;
        std::getline(file, line);
        size_t delimiter = line.find('=');

        if (delimiter != std::string::npos) {
            key = line.substr(0, delimiter);
            value = line.substr(delimiter + 1);
            data_[key] = value;
        }
    }

    file.close();
}


bool Settings::isInvalid() const {
    return error_;
}


std::string& Settings::operator[](const std::string& key) {
    return data_[key];
}
