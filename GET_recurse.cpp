#include "GET_recurse.h"

GetR:: GetR(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

const char* GetR:: send_answer(DataBase& data_base) {
    std::stringstream final_answer;
    std::string body = data_base.get(this->recurse);
    if (body != "") {
        std::string answer("HTTP/1.1 200 OK\n\n");
        final_answer << answer << body;
        return final_answer.str().c_str();
    } else {
        return "HTTP/1.1 404 NOT FOUND\n\n";
    }
}

GetR:: ~GetR() {}
