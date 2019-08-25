//
// Created by kir on 25.08.2019.
//

#ifndef NESTO_LOGGER_H
#define NESTO_LOGGER_H

#include <string_view>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <queue>

namespace nesto {

    class Logger
    {
    public:
        enum class LogLevel
        {
            Trace,
            Debug,
            Warning,
            Error,
            Info
        };

        Logger();
        virtual ~Logger();

        void open();
        void close();

        void log(std::string_view message, LogLevel level);

        void trace(std::string_view message);
        void debug(std::string_view message);
        void warning(std::string_view message);
        void error(std::string_view message);
        void info(std::string_view message);

    private:
        struct LogMessage
        {
            std::thread::id threadId;
            std::string message;
            std::tm *timestamp;
            LogLevel level;
        };
        std::mutex _mainQueueMtx;
        std::queue<LogMessage> _mainQueue, _writeQueue;
        std::condition_variable _waitMessages;
        std::thread _writeThread;
        std::atomic_bool _run;

        void writeProc();
    };

    static Logger log;

}


#endif //NESTO_LOGGER_H
