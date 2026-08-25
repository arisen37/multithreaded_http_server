#include <http_server/socket_util.h>

int socket_util::createAndBindSocket(int PORT1){

    //AF_INET -> IPV4 , SOCK_STREAM -> TCP Socket , 0 -> OS automatically selects protocol for the domain and socket type
    int serverSocket = socket(AF_INET , SOCK_STREAM , 0);

    //sockaddr_in is the class used to store serverAddress
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT1);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket , (struct sockaddr*)&serverAddress , sizeof(serverAddress));

    return serverSocket;
}

