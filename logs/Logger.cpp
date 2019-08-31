//
// Created by kir on 25.08.2019.
//

#include "../os.h"
#include <iostream>
#include <chrono>
#include <functional>
#ifdef NESTO_LINUX
#include <strings.h>
#define CASE_INSENSITIVE_COMPARE  strcasecmp
#else
#include <mem.h>
#define CASE_INSENSITIVE_COMPARE  stricmp
#endif
#include "Logger.h"

using namespace nesto;
using namespace std::chrono_literals;
using namespace std::string_literals;

inline const char *Logger::logLevelToString(Logger::LogLevel level)
{
    switch (level)
    {
        case Logger::LogLevel::Trace: return "TRACE";
        case Logger::LogLevel::Debug: return "DEBUG";
        case Logger::LogLevel::Info: return "INFO";
        case Logger::LogLevel::Error: return "ERROR";
        case Logger::LogLevel::Warning: return "WARNING";
        default: throw std::invalid_argument("unknown logs level value.");
    }
}

Logger::LogLevel Logger::logLevelFromString(std::string_view level) {
    if (!CASE_INSENSITIVE_COMPARE(level.data(), "trace")) {
        return LogLevel::Trace;
    } else if (!CASE_INSENSITIVE_COMPARE(level.data(), "debug")) {
        return LogLevel::Debug;
    } else if (!CASE_INSENSITIVE_COMPARE(level.data(), "info")) {
        return LogLevel::Info;
    } else if (!CASE_INSENSITIVE_COMPARE(level.data(), "error")) {
        return LogLevel::Error;
    } else if (!CASE_INSENSITIVE_COMPARE(level.data(), "warning")) {
        return LogLevel::Warning;
    } else {
        throw std::invalid_argument("unknown logs level value: "s + level.data());
    }
}

Logger::Logger() :
    BackgroundService()
{

}

Logger::~Logger()
{
    close();
}

void Logger::open()
{
    start();
}

void Logger::close()
{
    stop();
}

void Logger::log(std::string_view message, Logger::LogLevel level)
{
    LogMessage msg;
    msg.threadId = std::this_thread::get_id();
    msg.message = message;
    msg.level = level;
    auto now = time(nullptr);
    msg.timestamp = localtime(&now);

    {
        std::lock_guard lg(_mainQueueMtx);
        _mainQueue.push(msg);
    }
    wakeUp();
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

bool Logger::wakeUpCondition()
{
    return !_mainQueue.empty();
}

void Logger::backgroundProcess()
{
    {
        std::lock_guard lg_mainQueue(_mainQueueMtx);
        _writeQueue.swap(_mainQueue);
    }
    while (!_writeQueue.empty()) {
        auto msg = _writeQueue.front();
        _writeQueue.pop();
        std::cout << "[" << msg.timestamp->tm_hour << ":" << msg.timestamp->tm_min << ":" << msg.timestamp->tm_sec << "] "
                  << "[T:" << msg.threadId << "]"
                  << " [" << logLevelToString(msg.level) << "] " << msg.message << std::endl;
        //TODO: check if needed
        //delete msg.timestamp;
    }
}

