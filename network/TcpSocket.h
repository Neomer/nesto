//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_TCPSOCKET_H
#define NESTO_TCPSOCKET_H

#include "../threads/BackgroundService.h"

namespace nesto {

    class TcpSocket : public BackgroundService
    {
    public:
        ~TcpSocket() override = default;

        void connect();

        void close();


    };

}


#endif //NESTO_TCPSOCKET_H
