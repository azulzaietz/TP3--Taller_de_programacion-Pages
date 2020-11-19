#include "http_processor.h"
#include <string>

HttpProcessor:: HttpProcessor() {}

void HttpProcessor:: process(std::string s) {
    this->strstream << s;
}

const char* HttpProcessor:: answer(DataBase& data_base) {
    this->data_base = data_base;
    std::string word;
    unsigned wordCount = 0;
    std::string first_line;

    while (this->strstream >> word) {
        if (wordCount == 0) this->method = word;
        if (wordCount == 1) this->recurse = word;
        if (wordCount == 2) this->protocol = word;
        if (wordCount < 3) {
            first_line += word;
            first_line += " ";
        }
        wordCount++;
        if (word == "START_BODY") {
            while (std::getline(this->strstream, word)) {
                this->body += word;
                this->body += '\n';
            }
        }
    }

    std::cout << first_line.c_str() << '\n';
    this->m = find_method();
    return this->m->send_answer(data_base);
}

HttpMethod* HttpProcessor:: find_method() {
    return this->selector.select_method(this->method,
        this->recurse, this->protocol, this->body);
}

HttpProcessor:: ~HttpProcessor() {}
