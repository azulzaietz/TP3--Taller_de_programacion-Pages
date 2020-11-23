#include "thread_client.h"

ThreadClient:: ThreadClient(Socket* peer, const DataBase& data_base) {
    this->peer = peer;
    this->processor = new HttpProcessor();
    this->data_base = data_base;
}

void ThreadClient:: run() {
    char buffer[BUF_SIZE];
    ssize_t bytes_received = 0;

    while (keep_running){
        try {
            bytes_received = peer->socket_receive(buffer, BUF_SIZE);
            if (bytes_received < 0 || bytes_received == 0) {
                keep_running = false;
                break;
            }
            std::string str(buffer, bytes_received);
            std::lock_guard<std::mutex> lock(this->mtx);
            this->processor->process(str);
        } catch (...) {
            if (!keep_running) break;
        } 
    }
    std::string answer = this->processor->answer(this->data_base);
    peer->socket_send(answer.c_str(), answer.length());
    shutdown(peer->get_fd(), SHUT_WR);
    dead = true; 
}

void ThreadClient:: stop() {
    keep_running = false;
    delete this->peer;
}

bool ThreadClient:: is_dead() {
    return this->dead;
}

ThreadClient:: ~ThreadClient(){
    this->join();
    delete this->processor;
}
