#include "POST_recurse.h"

PostR:: PostR(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

char* PostR:: send_answer(DataBase& data_base) {

}

PostR:: ~PostR() {}
