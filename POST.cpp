#include "POST.h"

Post:: Post(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

const char* Post:: send_answer(DataBase& data_base) {
    return "HTTP/1.1 403 FORBIDDEN\n\n";
}

Post:: ~Post() {}
