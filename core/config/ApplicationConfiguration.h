//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_APPLICATIONCONFIGURATION_H
#define NESTO_APPLICATIONCONFIGURATION_H

#include "Configuration.h"

namespace nesto {

class ApplicationConfiguration : public Configuration
{
public:
    explicit ApplicationConfiguration(const std::string_view &filename);

    ~ApplicationConfiguration() override = default;

private:
    void toJson(nlohmann::json &object) const override;

    void fromJson(const nlohmann::json &object) override;
};

}

#endif //NESTO_APPLICATIONCONFIGURATION_H
