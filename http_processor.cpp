#include "http_processor.h"
#include <string>

HttpProcessor:: HttpProcessor() {}

void HttpProcessor:: process(std::string s) {
    this->strstream << s;
}

std::string HttpProcessor:: answer(DataBase& data_base) {
    //this->method = find_method();
    this->data_base = data_base;
    return this->strstream.str();
}

/*
HttpMethod* HttpProcessor:: find_method(char* method, char* recurse, char* protocol) {
    return new HttpMethod();
}
*/

HttpProcessor:: ~HttpProcessor() {}
