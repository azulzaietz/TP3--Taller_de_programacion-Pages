#include "thread_acceptor.h"

ThreadAcceptor:: ThreadAcceptor(Socket& s) {
    this->socket = s;
}

void ThreadAcceptor:: run() {
    while (keep_running) {
        Socket* peer = new Socket();
        if (peer->socket_accept(&this->socket) < 0){
            break;
        }
        clients.push_back(new ThreadClient(peer));
        clients.back()->start();
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
