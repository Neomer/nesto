//
// Created by kir on 26.08.2019.
//

#include "ApplicationConfiguration.h"

using namespace nesto;

ApplicationConfiguration::ApplicationConfiguration(const std::string_view &filename) :
        Configuration(filename, false)
{

}

void ApplicationConfiguration::toJson(nlohmann::json &object) const
{

    object["network"] = _networkCfg.toJsonObject();
    object["root"] = _rootPath;
    object["logs"] = _logsCfg.toJsonObject();
}

void ApplicationConfiguration::fromJson(const nlohmann::json &object)
{
    _networkCfg.fromJson(object["network"]);
    _rootPath = object["root"];
    _logsCfg.fromJson(object["logs"]);
}

std::string_view ApplicationConfiguration::getRootPath() const {
    return _rootPath;
}

LogsConfiguration &ApplicationConfiguration::getLogsConfiguration() {
    return _logsCfg;
}

void NetworkConfiguration::toJson(nlohmann::json &object) const
{
    object["server"] = _serverCfg.toJsonObject();
}

void NetworkConfiguration::fromJson(const nlohmann::json &object)
{
    _serverCfg.fromJson(object["server"]);
}

void ServerConfiguration::toJson(nlohmann::json &object) const
{
    object["port"] = _port;
}

void ServerConfiguration::fromJson(const nlohmann::json &object)
{
    _port = object["port"];
}

void LogsConfiguration::toJson(nlohmann::json &object) const {
    object["folder"] = _folder;
    object["level"] = Logger::logLevelToString(_level);
}

void LogsConfiguration::fromJson(const nlohmann::json &object) {
    _folder = object["folder"];
    std::string levelName = object["level"];
    _level = Logger::logLevelFromString(levelName);
}
