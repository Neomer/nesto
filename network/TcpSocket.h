//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_TCPSOCKET_H
#define NESTO_TCPSOCKET_H

#include <thread>
#include <mutex>
#include <vector>
#include <atomic>
#include "../threads/BackgroundService.h"

namespace nesto {

    class TcpSocket : public BackgroundService
    {
    public:
        TcpSocket();

        explicit TcpSocket(int socketDescriptor);

        ~TcpSocket() override = default;

        void connect();

        void close();

        size_t write(const char *data, size_t size);

        size_t read(char *buffer, size_t size);

    private:
        void readInternal();

        size_t _bufferSize;
        std::atomic_bool _run;
        char *_buffer;
        int _socketDescriptor;
        std::thread _readThread;

    };

}


#endif //NESTO_TCPSOCKET_H
