#ifndef GET_H
#define GET_H

#include <iostream>
#include <string>
#include <list>
#include "http_method.h"

class Get: public HttpMethod {
    private:
        std::string method;
        std::string recurse;
        std::string protocol;
    public:
        //Inicializa el tipo de instruccion
        //con sus parametros
        explicit Get(std::string method, 
            std::string recurse, std::string protocol);
        //Devuelve el mensaje correspondiente
        virtual char* send_answer(DataBase& data_base) override;
        virtual ~Get() override;
};

#endif