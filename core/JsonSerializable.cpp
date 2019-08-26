//
// Created by kir on 26.08.2019.
//

#include "JsonSerializable.h"

using namespace nesto;

nlohmann::json JsonSerializable::toJson() const
{
    nlohmann::json ret;
    toJson(ret);
    return ret;
}
