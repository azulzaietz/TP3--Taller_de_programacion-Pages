#include "http_processor.h"
#include <string>

HttpProcessor:: HttpProcessor() {}

void HttpProcessor:: process(std::string s) {
    this->strstream << s;
}

std::string HttpProcessor:: answer(DataBase& data_base) {
    this->data_base = data_base;
    std::string word;
    unsigned wordCount = 0;
    bool body = false;
    while (this->strstream >> word)
    {
        if (wordCount == 0) this->method = word;
        if (wordCount == 1) this->recurse = word;
        if (wordCount == 2) this->protocol = word;
        std::cout << "palabra: " << word << '\n';
        wordCount++;
    }
    this->m = find_method();
    return this->method;
}

HttpMethod* HttpProcessor:: find_method() {
    return this->selector.select_method(this->method,
        this->recurse, this->protocol);
}

HttpProcessor:: ~HttpProcessor() {}
