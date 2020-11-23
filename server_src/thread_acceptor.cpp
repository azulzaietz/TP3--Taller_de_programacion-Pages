#include "thread_acceptor.h"

ThreadAcceptor:: ThreadAcceptor(const Socket& s, const DataBase& data_base) {
    this->socket = s;
    this->data_base = data_base;
}

void ThreadAcceptor:: run() {
    while (keep_running) {
        Socket* peer = new Socket();
        if (peer->socket_accept(&this->socket) < 0) {
            delete peer;
            break;
        }
        clients.push_back(new ThreadClient(peer, this->data_base));
        clients.back()->start();
    }
}

void ThreadAcceptor:: stop() {
    this->keep_running = false;
    shutdown(this->socket.get_fd(), SHUT_RDWR);
    close(this->socket.get_fd());
    std::list<ThreadClient*>::iterator it;
    for (it = this->clients.begin(); 
    it != this->clients.end(); ++it) {
        (*it)->stop();
        delete (*it);
    }
}

ThreadAcceptor:: ~ThreadAcceptor(){}
