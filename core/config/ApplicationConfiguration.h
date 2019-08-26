//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_APPLICATIONCONFIGURATION_H
#define NESTO_APPLICATIONCONFIGURATION_H

#include "Configuration.h"

namespace nesto {

class ServerConfiguration : public JsonSerializable
{
public:
    void toJson(nlohmann::json &object) const override;

    void fromJson(const nlohmann::json &object) override;

private:
    uint16_t _port;
};

class NetworkConfiguration : public JsonSerializable
{
public:
    void toJson(nlohmann::json &object) const override;

    void fromJson(const nlohmann::json &object) override;

private:
    ServerConfiguration _serverCfg;
};

class ApplicationConfiguration : public Configuration
{
public:

    explicit ApplicationConfiguration(const std::string_view &filename);

    ~ApplicationConfiguration() override = default;

private:
    void toJson(nlohmann::json &object) const override;

    void fromJson(const nlohmann::json &object) override;

private:
    NetworkConfiguration _networkCfg;
    std::string _rootPath, _logsFolder;
};

}

#endif //NESTO_APPLICATIONCONFIGURATION_H
