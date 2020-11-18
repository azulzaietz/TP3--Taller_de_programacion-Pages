#include "GET.h"

Get:: Get(std::string method, 
    std::string recurse, std::string protocol) {
        this->method = method;
        this->recurse = recurse;
        this->protocol = protocol;
}

char* Get:: send_answer(DataBase& data_base) {

}

Get:: ~Get() {}
