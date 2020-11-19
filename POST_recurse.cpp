#include "POST_recurse.h"

PostR:: PostR(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

const char* PostR:: send_answer(DataBase& data_base) {
    data_base.post(this->recurse, this->body);
    //std::stringstream final_answer;
    //std::string answer("HTTP/1.1 200 OK\n\n");
    //final_answer << answer << this->body;
    return "HTTP/1.1 200 OK\n\n";
}

PostR:: ~PostR() {}
