//
// Created by vinokurov on 30.08.2019.
//

#ifndef NESTO_SEPARATELYSTOREDFILESTREAM_H
#define NESTO_SEPARATELYSTOREDFILESTREAM_H

#include <fstream>
#include <string_view>

namespace nesto {

class SeparatelyStoredFileStream : public std::fstream {
    public:
        explicit SeparatelyStoredFileStream(std::string_view mapFileName);

        ~SeparatelyStoredFileStream() override;
    };

}


#endif //NESTO_SEPARATELYSTOREDFILESTREAM_H
