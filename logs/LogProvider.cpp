//
// Created by vinokurov on 30.08.2019.
//

#include "LogProvider.h"

using namespace nesto;
using namespace std::string_literals;

LogProvider::LogProvider() {

}

LogProvider::~LogProvider() {

}
LogProvider &LogProvider::Instance() {
    static LogProvider instance;
    return instance;
}

void LogProvider::load(ApplicationConfiguration &configuration) {
    _loggers["all"] = new Logger();

    std::for_each(_loggers.begin(), _loggers.end(), [](std::pair<const char* const, nesto::Logger*> &item) -> void {
        item.second->open();
    });
}

void LogProvider::unload() {

}

Logger &LogProvider::logger(const char *direction) {
    return *(_loggers["all"]);

    auto it = _loggers.find(direction);
    if (it == _loggers.end()) {
        throw std::invalid_argument("logger with given direction `"s + direction + "` not found.");
    }
    return *it->second;
}
