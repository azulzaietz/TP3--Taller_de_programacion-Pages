#include "server.h"

//Lee los parametros pasados por linea de comandos para
//inicializar el servidor.
void Server:: read_command_line(int argc, char* const* argv) {	
    this->server_port = argv[1];
}

Server:: Server(int argc, char* const* argv) {
    read_command_line(argc, argv);
    this->socket = new Socket();
}

void Server:: start() {
    this->acceptor = new ThreadAcceptor(*this->socket);
    acceptor->start();
}

/*
Socket* Server:: server_accept() {
    Socket* peer = new Socket();
    peer->socket_accept(this->socket);
    return peer;
}
*/

bool Server:: ready_to_receive() {
    std::cout << "por conectar" << '\n';
    return this->socket->socket_bind_and_listen(NULL, this->server_port);
}

/*
void Server:: socket_close() {
    delete this->socket;
}
*/

Server:: ~Server() {
    this->acceptor->stop();
}
