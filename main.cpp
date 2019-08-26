#include <iostream>
#include "logs/Logger.h"
#include "core/config/ApplicationConfiguration.h"

using namespace nesto;

int main()
{
    ApplicationConfiguration cfg("app.config");
    nesto::log.open();

    cfg.save();
    nesto::log.close();
    return 0;
}