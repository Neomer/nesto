//
// Created by kir on 25.08.2019.
//

#include <iostream>
#include <chrono>
#include <functional>
#include "Logger.h"

using namespace nesto;
using namespace std::chrono_literals;
using namespace std::string_literals;

inline const char *logLevelToString(Logger::LogLevel level)
{
    switch (level)
    {
        case Logger::LogLevel::Trace: return "TRACE";
        case Logger::LogLevel::Debug: return "DEBUG";
        case Logger::LogLevel::Info: return "INFO";
        case Logger::LogLevel::Error: return "ERROR";
        case Logger::LogLevel::Warning: return "WARNING";
        default: return "UNKNOWN";
    }
}

Logger::Logger() :
    _run{ false }
{

}

Logger::~Logger()
{
    close();
}

void Logger::open()
{
    _run = true;
    _writeThread = std::thread{ std::bind(&Logger::writeProc, this) };
    _writeThread.detach();
}

void Logger::close()
{
    if (_run.load()) {
        _run = false;
        _waitMessages.notify_all();
        if (_writeThread.joinable()) {
            _writeThread.join();
        }
    }
}

void Logger::log(std::string_view message, Logger::LogLevel level)
{
    LogMessage msg;
    msg.threadId = std::this_thread::get_id();
    msg.message = message;
    msg.level = level;
    auto now = time(nullptr);
    msg.timestamp = localtime(&now);

    std::lock_guard lg(_mainQueueMtx);
    _mainQueue.push(msg);
}

void Logger::trace(std::string_view message)
{
    log(message, LogLevel::Trace);
}

void Logger::debug(std::string_view message)
{
    log(message, LogLevel::Debug);
}

void Logger::warning(std::string_view message)
{
    log(message, LogLevel::Warning);
}

void Logger::error(std::string_view message)
{
    log(message, LogLevel::Error);
}

void Logger::info(std::string_view message)
{
    log(message, LogLevel::Info);
}

void Logger::writeProc()
{
    std::mutex mtx;
    std::unique_lock uniq(mtx);
    auto pred = [&]() -> bool { return !_mainQueue.empty(); };

    while (_run.load())
    {
        if (_waitMessages.wait_for(uniq, 1s, pred)) {
            if (!_run.load()) {
                break;
            }
        }
        if (pred()) {
            std::lock_guard lg_mainQueue(_mainQueueMtx);
            _writeQueue.swap(_mainQueue);
        } else {
            continue;
        }
        while (!_writeQueue.empty()) {
            auto msg = _writeQueue.front();
            _writeQueue.pop();
            std::cout << "[" << msg.timestamp->tm_hour << ":" << msg.timestamp->tm_min << ":" << msg.timestamp->tm_sec
                << "[T:" << msg.threadId
                << " [" << logLevelToString(msg.level) << "] " << msg.message << std::endl;
            //delete msg.timestamp;
        }
    }
}
