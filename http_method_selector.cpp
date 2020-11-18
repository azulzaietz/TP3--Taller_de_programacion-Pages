#include "http_method_selector.h"
#include "GET_recurse.h"

HttpMethodSelector:: HttpMethodSelector() {}

HttpMethod* HttpMethodSelector:: select_method(std::string method, 
    std::string recurse, std::string protocol) {
        if (method == "GET" && recurse == "/") return new GetR(method, recurse, protocol); 
}

HttpMethodSelector:: ~HttpMethodSelector() {}
