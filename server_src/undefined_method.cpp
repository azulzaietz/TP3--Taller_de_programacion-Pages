#include "undefined_method.h"

UndefinedMethod:: UndefinedMethod(std::string method, 
    std::string recurse, std::string protocol,
    std::string body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body;
}

std::string UndefinedMethod::send_answer(DataBase& data_base) {
    return std::string("HTTP/1.1 405 METHOD NOT ALLOWED\n\n");
}

UndefinedMethod:: ~UndefinedMethod() {}
