#include "GET_recurse.h"

GetR:: GetR(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

char* GetR:: send_answer(DataBase& data_base) {

}

GetR:: ~GetR() {}
