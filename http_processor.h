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
        HttpMethod* m;
        std::string method;
        std::string recurse;
        std::string protocol;
        std::stringstream body;
        bool start_body = false;
        HttpMethod* find_method();

    public:
        HttpProcessor();

        void process(std::string s);

        const char* answer(DataBase& data_base);

        ~HttpProcessor();
};

#endif
