//
// Created by vinokurov on 30.08.2019.
//

#ifndef NESTO_LOGPROVIDER_H
#define NESTO_LOGPROVIDER_H

#include <unordered_map>
#include "../core/config/ApplicationConfiguration.h"

namespace nesto {

    class LogProvider final {
    public:
        static LogProvider &Instance();

        void load(ApplicationConfiguration &configuration);
        void unload();

        /// Returns logger by given direction.
        /// \param direction Direction of logs' output.
        /// \throw std::invalid_argument throws if no ogger associated with given direction name.
        Logger &logger(const char *direction);

    private:
        explicit LogProvider();
        ~LogProvider();

        std::unordered_map<const char *, Logger *> _loggers;
    };

}

#endif //NESTO_LOGPROVIDER_H
