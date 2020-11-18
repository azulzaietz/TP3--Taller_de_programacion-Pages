#include "POST.h"

Post:: Post(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

char* Post:: send_answer(DataBase& data_base) {

}

Post:: ~Post() {}
