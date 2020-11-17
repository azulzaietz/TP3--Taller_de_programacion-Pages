#include "http_processor.h"
#include <string>

HttpProcessor:: HttpProcessor() {}

void HttpProcessor:: process(std::string s) {
    this->strstream << s;
}

std::string HttpProcessor:: answer() {
    return this->strstream.str();
}

HttpProcessor:: ~HttpProcessor() {}
