#include "GET.h"

Get:: Get(std::string& method, 
    std::string& recurse, std::string& protocol, std::string& body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body;
}

std::string Get:: send_answer(DataBase& data_base) {
    std::string answer(
        "HTTP/1.1 200 OK\nContent-Type: text/html\n\n" +
        data_base.get("body"));
    return answer;
}

Get:: ~Get() {}
