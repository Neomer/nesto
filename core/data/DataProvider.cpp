//
// Created by kir on 26.08.2019.
//

#include "../../logs/Logger.h"
#include "DataProvider.h"

using namespace nesto;
using namespace std;

DataProvider::DataProvider(std::filesystem::path rootPath) :
    _rootPath{ rootPath }
{

}

DataProvider::~DataProvider() {

}

std::future<void> DataProvider::initialize() {
    return std::async(std::launch::async, [&]() -> void {
        initializeRootDirectory();
        initializeDataContainer();
    });
}

void DataProvider::initializeRootDirectory() {
    nesto::log.debug("check if root directory exists.");
    if (!filesystem::exists(_rootPath)) {
        nesto::log.debug("root directory is not created. Trying to create it...");
        if (!filesystem::create_directories(_rootPath)) {
            throw std::runtime_error("root directory creation failed.");
        }
        nesto::log.debug("root directory is created.");
    }
    nesto::log.debug("root directory is ready.");
}

void DataProvider::initializeDataContainer() {
    nesto::log.debug("start to initialize data container.");
    nesto::log.debug("data container is ready.");
}
