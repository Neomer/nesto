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
    object["log_dir"] = _logsFolder;
}

void ApplicationConfiguration::fromJson(const nlohmann::json &object)
{
    _networkCfg.fromJson(object["network"]);
    _rootPath = object["root"];
    _logsFolder = object["log_dir"];
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
