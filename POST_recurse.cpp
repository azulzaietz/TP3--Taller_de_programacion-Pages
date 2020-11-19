#include "POST_recurse.h"

PostR:: PostR(std::string& method, 
    std::string& recurse, std::string& protocol,
    std::string& body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body;
}

const char* PostR:: send_answer(DataBase& data_base) {
    data_base.post(this->recurse, this->body);
    std::string answer("HTTP/1.1 200 OK\n\n" + this->body);
    return answer.c_str();
}

PostR:: ~PostR() {}
