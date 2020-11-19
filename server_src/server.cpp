#include "server.h"
#include <string>

Server:: Server(int argc, char* const* argv) {
    read_command_line(argc, argv);
    this->socket = new Socket();
    this->data_base = new DataBase();
    read_html();
}

//Lee los parametros pasados por linea de comandos para
//inicializar el servidor.
void Server:: read_command_line(int argc, char* const* argv) {	
    this->server_port = argv[1];
    this->fn = argv[2];
}

void Server:: read_html() {
    std::string line;
    std::ifstream myfile(this->fn);
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            if (!line.empty()) {
                this->html_content << line;
            }
        }
        myfile.close();
    } else { 
        std::cout << "Unable to open file"; 
    }
    this->data_base->post("body", this->html_content.str());
}

void Server:: start() {
    this->acceptor = new ThreadAcceptor(*this->socket, *this->data_base);
    acceptor->start();
}

bool Server:: ready_to_receive() {
    return this->socket->socket_bind_and_listen(NULL, this->server_port);
}

Server:: ~Server() {}
