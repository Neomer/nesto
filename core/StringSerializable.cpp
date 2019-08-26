//
// Created by kir on 26.08.2019.
//

#include "StringSerializable.h"

using namespace nesto;

std::string StringSerializable::toStringObject() const
{
    std::string ret;
    toString(ret);
    return ret;
}
