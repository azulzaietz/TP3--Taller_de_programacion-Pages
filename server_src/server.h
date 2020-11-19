#ifndef SERVER_H
#define SERVER_H

#include "thread_acceptor.h"
#include "../common_src/socket.h"
#include <fstream>

class Server {
    private:
        const char* server_port;
        Socket* socket;
        ThreadAcceptor* acceptor;
        DataBase* data_base;
        char* fn;
        std::stringstream html_content;

        void read_command_line(int argc, char* const* argv);

    public:
        //Inicializa un servidor con los parametros correspondientes.
        //Post: el servidor esta listo para ser usado y recibir
        //mensajes.
        Server(int argc, char* const* argv);

        //Recibe un mensaje cifrado del cliente y lo muestra 
        //descifrado por salida estándar.
        bool ready_to_receive();

        //Crea un hilo aceptador
        //para recibir conexiones de
        //multiples clientes
        void start();

        //Lee el archivo html pasado
        //como parametro y guarda su contenido
        void read_html();

        //Acepta conexiones
        //Devuelve -1 en caso de error
        //el fd correspondiente en caso
        //exitoso
        Socket* server_accept();

        //Cierra el socket en caso de 
        //que se reciba q por stdin
        void socket_close();

        ~Server();
};

#endif
