#ifndef GET_R_H
#define GET_R_H

#include <iostream>
#include <string>
#include <list>
#include "http_method.h"

class GetR: public HttpMethod {
    private:
        std::string method;
        std::string recurse;
        std::string protocol;
    public:
        //Inicializa el tipo de instruccion
        //con sus parametros
        explicit GetR(std::string method, 
            std::string recurse, std::string protocol);
        //Devuelve el mensaje correspondiente
        virtual char* send_answer(DataBase& data_base) override;
        virtual ~GetR() override;
};

#endif