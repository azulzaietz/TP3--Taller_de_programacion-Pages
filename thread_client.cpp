#include "thread_client.h"

ThreadClient:: ThreadClient(Socket* peer) {
    this->peer = peer;
    this->processor = new HttpProcessor();
}

void ThreadClient:: run() {
    char buffer[4];
    ssize_t bytes_received = 0;
    while ((bytes_received = peer->socket_receive(buffer, 4)) != 0) {
        if (bytes_received < 0) break;
        std::string str(buffer);
        this->processor->process(str); 
    }
    peer->socket_send(this->processor->answer().c_str(), 
        this->processor->answer().length());
    shutdown(peer->get_fd(), SHUT_WR);
}

void ThreadClient:: stop() {
    delete this->peer;
}

ThreadClient:: ~ThreadClient(){}
