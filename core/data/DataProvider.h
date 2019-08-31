//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_DATAPROVIDER_H
#define NESTO_DATAPROVIDER_H

#include "../../os.h"
#include <string_view>
#include <future>
#include "models/IndexFile.h"
#include "models/StoredFile.h"

namespace nesto {

    extern Logger *log;

    class DataProvider
    {
    public:
        explicit DataProvider(std::filesystem::path rootPath, Logger &logger);

        ~DataProvider();

        std::future<void> initialize();

        StoredFile &load(std::string_view name);

    private:
        void initializeRootDirectory();
        void initializeDataContainer();

        std::filesystem::path _rootPath;
        Logger &_logger;

        IndexFile *_indexFile;
    };

}

#endif //NESTO_DATAPROVIDER_H
