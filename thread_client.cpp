#include "thread_client.h"

ThreadClient:: ThreadClient(Socket* peer) {
    this->peer = peer;
}

void ThreadClient:: run() {
    char buffer[BUF_SIZE];
    ssize_t bytes_received = 0;
    while ((bytes_received = peer->socket_receive(buffer, BUF_SIZE)) != 0) {
        if (bytes_received < 0) break;
        peer->socket_send(buffer, bytes_received);
        shutdown(peer->get_fd(), SHUT_WR);
    }
}

void ThreadClient:: stop() {
    delete this->peer;
}

ThreadClient:: ~ThreadClient(){}
