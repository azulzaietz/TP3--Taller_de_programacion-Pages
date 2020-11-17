#include "data_base.h"

DataBase:: DataBase() {}

void DataBase:: post(std::string key, std::string value) {
    this->https_data.insert({key, value});
}

std::string DataBase:: get(std::string key) {
    try {
        return this->https_data.at(key);
    } catch (std::out_of_range) {
        return "";
    }
}

DataBase:: ~DataBase() {}
