#include "logs/Logger.h"
#include "core/config/ApplicationConfiguration.h"
#include "core/data/DataProvider.h"

using namespace nesto;

int main()
{
    ApplicationConfiguration cfg("app.config");
    cfg.reload();
    nesto::log.open();

    DataProvider provider(cfg.getRootPath());
    auto initializationResult = provider.initialize();

    int key = 0;
    while (key != 'q') {
        key = getchar();
    }

    cfg.save();
    nesto::log.close();
    return 0;
}