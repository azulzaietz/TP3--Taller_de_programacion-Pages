#ifndef THREAD_ACCEPTOR_H
#define THREAD_ACCEPTOR_H

#include <stdio.h>
#include <string.h>
#include <list>
#include <atomic>
#include <iostream>
#include "thread.h"
#include "../common_scr/socket.h"
#include "thread_client.h"
#include "data_base.h"

class ThreadAcceptor: public Thread {
    Socket socket;
    DataBase data_base;
    std::list<ThreadClient*> clients;
    std::atomic<bool> keep_running{true};

    public:
    ThreadAcceptor(Socket& socket, DataBase& data_base);
    virtual void run() override;
    void stop();
    virtual ~ThreadAcceptor() override;
};

#endif
