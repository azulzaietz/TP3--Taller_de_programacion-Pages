#include "thread_client.h"

ThreadClient:: ThreadClient(Socket* peer) {
    this->peer = peer;
}

void ThreadClient:: run() {
    char buffer[BUF_SIZE];
    ssize_t bytes_received = 0;
    try {
        while ((bytes_received = peer->socket_receive(buffer, BUF_SIZE)) != 0) {
            std::cout << "antes de fwrite servidor" << buffer << '\n';
            peer->socket_send(buffer, bytes_received);
            shutdown(peer->get_fd(), SHUT_WR);
        }
    } catch (...) {
        
    }
    
}

void ThreadClient:: stop() {
    delete this->peer;
}

ThreadClient:: ~ThreadClient(){}
