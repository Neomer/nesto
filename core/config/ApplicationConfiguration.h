//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_APPLICATIONCONFIGURATION_H
#define NESTO_APPLICATIONCONFIGURATION_H

#include "Configuration.h"
#include "../../logs/Logger.h"

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

class LogsConfiguration : public JsonSerializable
{
public:
    void toJson(nlohmann::json &object) const override;

    void fromJson(const nlohmann::json &object) override;

private:
    std::string _folder;
    nesto::Logger::LogLevel _level;
};

class ApplicationConfiguration : public Configuration
{
public:

    explicit ApplicationConfiguration(const std::string_view &filename);

    ~ApplicationConfiguration() override = default;

    std::string_view getRootPath() const;

    LogsConfiguration &getLogsConfiguration();

private:
    void toJson(nlohmann::json &object) const override;

    void fromJson(const nlohmann::json &object) override;

private:
    NetworkConfiguration _networkCfg;
    LogsConfiguration _logsCfg;
    std::string _rootPath;
};

}

#endif //NESTO_APPLICATIONCONFIGURATION_H
