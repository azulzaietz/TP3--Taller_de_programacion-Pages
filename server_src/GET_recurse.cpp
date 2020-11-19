#include "GET_recurse.h"

GetR:: GetR(const std::string method, 
    const std::string recurse, const std::string protocol, 
    const std::string body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body; 
}

std::string GetR:: send_answer(DataBase& data_base) {
    std::string body = data_base.get(this->recurse);
    if (body != "") {
        std::string answer("HTTP/1.1 200 OK\n\n" + body);
        return answer;
    } else {
        return std::string("HTTP/1.1 404 NOT FOUND\n\n");
    }
}

GetR:: ~GetR() {}
