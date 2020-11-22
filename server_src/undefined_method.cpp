#include "undefined_method.h"

UndefinedMethod:: UndefinedMethod(const std::string& method, 
    const std::string& recurse,
    const std::string& protocol,
    const std::string& body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body;
}

std::string UndefinedMethod::send_answer(DataBase& data_base) {
    return std::string("HTTP/1.1 405 METHOD NOT ALLOWED\n\n" + 
        this->method + " es un comando desconocido");
}

UndefinedMethod:: ~UndefinedMethod() {}
