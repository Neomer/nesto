#include <iostream>
#include "logs/Logger.h"

int main()
{
    nesto::log.open();

    nesto::log.debug("hello");
    nesto::log.debug("world");

    auto writing_proc = [&]() -> void {
        for (auto i = 0; i < 10; ++i) {
            nesto::log.debug("from thread");
        }
    };
    std::thread thr(writing_proc);
    std::thread thr2(writing_proc);
    std::thread thr3(writing_proc);
    std::thread thr4(writing_proc);

    nesto::log.debug("end");

    nesto::log.close();
    return 0;
}