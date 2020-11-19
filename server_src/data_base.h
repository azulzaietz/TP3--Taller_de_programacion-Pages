#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <map>

class DataBase {
    private:
        std::map <std::string, std::string> https_data;

    public:
        DataBase();
        void post(std::string key, std::string value);
        std::string get(std::string key);
        ~DataBase();
};

#endif
