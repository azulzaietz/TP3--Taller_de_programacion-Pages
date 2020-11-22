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
    return this->socket.socket_connect(this->server_host, this->server_port);
}

void Client:: send_message() {
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            std::string body("START_BODY\n");
            this->socket.socket_send(body.c_str(), body.length());
        } else {
            line += '\n';
            this->socket.socket_send(line.c_str(), line.length());
        }
    }
    shutdown(this->socket.get_fd(), SHUT_WR); 
}

void Client:: receive_message() {
    char buffer[BUF_SIZE];
    ssize_t bytes_received = 0;
    while ((bytes_received = 
        this->socket.socket_receive(buffer, BUF_SIZE)) != 0) {
        std::string str(buffer, bytes_received);
        std::cout << str.c_str();
    }
}

Client:: ~Client() {}
