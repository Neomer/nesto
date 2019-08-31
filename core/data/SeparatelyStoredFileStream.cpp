//
// Created by vinokurov on 30.08.2019.
//

#include <filesystem>
#include "SeparatelyStoredFileStream.h"

using namespace std;
using namespace nesto;

SeparatelyStoredFileStream::SeparatelyStoredFileStream(std::string_view mapFileName)
{
    auto openMode = ios::out | ios::in | ios::binary | ios::ate;
    if (!filesystem::exists(mapFileName)) {
        openMode |= ios::trunc;
    }
    open(mapFileName.data(), openMode);
    if (!is_open()) {
        throw std::invalid_argument("");
    }
}

SeparatelyStoredFileStream::~SeparatelyStoredFileStream()
{
    close();
}



