#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "../common_src/socket.h"

#define BUF_SIZE 64

class Client {
    private:
        const char* server_host;
        const char* server_port;
        Socket* socket;
        Client &operator=(const Client& s);
        void read_command_line(int argc, char* const* argv);

    public:
        //Lee los parametros de la linea de comandos para inicializar
        //los atributos del cliente.
        //Pre: todos los parametros fueron pasados correctamente
        //Post: el cliente queda listo para ser usado y enviar mensajes.
        Client(int argc, char* const* argv);
        Client(const Client &c);

        //Devuelve true si pudo conectarse
        //al servidor, false en caso
        //de error.
        bool connect_to_server();

        //Envia el mensaje correspondiente
        //al servidor
        void send_message();

        void receive_message();

        ~Client();
};

#endif
