#include "logs/LogProvider.h"
#include "core/config/ApplicationConfiguration.h"
#include "core/data/DataProvider.h"

using namespace nesto;

int main()
{

    ApplicationConfiguration cfg("app.config");
    cfg.reload();
    LogProvider::Instance().load(cfg);
    Logger &logger = LogProvider::Instance().logger("all");

    logger.debug("creating data provider.");
    DataProvider provider(cfg.getRootPath(), logger);
    auto initializationResult = provider.initialize();

    logger.debug("waiting for data provider will be ready...");
    initializationResult.get();
    logger.debug("data provider initialization is finished.");
    logger.debug("nesto is ready.");
    int key = 0;
    while (key != 'q') {
        key = getchar();
    }
    logger.debug("nest is stopping...");

    cfg.save();
    logger.close();
    return 0;
}