#ifndef THREAD_CLIENT_H
#define THREAD_CLIENT_H

#define BUF_SIZE 64

#include <stdio.h>
#include <iostream>
#include <string>
#include "thread.h"
#include "socket.h"
#include "http_processor.h"

class ThreadClient: public Thread {
    Socket* peer;
    HttpProcessor* processor;

    public:
    ThreadClient(Socket* peer);
    virtual void run() override;
    void stop();
    virtual ~ThreadClient() override;
};

#endif
