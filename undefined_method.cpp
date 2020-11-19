#include "undefined_method.h"

UndefinedMethod:: UndefinedMethod(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

char* UndefinedMethod:: send_answer(DataBase& data_base) {
    return "HTTP/1.1 405 METHOD NOT ALLOWED\n\n";
}

UndefinedMethod:: ~UndefinedMethod() {}
