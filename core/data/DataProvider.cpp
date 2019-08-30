//
// Created by kir on 26.08.2019.
//

#include "../../logs/Logger.h"
#include "DataProvider.h"

using namespace nesto;
using namespace std;
using namespace string_literals;

DataProvider::DataProvider(std::filesystem::path rootPath, Logger &logger) :
    _rootPath{ rootPath },
    _logger{ logger },
    _indexFile{ nullptr }
{
    
}

DataProvider::~DataProvider() {

}

std::future<void> DataProvider::initialize() {
    _logger.debug("run data provider initialization task.");
    return std::async(std::launch::async, [&]() -> void {
        initializeRootDirectory();
        initializeDataContainer();
    });
}

void DataProvider::initializeRootDirectory() {
    _logger.debug("check if root directory exists.");
    if (_rootPath.empty()) {
        throw runtime_error("root directory isn't set. Check your configuration file.");
    }
    if (!filesystem::exists(_rootPath)) {
        _logger.debug("root directory is not created. Trying to create it...");
        if (!filesystem::create_directories(_rootPath)) {
            throw std::runtime_error("root directory creation failed.");
        }
        _logger.debug("root directory is created.");
    }
    _logger.debug("root directory is ready.");

    _logger.debug("loading index file.");
    auto indexPath = _rootPath / ".index";
    _indexFile = new IndexFile(indexPath, _logger);
    _logger.debug("index file ready.");

}

void DataProvider::initializeDataContainer() {
    _logger.debug("start to initialize data container.");
    _logger.debug("data container is ready.");
}
