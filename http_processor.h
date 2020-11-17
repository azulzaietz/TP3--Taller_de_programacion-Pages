#ifndef HTTP_PROCESSOR_H
#define HTTP_PROCESSOR_H

#include <iostream>
#include <string>
#include <sstream>
#include "http_method.h"

class HttpProcessor {
    private:
        std::stringstream strstream;
        DataBase data_base;
        HttpMethod method;

    public:
        HttpProcessor();

        void process(std::string s, DataBase& data_base);

        std::string answer();

        ~HttpProcessor();
};

#endif
