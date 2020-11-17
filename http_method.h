#ifndef HTTP_METHOD_H
#define HTTP_METHOD_H

#include <iostream>
#include <list>
#include <algorithm>
#include <string>

class HttpMethod {
    private:
        char* method;
        char* recurse;
        char* protocol;
    public:
        //Clase padre de la cual heredan todos los
        //tipos de instruccion para poder
        //aplicar polimorfismo
        HttpMethod(char* method, char* recurse, char* protocol);
        //Devuelve el mensaje correspondiente
        virtual char* send_answer();
        virtual ~HttpMethod();
};

#endif