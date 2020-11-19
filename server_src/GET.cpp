#include "GET.h"

Get:: Get(const std::string& method, 
    const std::string& recurse,
    const std::string& protocol,
    const std::string& body) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
        this->body = body;
}

std::string Get::send_answer(DataBase& data_base) {
    std::string answer(
        "HTTP/1.1 200 OK\nContent-Type: text/html\n\n" +
        data_base.get("body"));
    return answer;
}

Get:: ~Get() {}
