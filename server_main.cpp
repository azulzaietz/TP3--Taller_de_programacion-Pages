#include "server.h"
#include "thread_acceptor.h"

int main(int argc, char* const* argv) {
    if (argc != 3) return -1;

    Server server(argc, argv);
    if (!server.ready_to_receive()) {
        return -1;
    }

    server.start();
    std::string input;
    while (input != "q") {
        std::cin >> input;
    }

    return 0;
}