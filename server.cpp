#include "server.h"

//Lee los parametros pasados por linea de comandos para
//inicializar el servidor.
void Server:: read_command_line(int argc, char* const* argv) {	
    this->server_port = argv[1];
}

Server:: Server(int argc, char* const* argv) {
    read_command_line(argc, argv);
    this->socket = new Socket();
    this->data_base = new DataBase();
}

void Server:: start() {
    this->acceptor = new ThreadAcceptor(*this->socket, *this->data_base);
    acceptor->start();
}

bool Server:: ready_to_receive() {
    return this->socket->socket_bind_and_listen(NULL, this->server_port);
}

Server:: ~Server() {}
