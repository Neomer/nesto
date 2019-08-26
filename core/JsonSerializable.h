//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_JSONSERIALIZABLE_H
#define NESTO_JSONSERIALIZABLE_H

#include "../modules/json/single_include/nlohmann/json.hpp"

namespace nesto {

    class JsonSerializable
    {
    public:
        virtual ~JsonSerializable() = default;

        virtual void toJson(nlohmann::json &object) const = 0;
        [[nodiscard]] nlohmann::json toJsonObject() const;

        virtual void fromJson(const nlohmann::json &object) = 0;
    };

}
#endif //NESTO_JSONSERIALIZABLE_H
