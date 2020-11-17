#ifndef SETTINGS_H
#define SETTINGS_H

#include <fstream>
#include <map>


class Settings {
private:
    std::map<std::string, std::string> data_;
    bool error_ = false;

public:
    Settings();
    Settings(const std::string& path);
    void setDefault();
    bool isInvalid();
    std::string& operator[](const std::string& key);
};


#endif // SETTINGS_H
