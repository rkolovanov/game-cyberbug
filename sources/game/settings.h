#ifndef SOURCES_COMMON_SETTINGS_H
#define SOURCES_COMMON_SETTINGS_H

#include <map>
#include <string>
#include <fstream>

namespace game {


class Settings final {
private:
    std::map<std::string, std::string> data_;
    bool error_ = false;

public:
    explicit Settings(const std::string& path);

    std::string& operator[](const std::string& key);

    bool isInvalid() const;
}; // class Settings


};

#endif // SOURCES_COMMON_SETTINGS_H
