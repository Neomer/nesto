//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_BACKGROUNDSERVICE_H
#define NESTO_BACKGROUNDSERVICE_H

#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <atomic>

namespace nesto {

/**
 * Abstract class for any background service.
 * Class creates a new thread for a periodic-time-heavy operation and wait until thread will be awakened to execute it.
 */
    class BackgroundService
    {
    public:
        BackgroundService();

        virtual ~BackgroundService();

        void start();

        void stop();

        void wakeUp();

    protected:
        virtual bool wakeUpCondition() = 0;

        virtual void backgroundProcess() = 0;

    private:
        void internalProc();

        std::atomic_bool _run;
        std::thread _workThread;
        std::condition_variable _wakeUpConditionVar;
    };

}

#endif //NESTO_BACKGROUNDSERVICE_H
