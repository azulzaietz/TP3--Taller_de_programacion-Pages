#ifndef HTTP_PROCESSOR_H
#define HTTP_PROCESSOR_H

#include <iostream>
#include <string>
#include <sstream>

class HttpProcessor {
    private:
        std::stringstream strstream;

    public:
        HttpProcessor();

        void process(std::string s);

        std::string answer();

        ~HttpProcessor();
};

#endif
