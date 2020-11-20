#ifndef THREAD_CLIENT_H
#define THREAD_CLIENT_H

#define BUF_SIZE 64

#include <stdio.h>
#include <iostream>
#include <string>
#include <mutex>
#include "thread.h"
#include "../common_src/socket.h"
#include "http_processor.h"
#include "data_base.h"

class ThreadClient: public Thread {
    Socket* peer;
    HttpProcessor* processor;
    DataBase data_base;
    std::mutex mtx;

    public:
    ThreadClient(Socket* peer, const DataBase& data_base);
    virtual void run() override;
    void stop();
    virtual ~ThreadClient() override;
};

#endif
