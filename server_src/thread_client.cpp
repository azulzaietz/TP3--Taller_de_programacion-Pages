#include "thread_client.h"

ThreadClient:: ThreadClient(Socket* peer, const DataBase& data_base) {
    this->peer = peer;
    this->processor = new HttpProcessor();
    this->data_base = data_base;
}

void ThreadClient:: run() {
    try {
        char buffer[BUF_SIZE];
        ssize_t bytes_received = 0;
        while ((bytes_received = peer->socket_receive(buffer, BUF_SIZE)) != 0) {
            if (bytes_received < 0) break;
            std::string str(buffer, bytes_received);
            std::lock_guard<std::mutex> lock(this->mtx);
            this->processor->process(str);
        }
        std::string answer = this->processor->answer(this->data_base);
        peer->socket_send(answer.c_str(), 
            answer.length());
        shutdown(peer->get_fd(), SHUT_WR);
    } catch (...) {}  
}

void ThreadClient:: stop() {
    delete this->peer;
}

ThreadClient:: ~ThreadClient(){}
