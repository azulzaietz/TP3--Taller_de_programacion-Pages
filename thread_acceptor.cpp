#include "thread_acceptor.h"

ThreadAcceptor:: ThreadAcceptor(Socket& s) {
    this->socket = s;
}

void ThreadAcceptor:: run() {
    while (keep_running) {
        try {
            Socket* peer = new Socket();
            peer->socket_accept(&this->socket);
            clients.push_back(new ThreadClient(peer));
            clients.back()->start();
        } catch (...) {
            break;
        }
    } 
}

void ThreadAcceptor:: stop() {
    this->keep_running = false;
    delete &this->socket;
    std::list<ThreadClient*>::iterator it;
    for (it = this->clients.begin(); 
    it != this->clients.end(); ++it) {
        (*it)->stop();
    }
}

ThreadAcceptor:: ~ThreadAcceptor(){
    this->keep_running = false;
    delete &this->socket;
    std::list<ThreadClient*>::iterator it;
    for (it = this->clients.begin(); 
    it != this->clients.end(); ++it) {
        (*it)->stop();
    }
}
