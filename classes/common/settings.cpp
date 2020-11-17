#include "classes/common/settings.h"
#include "classes/common/exception.h"

Settings::Settings() {
    setDefault();
}

Settings::Settings(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        file.close();
        error_ = true;
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

void Settings::setDefault() {
    data_["console_logger"] = "true";
    data_["file_logger"] = "true";
    data_["logs_path"] = "./";
}

bool Settings::isInvalid() {
    return error_;
}

std::string& Settings::operator[](const std::string& key) {
    return data_[key];
}


