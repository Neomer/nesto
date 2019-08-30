//
// Created by vinokurov on 30.08.2019.
//

#ifndef NESTO_INDEXFILE_H
#define NESTO_INDEXFILE_H

#include <fstream>
#include <string_view>
#include <filesystem>
#include <ostream>
#include "../../../logs/Logger.h"

namespace nesto {

    class IndexFile : public std::fstream {
    public:
        struct Version
        {
            friend std::ostream &operator<<(std::ostream &os, const Version &version);
            friend std::istream &operator>>(std::istream &is, Version &version);

            uint8_t Maintance;
            uint16_t Major;
            uint16_t Minor;
        };

        explicit IndexFile(std::filesystem::path &filename, Logger &logger);
        ~IndexFile() override;

    private:
        void createIndexFile(std::filesystem::path &filename);

        Version _indexFileVersion;
        Logger &_logger;
    };

}


#endif //NESTO_INDEXFILE_H
