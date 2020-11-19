#include "POST.h"

Post:: Post(const std::string method, 
    const std::string recurse, const std::string protocol, 
    const std::string body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body;
}

std::string Post::send_answer(DataBase& data_base) {
    return std::string("HTTP/1.1 403 FORBIDDEN\n\n");
}

Post:: ~Post() {}
