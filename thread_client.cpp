#include "thread_client.h"

ThreadClient:: ThreadClient(Socket* peer, DataBase& data_base) {
    this->peer = peer;
    this->processor = new HttpProcessor();
    this->data_base = data_base;
}

void ThreadClient:: run() {
    char buffer[BUF_SIZE];
    ssize_t bytes_received = 0;
    while ((bytes_received = peer->socket_receive(buffer, BUF_SIZE)) != 0) {
        if (bytes_received < 0) break;
        std::string str(buffer);
        this->processor->process(str, this->data_base); 
    }
    peer->socket_send(this->processor->answer().c_str(), 
        this->processor->answer().length());
    shutdown(peer->get_fd(), SHUT_WR);
}

void ThreadClient:: stop() {
    delete this->peer;
}

ThreadClient:: ~ThreadClient(){}
