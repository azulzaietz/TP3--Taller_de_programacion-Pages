#ifndef POST_H
#define POST_H

#include <iostream>
#include <string>
#include <list>
#include "http_method.h"

class Post: public HttpMethod {
    private:
        std::string method;
        std::string recurse;
        std::string protocol;
        std::string body;
    public:
        //Inicializa el tipo de instruccion
        //con sus parametros
        explicit Post(const std::string& method, 
            const std::string& recurse,
            const std::string& protocol,
            const std::string& body);
        //Devuelve el mensaje correspondiente
        virtual std::string send_answer(DataBase& data_base) override;
        virtual ~Post() override;
};

#endif
