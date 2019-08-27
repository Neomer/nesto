//
// Created by kir on 26.08.2019.
//

#include "../os.h"
#include <functional>
#include <sys/types.h>
#ifdef NESTO_LINUX
#include <sys/socket.h>
#include <netinet/in.h>
#endif
#ifdef NESTO_WIN
#include <winsock2.h>
#endif
#include <unistd.h>
#include "TcpSocket.h"
#include "../logs/Logger.h"

using namespace nesto;

TcpSocket::TcpSocket() :
    _socketDescriptor{ 0 },
    _run{ true },
    _bufferSize{ 10240 },
    _buffer{ new char[_bufferSize] }
{

}

TcpSocket::TcpSocket(int socketDescriptor) :
    _socketDescriptor{ socketDescriptor },
    _run{ true },
    _readThread{ std::bind(&TcpSocket::readInternal, this) },
    _bufferSize{ 10240 },
    _buffer{ new char[_bufferSize] }
{
    _readThread.detach();
}

void TcpSocket::connect()
{
    _socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
    if(_socketDescriptor < 0)
    {
        throw std::runtime_error("Socket creation failed.");
    }
}

void TcpSocket::close()
{
    _run = false;
    ::close(_socketDescriptor);
}

size_t TcpSocket::write(const char *data, size_t size)
{
    return send(_socketDescriptor, data, size, 0);
}

size_t TcpSocket::read(char *buffer, size_t size)
{
    return recv(_socketDescriptor, buffer, size, 0);
}

void TcpSocket::readInternal()
{
    while (_run.load()) {
        auto length = recv(_socketDescriptor, _buffer, _bufferSize, 0);
        if (!length) {
            _run = false;
            break;
        }
    }
}

