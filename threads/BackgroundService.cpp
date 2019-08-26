//
// Created by kir on 26.08.2019.
//

#include <functional>
#include "BackgroundService.h"

using namespace nesto;
using namespace std::chrono_literals;

BackgroundService::BackgroundService() :
    _run{ false }
{

}

BackgroundService::~BackgroundService()
{
    stop();
}

void BackgroundService::wakeUp()
{
    _wakeUpConditionVar.notify_one();
}

void BackgroundService::start()
{
    _run = true;
    _workThread = std::thread{ std::bind(&BackgroundService::internalProc, this) };
    _workThread.detach();
}

void BackgroundService::stop()
{
    if (_run.load()) {
        _run = false;
        wakeUp();
        if (_workThread.joinable()) {
            _workThread.join();
        }
    }
}

void BackgroundService::internalProc()
{
    std::mutex mtx;
    std::unique_lock uniq(mtx);
    while (_run.load()) {
        if (_wakeUpConditionVar.wait_for(uniq, 1s, [&]() -> bool { return wakeUpCondition(); })) {
            if (!_run.load()) {
                break;
            }
        } else {
            continue;
        }
        if (wakeUpCondition()) {
            backgroundProcess();
        }
    }
}

