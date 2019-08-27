//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_DATAPROVIDER_H
#define NESTO_DATAPROVIDER_H

#include <string_view>
#include <filesystem>
#include <future>

namespace nesto {

    class DataProvider
    {
    public:
        explicit DataProvider(std::filesystem::path rootPath);

        ~DataProvider();

        std::future<void> initialize();

    private:
        void initializeRootDirectory();
        void initializeDataContainer();

        std::filesystem::path _rootPath;
    };

}

#endif //NESTO_DATAPROVIDER_H
