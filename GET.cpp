#include "GET.h"

Get:: Get(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

const char* Get:: send_answer(DataBase& data_base) {
    std::stringstream final_answer;
    std::string answer("HTTP/1.1 200 OK\nContent-Type: text/html\n\n");
    final_answer << answer << data_base.get("body");
    return final_answer.str().c_str();
}

Get:: ~Get() {}
