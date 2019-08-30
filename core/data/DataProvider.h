//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_DATAPROVIDER_H
#define NESTO_DATAPROVIDER_H

#include <string_view>
#include <filesystem>
#include <future>
#include "models/IndexFile.h"

namespace nesto {

    extern Logger *log;

    class DataProvider
    {
    public:
        explicit DataProvider(std::filesystem::path rootPath, Logger &logger);

        ~DataProvider();

        std::future<void> initialize();

    private:
        void initializeRootDirectory();
        void initializeDataContainer();

        std::filesystem::path _rootPath;
        Logger &_logger;

        IndexFile *_indexFile;
    };

}

#endif //NESTO_DATAPROVIDER_H
