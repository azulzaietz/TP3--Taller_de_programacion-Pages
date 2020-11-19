#include "http_method_selector.h"
#include "GET_recurse.h"
#include "POST.h"
#include "GET.h"
#include "POST_recurse.h"
#include "undefined_method.h"

HttpMethodSelector:: HttpMethodSelector() {}

HttpMethod* HttpMethodSelector:: select_method(std::string method, 
    std::string recurse, std::string protocol, std::string body) {
        if (method == "POST") {
            if (recurse.length() == 1) {
                return new Post(method, recurse, protocol, body);
            } else {
                return new PostR(method, recurse, protocol, body);
            }
        } else if (method == "GET") {
            if (recurse.length() == 1) {
                return new Get(method, recurse, protocol, body);
            } else {
                return new GetR(method, recurse, protocol, body);
            }
        } else {
            return new UndefinedMethod(method, recurse, protocol, body);
        }
}

HttpMethodSelector:: ~HttpMethodSelector() {}
