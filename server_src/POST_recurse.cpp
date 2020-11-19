#include "POST_recurse.h"

PostR:: PostR(const std::string method, 
    const std::string recurse, const std::string protocol, 
    const std::string body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body;
}

std::string PostR:: send_answer(DataBase& data_base) {
    data_base.post(this->recurse, this->body);
    std::string answer("HTTP/1.1 200 OK\n\n" + this->body);
    return answer;
}

PostR:: ~PostR() {}
