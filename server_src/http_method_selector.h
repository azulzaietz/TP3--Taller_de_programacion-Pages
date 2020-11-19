#ifndef HTTP_SELECTOR_H
#define HTTP_SELECTOR_H

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include "http_method.h"

class HttpMethodSelector {
    public:
        //Clase padre de la cual heredan todos los
        //tipos de instruccion para poder
        //aplicar polimorfismo
        HttpMethodSelector();
        //Devuelve el mensaje correspondiente
        HttpMethod* select_method(std::string& method, 
            std::string& recurse, std::string& protocol, std::string& body);
        virtual ~HttpMethodSelector();
};

#endif
