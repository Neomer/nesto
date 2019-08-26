//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_STRINGSERIALIZABLE_H
#define NESTO_STRINGSERIALIZABLE_H

#include <string_view>
#include <string>

namespace nesto {

    class StringSerializable
    {
    public:
        virtual ~StringSerializable() = default;

        virtual void toString(std::string &string) const = 0;

        [[nodiscard]] std::string toString() const;

        virtual void fromString(std::string_view string) = 0;
    };

}
#endif //NESTO_STRINGSERIALIZABLE_H
