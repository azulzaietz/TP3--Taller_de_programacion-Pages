#ifndef HTTP_PROCESSOR_H
#define HTTP_PROCESSOR_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "http_method.h"
#include "data_base.h"

class HttpProcessor {
    private:
        std::stringstream strstream;
        DataBase data_base;
        HttpMethod* m;
        char* method;
        char* recurse;
        char* protocol;
        HttpMethod* find_method(char* method, char* recurse, char* protocol);

    public:
        HttpProcessor();

        void process(std::string s);

        std::string answer(DataBase& data_base);

        ~HttpProcessor();
};

#endif
