#include "POST.h"

Post:: Post(std::string& method, 
    std::string& recurse, std::string& protocol,
    std::string& body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body;
}

std::string Post:: send_answer(DataBase& data_base) {
    return std::string("HTTP/1.1 403 FORBIDDEN\n\n");
}

Post:: ~Post() {}
