#include "client.h"

int main(int argc, char* const* argv) {
    if (argc != 3) return -1;
    Client client(argc, argv);
    
    if (!client.connect_to_server()) {
        return -1;
    }

    client.send_message();
    client.receive_message();
    
    return 0;
}