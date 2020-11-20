#ifndef HTTP_PROCESSOR_H
#define HTTP_PROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "http_method.h"
#include "data_base.h"
#include "http_method_selector.h"

class HttpProcessor {
    private:
        std::stringstream strstream;
        DataBase data_base;
        HttpMethodSelector selector;
        std::string method;
        std::string recurse;
        std::string protocol;
        std::string body;
        bool start_body = false;
        HttpMethod* find_method();

    public:
        HttpProcessor();

        void process(const std::string& s);

        std::string answer(DataBase& data_base);

        ~HttpProcessor();
};

#endif
