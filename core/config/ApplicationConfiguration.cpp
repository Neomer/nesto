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
    object["hello"] = "world";
}

void ApplicationConfiguration::fromJson(const nlohmann::json &object)
{

}
