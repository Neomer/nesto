//
// Created by vinokurov on 30.08.2019.
//

#ifndef NESTO_SEPARATELYSTOREDFILESTREAM_H
#define NESTO_SEPARATELYSTOREDFILESTREAM_H

#include <fstream>
#include <string_view>

namespace nesto {

    class SeparatelyStoredFileStream : public std::ifstream {
    public:
        SeparatelyStoredFileStream(std::string_view mapFileName);

        ~SeparatelyStoredFileStream();
    };

}


#endif //NESTO_SEPARATELYSTOREDFILESTREAM_H
