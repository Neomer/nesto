//
// Created by kir on 26.08.2019.
//

#include <filesystem>
#include <iostream>
#include <fstream>
#include "Configuration.h"

using namespace nesto;
using namespace std;
using namespace std::string_literals;

Configuration::Configuration(std::string_view filename, bool saveOnDestroy) :
        _filename{ filename.data() },
        _saveOnDestroy{ saveOnDestroy }
{

}

Configuration::~Configuration()
{
    if (_saveOnDestroy) {
        save();
    }
}

void Configuration::save()
{
    ofstream stream(_filename, ios::out);
    stream << toJsonObject();
    stream.close();
}

void Configuration::reload()
{
    if (!std::filesystem::exists(_filename)) {
        throw runtime_error("configuration file not found "s + _filename);
    }

    // Reading data from file and deserialize it to the Json-object.
    ifstream stream(_filename, ios::in);
    nlohmann::json object;
    stream >> object;
    stream.close();

    fromJson(object);
}
