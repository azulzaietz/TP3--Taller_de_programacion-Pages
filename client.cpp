#include "client.h"

Client:: Client(int argc, char* const* argv){
    read_command_line(argc, argv);
}

//Lee los parametros de la linea de comandos
void Client:: read_command_line(int argc, char* const* argv) {	
    this->server_host = argv[1];
    this->server_port = argv[2];
}

bool Client:: connect_to_server() {
    this->socket = new Socket();
    return this->socket->socket_connect(this->server_host, this->server_port);
}

void Client:: send_message() {
    std::string line;

    while (std::getline(std::cin, line)) {
        this->socket->socket_send(line.c_str(), line.length());
    }
    shutdown(this->socket->get_fd(), SHUT_WR); 
}

void Client:: receive_message() {
    char buffer[64];
    ssize_t bytes_received = 0;
    while ((bytes_received = this->socket->socket_receive(buffer, 64)) != 0) {
        std::cout << buffer << '\n';
    }
}

Client:: ~Client() {}
